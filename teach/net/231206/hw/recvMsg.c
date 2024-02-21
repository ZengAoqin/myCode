#include <stdio.h>
#include <pthread.h>
#include <sys/socket.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>

//子线程用于发送数据
void* sendMsgs(void* arg)
{
	//获取连接客户端的套接字
	int confd = *(int *)arg;
	
	//畅聊
	char buf[128];
	for(;;)
	{
		//清空buf
		memset(buf, 0, sizeof(buf));
		printf("请输入内容\n");
		//向连接上的客户端发送消息
		fgets(buf, sizeof(buf), stdin);
		//发送数据
		send(confd, buf, strlen(buf), 0);
		//判断退出
		if(!strncmp(buf, "bye\n", 4))
			break;
	}
	
	//退出子线程
	pthread_exit(NULL);
}

//获取连接成功的套接字对象
int ConfdSock(const char* prot, int* sockfd) //port: 端口号 sockfd: 服务器的套接字
{
	//a.建立TCP连接，创建Socket文件描述符fd(sockfd)，即建立通信端点 socket
	*sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if(-1 == *sockfd)
	{
		fprintf(stderr, "line[%d] socket failed\n", __LINE__);
		return -1;
	}
	else
	{
		printf("成功申请套接字为：%d\n", *sockfd);
	}
	
	//b.绑定套接字文件描述符sockfd与网络地址和端口号，即ip地址+端口号 bind
	//初始化IP地址和端口的结构体
	struct sockaddr_in ServerAddr; 	//定义结构体对象
	memset(&ServerAddr, 0, sizeof(ServerAddr)); //清空操作
	ServerAddr.sin_family = AF_INET; //协议族
	ServerAddr.sin_port = htons(atoi(prot)); //设置端口号
	ServerAddr.sin_addr.s_addr = htonl(INADDR_ANY); //获取服务器的IP地址
	int ret = bind(*sockfd, (struct sockaddr *)&ServerAddr, sizeof(ServerAddr));
	if(-1 == ret)
	{
		fprintf(stderr, "line[%d] bind failed\n", __LINE__);
		return -1;
	}
	
	//c.设置套接字进入被动监听状态，即设置套接字的监听 listen
	listen(*sockfd, 1);
	
	//d.等待客户端连接服务器，发起连接请求 accept
	struct sockaddr_in ClientAddr; 	//定义结构体对象
	memset(&ClientAddr, 0, sizeof(ClientAddr)); //清空操作
	
	socklen_t len = sizeof(ClientAddr);
	int confd = accept(*sockfd, (struct sockaddr *)&ClientAddr, &len);
	if(-1 == confd)
	{
		fprintf(stderr, "line[%d] accept failed\n", __LINE__);
		return -1;
	}
	printf("连接成功的套接字%d\n", confd);
	
	return confd;
}

//函数用来接收数据
void recvMsgs(int confd)
{
	char buf[128];
	//畅聊
	for(;;)
	{
		//清空buf
		memset(buf, 0, sizeof(buf));
		//接收连接成功套接字的数据
		read(confd, buf, sizeof(buf));
		printf("%s", buf);
		if(!strcmp(buf, "bye\n"))
			break;
	}
}

int main(int argc, char* argv[])
{
	//获取连接成功的套接字对象
	int sockfd;
	int confd = ConfdSock(argv[1], &sockfd);
	
	//创建线程对象
	pthread_t thread;
	pthread_create(&thread, NULL, sendMsgs, &confd);
	
	//主线程用于接收数据
	recvMsgs(confd);
	
	//回收子线程资源
	pthread_join(thread, NULL);
	
	//关闭套接字描述符
	close(confd);
	close(sockfd);
	return 0;
}