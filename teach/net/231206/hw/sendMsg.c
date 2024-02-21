#include <stdio.h>
#include <pthread.h>
#include <sys/socket.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>

//子线程用来接收消息
void* recvMsgs(void* arg)
{
	//获取TCP套接字
	int sockfd = *(int*)arg;
	
	//畅聊
	char buf[128];
	for(;;)
	{
		//清空buf
		memset(buf, 0, sizeof(buf));
		//接收服务器的数据
		recv(sockfd, buf, sizeof(buf), 0);
		printf("%s", buf);
		//判断退出
		if(!strcmp(buf, "bye\n"))
		{
			break;
		}
	}
	
	//退出线程
	pthread_exit(NULL);
}

//获取连接服务器的套接字
int ServerSock(const char* IP, const char* port)
{
	//a.建立TCP套接字，创建sockfd，即建立通信端点 Socket
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
	
	//b.对服务端发送请求connect，同步配置ip地址和端口
	struct sockaddr_in ServerAddr;
	memset(&ServerAddr, 0, sizeof(ServerAddr));
	ServerAddr.sin_family = AF_INET; //协议族
	ServerAddr.sin_port = htons(atoi(port)); //设置端口号
	ServerAddr.sin_addr.s_addr = inet_addr(IP); //IPV4的地址
	//启动连接服务器
	int ret = connect(sockfd, (struct sockaddr *)&ServerAddr, sizeof(ServerAddr));
	if(-1 == ret)
	{
		fprintf(stderr, "line[%d] connect failed\n", __LINE__);
		return -1;
	}
	
	return sockfd;
}

//主线程用来发送消息
void sendMsg(int sockfd)
{
	//畅聊
	char buf[128];
	for(;;)
	{
		//清空buf
		memset(buf, 0, sizeof(buf));
		fgets(buf, sizeof(buf), stdin);
		//发送数据
		send(sockfd, buf, strlen(buf), 0);
		//判断退出
		if(!strcmp(buf, "bye\n"))
		{
			break;
		}
	}
}

//主线程用来发送消息，子线程用来接收消息
int main(int argc, char* argv[]) // ./main 192.168.2.104 8080
{
	//获取连接服务器的套接字
	int sockfd = ServerSock(argv[1], argv[2]);
	
	//创建线程对象
	pthread_t thread;
	pthread_create(&thread, NULL, recvMsgs, &sockfd);
	
	//主线程用来发送消息
	sendMsg(sockfd);
	
	//回收线程资源
	pthread_join(thread, NULL);
	//关闭套接字
	close(sockfd);
	return 0;
}