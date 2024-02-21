#include <sys/socket.h>
#include <stdio.h>

#include <string.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdbool.h>
#include <fcntl.h>
#include <sys/epoll.h>
#include <errno.h>

#define R_MAX				1024			//最多读取字节数
#define MAX_EVENT_NUMBER 	10000			//最大事件数
#define RESPONESE           "server response"

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

//设置句柄非阻塞
int setnonblocking(int fd)
{
	int old_op = fcntl(fd, F_GETFL);
	int new_op = old_op | O_NONBLOCK;
	fcntl(fd, F_SETFL, new_op);
	return old_op;
}

int main(int argc, char* argv[])
{
	int tcpfd = tcpServerSock(argv[1]);
	
	//创建epoll实例
	int m_epollfd = epoll_create(5);
	if(m_epollfd == -1)
	{
		perror("epoll_create failed");
		return -1;
	}
	
	//创建节点结构体将监听连接的句柄
	struct epoll_event event;
	event.data.fd = tcpfd;
	//设置该句柄为边缘触发（数据没处理完后续不会再触发事件，水平触发式不管数据有没有触发都返回事件）
	event.events = EPOLLIN | EPOLLET | EPOLLRDHUP;
	//添加监听连接句柄作为初始节点进入红黑树结构中，该节点后续处理连接的句柄
	epoll_ctl(m_epollfd, EPOLL_CTL_ADD, tcpfd, &event);
	
	int number = 0,i = 0;
	//初始化红黑树和时间链表结构rdlist
	struct epoll_event events[MAX_EVENT_NUMBER];
	struct sockaddr_in client_addr;
	socklen_t len = sizeof(client_addr);
	int sockfd = 0,confd = 0;
	struct epoll_event cli_event;
	char buf[R_MAX];
	/*
	int epoll_wait(int epfd, struct epoll_event *events,
                      int maxevents, int timeout);
	*/
	for(;;)
	{
		number = epoll_wait(m_epollfd, events, MAX_EVENT_NUMBER, -1);
		if(number < 0 && errno != EINTR)
		{
			printf("epoll failed");
			break;
		}
		
		for(i = 0; i < number; i++)
		{
			sockfd = events[i].data.fd;
			//属于处理新到的客户端连接
			if(sockfd == tcpfd)
			{
				memset(&client_addr, 0, sizeof(client_addr));
				confd = accept(tcpfd, (struct sockaddr*)&client_addr, &len);
				if(confd < 0)
				{
					printf("errno is:%d accept error", errno);
					return -1;
				}
				memset(&cli_event, 0, sizeof(cli_event));
				cli_event.data.fd = confd;
				//设置该句柄为边缘触发（数据没处理完后续不会再触发事件，水平触发式不管数据有没有触发都返回事件）
				cli_event.events = EPOLLIN | EPOLLRDHUP;
				//添加监听连接句柄作为初始节点进入红黑树结构中，该节点后续处理连接的句柄
				epoll_ctl(m_epollfd, EPOLL_CTL_ADD, confd, &cli_event);
				setnonblocking(confd);
			}
			else if(events[i].events & (EPOLLHUP | EPOLLERR | EPOLLRDHUP))
			{
				//服务端关闭连接
				epoll_ctl(m_epollfd, EPOLL_CTL_DEL, sockfd, NULL);
				close(sockfd);
			}
			else if(events[i].events & EPOLLIN) //处理客户端端连接上收到的数据
			{
				memset(buf, 0, sizeof(buf));
				read(sockfd, buf, sizeof(buf));
				printf("client[%d]:%s\n", sockfd, buf);
				
				//将事件设置为写事件返回数据给客户端
				events[i].data.fd = sockfd;
				events[i].events = EPOLLOUT | EPOLLET | EPOLLONESHOT | EPOLLRDHUP;
				epoll_ctl(m_epollfd, EPOLL_CTL_MOD, sockfd, &events[i]);
			}
			else if(events[i].events & EPOLLOUT)
			{
				//给客户端的回应
				write(sockfd, RESPONESE, strlen(RESPONESE));
				
				//将事件设置为读事件，继续监听客户端
				events[i].data.fd = sockfd;
				events[i].events = EPOLLIN | EPOLLRDHUP;
				epoll_ctl(m_epollfd, EPOLL_CTL_MOD, sockfd, &events[i]);
			}
		}
	}
	
	return 0;
}