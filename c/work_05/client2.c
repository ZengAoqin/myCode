#include <stdio.h>
#include <sys/socket.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>


void* func(void* arg)
{
	//a.建立TCP套接字，创建sockfd，即建立通信端点 Socket
	int sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if(-1 == sockfd)
	{
		fprintf(stderr, "line[%d] socket failed\n", __LINE__);
		pthread_exit(NULL);
	}
	else
	{
		printf("成功申请套接字为：%d\n", sockfd);
	}
	
	//b.对服务端发送请求connect，同步配置ip地址和端口
	struct sockaddr_in ServerAddr;
	memset(&ServerAddr, 0, sizeof(ServerAddr));
	ServerAddr.sin_family = AF_INET; //协议族
	ServerAddr.sin_port = htons(8090); //设置端口号
	ServerAddr.sin_addr.s_addr = htonl(INADDR_ANY); //IPV4的地址
	//启动连接服务器
	connect(sockfd, (struct sockaddr *)&ServerAddr, sizeof(ServerAddr));
	
	//c.请求连接成功，通过套接字sockfd进行数据的接收和发送 recv/send
	char buf[128];
	for(;;)
	{
		memset(buf, 0, sizeof(buf)); //清空数组
		printf("请输入发送的内容\n");
		fgets(buf, sizeof(buf), stdin);
		send(sockfd, buf, strlen(buf), 0);
		if(!strcmp(buf, "byebye\n"))
		{
			break;
		}
	}
	//d.关闭客户端对象 close
	close(sockfd);
	
	pthread_exit(NULL);
}


int main(int argc, char* argv[])
{
	//定义子线程
	pthread_t thread_id;
	int ret = pthread_create(&thread_id, NULL, func, NULL);
	if (ret)
	{
		perror("create thread1 failed");
		return -1;
	}
	
	sleep(2);
	//主进程
	//a.建立TCP连接，创建Socket文件描述符fd(sockfd)，即建立通信端点 socket
	int sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if(-1 == sockfd)
	{
		fprintf(stderr, "line[%d] socket failed\n", __LINE__);
		return -1;
	}
	else
	{
		printf("成功申请套接字为：%d\n", sockfd);
	}
	
	//b.绑定套接字文件描述符sockfd与网络地址和端口号，即ip地址+端口号 bind
	//初始化IP地址和端口的结构体
	struct sockaddr_in ServerAddr; 	//定义结构体对象
	memset(&ServerAddr, 0, sizeof(ServerAddr)); //清空操作
	ServerAddr.sin_family = AF_INET; //协议族
	ServerAddr.sin_port = htons(8080); //设置端口号
	ServerAddr.sin_addr.s_addr = htonl(INADDR_ANY); //获取本地IP地址
	ret = bind(sockfd, (struct sockaddr *)&ServerAddr, sizeof(ServerAddr));
	if(-1 == ret)
	{
		fprintf(stderr, "line[%d] bind failed\n", __LINE__);
		return -1;
	}
	
	//c.设置套接字进入被动监听状态，即设置套接字的监听 listen
	listen(sockfd, 1);
	
	//d.等待客户端连接服务器，发起连接请求 accept
	struct sockaddr_in ClientAddr; 	//定义结构体对象
	memset(&ClientAddr, 0, sizeof(ClientAddr)); //清空操作
	
	socklen_t len = sizeof(ClientAddr);
	int confd = accept(sockfd, (struct sockaddr *)&ClientAddr, &len);
	if(-1 == confd)
	{
		fprintf(stderr, "line[%d] accept failed\n", __LINE__);
		return -1;
	}
	printf("连接成功的套接字%d\n", confd);
	
	//e.收到连接请求，获取客户端的连接套接字confd，用于数据的接收和发送 recv/send
	char buf[128];
	for(;;)
	{
		memset(buf, 0, sizeof(buf)); //清空buf
		//从TCP套接字接收数据
		recv(confd, buf, sizeof(buf), 0);
		printf("[%s]客户端发送的内容为:%s", inet_ntoa(ClientAddr.sin_addr), buf);
		
		if(!strcmp(buf, "byebye\n"))
			break;
	}
	
	//f.关闭服务端对象 close
	close(sockfd);
	
	return 0;
}