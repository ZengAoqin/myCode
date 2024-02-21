#include <sys/socket.h>
#include <stdio.h>
#include <arpa/inet.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>

int confd; //客户端连接套接字

//紧急信号处理函数
void fun(int sig)
{
	char buf[128];
	memset(buf, 0, sizeof(buf));
	recv(confd, buf, sizeof(buf), MSG_OOB); //接收紧急外带数据
	printf("紧急数据:%s\n", buf);
}

int main(int argc, char* argv[])
{
	//创建tcp套接字
	int tcpsock = socket(AF_INET, SOCK_STREAM, 0);
	if(-1 == tcpsock)
	{
		perror("tcp socket failed");
		return -1;
	}
	
	
	//绑定
	struct sockaddr_in r_addr; //接收端自身地址
	memset(&r_addr, 0, sizeof(r_addr));
	r_addr.sin_family = AF_INET;
	r_addr.sin_addr.s_addr = inet_addr("0.0.0.0");  //接收任意主机消息
	r_addr.sin_port = htons(atoi(argv[1]));			//端口号
	bind(tcpsock, (struct sockaddr*)&r_addr, sizeof(r_addr)); //绑定套接字
	
	//监听
	listen(tcpsock, 4);
	
	//等待客户端连接
	confd = accept(tcpsock, NULL, NULL);
	if(-1 == confd)
	{
		perror("accept failed");
		return -1;
	}
	
	//设置套接字confd的接收缓冲区下限
	socklen_t on = 10; //10个字节
	setsockopt(confd, SOL_SOCKET, SO_RCVLOWAT, &on,  sizeof(on));
	
	//设置套接字的紧急信号宿主
	fcntl(confd, F_SETOWN, getpid());
	//捕获紧急信号
	signal(SIGURG, fun); //SIGURG
	
	//聊天
	char buf[128];
	int ret;
	for(;;)
	{
		memset(buf, 0, sizeof(buf)); //清空buf
		ret = recv(confd, buf, sizeof(buf), 0); //接收普通数据
		printf("读取字节的大小:%d, 读取内容:%s\n", ret, buf);
		if(!strcmp(buf, "bye\n"))
			break;
	}
	
	//关闭套接字
	close(confd);
	close(tcpsock);
	
	return 0;
}