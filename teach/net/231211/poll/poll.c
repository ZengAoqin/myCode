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
#include <poll.h>

#define CLIENT_MAX		20		//最多客户端连接数量
#define R_MAX			128		//最多读取字节数

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
	
	//a.创建poll 结构体数组fds[CLIENT_MAX]
	struct pollfd fds[CLIENT_MAX]; //定义集合
	unsigned int nfds = 0; 			//集合的下标
	//将对应的fd的读事件监听添加到数组的第一个元素，使用-1初始化未使用的套接字
	fds[0].fd = tcpfd; /*文件描述符*/
	fds[0].events = POLLIN; /*监听的事件集合*/
	int i = 0,j = 0;					//i用来表示不同位置的下标
	int confd = 0;						//连接成功客户端的套接字
	int ret = 0;
	char buf[R_MAX];					//读取数据
	for(i = 1; i < CLIENT_MAX; i++)
	{
		fds[i].fd = -1; //赋值为-1
	}
	nfds++;
	
	//检测数据的接收
	for(;;)
	{
		printf("准备监听\n");
		//b.进行poll函数阻塞轮询，根据返回值确定处理方式
		ret = poll(fds, nfds, 5000);
		if(-1 == ret) //失败
		{
			perror("poll failed");
			return -1;
		}
		else if(0 == ret) //超时
		{
			printf("time out...\n");
			continue;
		}
		else if(ret > 0) //成功监听到
		{
			//c.判断结果大于0之后，对文件描述符集合素组进行属性判定
			if(fds[0].revents & POLLIN)
			{
				//等待客户端的连接
				confd = accept(tcpfd, (struct sockaddr*)&addr, &len);
				if(-1 == confd) //连接失败
				{
					perror("accept failed");
					return -1;
				}
				fds[nfds].fd = confd; /*文件描述符*/
				fds[nfds].events = POLLIN; /*监听的事件集合*/
				printf("new client connect:%s\n", inet_ntoa(addr.sin_addr));
				
				nfds++; //客户端连接数量加1
			}
			
			//监听客户端的数据发送
			for(i = 1; i < nfds; i++)
			{
				//判断集合是否存在某个客户端套接字
				if(fds[i].revents & POLLIN)
				{
					//清空buf
					memset(buf, 0, sizeof(buf));
					recv(fds[i].fd, buf, sizeof(buf), 0); //普通数据接收
					printf("[%d]:%s\n", fds[i].fd, buf);
					
					//客户端要退出
					if(!strcmp("bye", buf) || !strcmp("", buf))
					{
						//关闭文件描述符
						close(fds[i].fd);
						//向前覆盖
						for(j = i; j < nfds-1; j++)
						{
							fds[j] = fds[j+1];
						}
						nfds--;
					}
				}
			}
		}
	}
	
	
	return 0;
}