#include <stdio.h>
#include <sys/socket.h>
#include <string.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdbool.h>
#include <fcntl.h>
#include <sys/select.h>

//获取服务端套接字
int tcpServerSock(const char* port)
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
	r_addr.sin_port = htons(atoi(port));			//端口号
	bind(tcpsock, (struct sockaddr*)&r_addr, sizeof(r_addr)); //绑定套接字
	
	//监听
	listen(tcpsock, 4);
	
	return tcpsock;
}

int main(int argc, char* argv[])
{
	//等待服务端套接字的获取
	int tcpfd = tcpServerSock(argv[1]);
	
	//等待客户端的连接
	struct sockaddr_in addr;	//定义结构体对象
	socklen_t len = sizeof(addr);
	int confd = accept(tcpfd, (struct sockaddr*)&addr, &len);
	if(-1 == confd)
	{
		perror("accept failed");
		return -1;
	}
	printf("当前的数据对象%d\n", confd);
	
	fd_set rset;	//读绪的集合
	//获取最大的文件描述符
	int maxfd = confd > 2 ? confd:2;
	int ret;
	//定义超时时间
	struct timeval timeout;
	//定义一个buf
	char buf[128];
	//不断的监测集合中的套接字对象
	for(;;)
	{
		//清空读就绪集合
		FD_ZERO(&rset);
		//将连接成功的套接字加入到集合
		FD_SET(confd, &rset);
		
		//设定超时时间
		timeout.tv_sec = 5; //设置时间为5秒
		//准备设置监听
		ret = select(maxfd+1, &rset, NULL, NULL, &timeout);
		
		if(0 == ret)
		{
			printf("time out\n");
		}
		else if(-1 == ret)
		{
			printf("get failed\n");
		}
		
		//检测数据是否到达
		if(FD_ISSET(confd, &rset))
		{
			//清空buf
			memset(buf, 0, sizeof(buf));
			recv(confd, buf, sizeof(buf), 0); //接收数据
			printf("来自[%s]发送:[%s]\n", inet_ntoa(addr.sin_addr), buf);
		}
		
		//退出
		if(!strcmp(buf, "quit111"))
		{
			break;
		}
	}
	
	//关闭服务端
	close(tcpfd);
	return 0;
}