#include <stdio.h>
#include <sys/socket.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <signal.h>

int confd; //连接成功的fd

void fun(int sig)
{
	char buf[128];
	memset(buf, 0, sizeof(buf));
	//接收紧急外带数据
	recv(confd, buf, sizeof(buf), MSG_OOB);
	printf("紧急外带数据:%s\n", buf);
}

int main(int argc, char* argv[])
{
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
	ServerAddr.sin_port = htons(atoi(argv[1])); //设置端口号
	ServerAddr.sin_addr.s_addr = htonl(INADDR_ANY); //获取服务器的IP地址
	int ret = bind(sockfd, (struct sockaddr *)&ServerAddr, sizeof(ServerAddr));
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
	confd = accept(sockfd, (struct sockaddr *)&ClientAddr, &len);
	if(-1 == confd)
	{
		fprintf(stderr, "line[%d] accept failed\n", __LINE__);
		return -1;
	}
	printf("连接成功的套接字%d\n", confd);
	
	//设置连接对象的描述信号SIGIO或者SIGURG
	//给进程设置为信号宿主
	fcntl(confd, F_SETOWN, getpid());
	signal(SIGURG, fun);
	
	//e.收到连接请求，获取客户端的连接套接字confd，用于数据的接收和发送 recv/send
	char buf[128];
	for(;;)
	{
		memset(buf, 0, sizeof(buf)); //清空buf
		read(confd, buf, sizeof(buf)); //接收连接成功套接字的数据
		printf("[%s]客户端发送的内容为:%s", inet_ntoa(ClientAddr.sin_addr), buf);
		
		if(!strcmp(buf, "byebye\n"))
			break;
	}
	
	//f.关闭服务端对象 close
	close(sockfd);
	return 0;
}