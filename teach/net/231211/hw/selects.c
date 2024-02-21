#include <sys/socket.h>
#include <stdio.h>

#include <string.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdbool.h>
#include <fcntl.h>
#include <sys/select.h>

/*
练习：使用多路复用select 设置20个人连接服务端，实时接收客户端发送的所有消息，多路复用的模型优先，
可以同时处理多个文件描述符，不需要开启线程
思路：当select函数的返回值>0，表示套接字有数据，加入到客户端结构体
并且循环遍历读取每个客户端对象，获取客户端的数据[可参考非阻塞io读取方式]
若数组存储，尝试使用j+1为套接字赋值给j位，将退出套接字覆盖
*/

#define CLIENT_MAX		20		//最多客户端连接数量
#define R_MAX			128		//最多读取字节数

//客户端的基础信息结构体
typedef struct client
{
	int confd;					//连接成功的客户端的套接字
	struct sockaddr_in addr;	//记录客户端的地址信息
	int count;					//记录客户端的个数
}client, *CLIENT;

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
	//获取服务端的套接字
	int tcpfd = tcpServerSock(argv[1]);
	
	//设置初始数据
	struct sockaddr_in addr;			//定义地址的结构体对象
	socklen_t len = sizeof(addr);		//地址长度
	int maxfd = tcpfd;					//用来保存存在最大的文件描述符
	fd_set rsets;						//读文件数据的集合
	struct timeval timeout;				//超时时间的结构体
	int i = 0,j = 0;					//i用来表示不同位置的下标
	client clients[CLIENT_MAX];			//客户端连接的数量
	char buf[R_MAX];					//读取数据
	int confd = 0, cliCounts = 0;		//连接成功客户端的套接字
	int ret = 0;
	//准备检测数据
	for(;;)
	{
		//清空文件集合
		FD_ZERO(&rsets);
		FD_SET(tcpfd, &rsets);	//将套接字加入到集合
		//将客户端的连接套接字加入到文件集合
		for(i = 0; i < cliCounts; i++)
		{
			FD_SET(clients[i].confd, &rsets);
		}
		
		//设定超时时间
		timeout.tv_sec = 5;	//超时时长为5秒
		printf("准备监听\n");
		//监听文件描述符
		ret = select(maxfd+1, &rsets, NULL, NULL, &timeout);
		if(-1 == ret) //失败
		{
			perror("select failed");
			return -1;
		}
		else if(0 == ret) //超时
		{
			printf("time out...\n");
			continue;
		}
		else if(ret > 0) //成功监听到
		{
			//判断tcpfd是否存在于集合
			if(FD_ISSET(tcpfd, &rsets))
			{
				//等待客户端的连接
				confd = accept(tcpfd, (struct sockaddr*)&addr, &len);
				if(-1 == confd) //连接失败
				{
					perror("accept failed");
					return -1;
				}
				clients[cliCounts].confd = confd;
				clients[cliCounts].addr = addr;
				clients[cliCounts].count = cliCounts;
				printf("new client connect:%s\n", inet_ntoa(addr.sin_addr));
				//确定最大新的文件描述符
				if(maxfd < confd)
					maxfd = confd;	
				cliCounts++; //客户端连接数量加1
			}
			
			//监听客户端的数据发送
			for(i = 0; i < cliCounts; i++)
			{
				//判断集合是否存在某个客户端套接字
				if(FD_ISSET(clients[i].confd, &rsets))
				{
					//清空buf
					memset(buf, 0, sizeof(buf));
					recv(clients[i].confd, buf, sizeof(buf), 0); //普通数据接收
					printf("[%s][%d]:%s", inet_ntoa(clients[i].addr.sin_addr), clients[i].confd, buf);
					
					//客户端要退出
					if(!strcmp("bye", buf) || !strcmp("", buf))
					{
						//关闭文件描述符
						close(clients[i].confd);
						//向前覆盖
						for(j = i; j < cliCounts-1; j++)
						{
							clients[j] = clients[j+1];
						}
						cliCounts--;
					}
				}
			}
		}
	}
	
	
	return 0;
}