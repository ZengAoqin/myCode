#include <stdio.h>
#include <sys/socket.h>
#include <string.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdbool.h>
#include <pthread.h>

//管理人数
typedef struct client
{
	int clifd[20];		//20个客户端存储对象空间
	int count;			//连接成功的个数
}client, *CLIENT;

//初始化管理客户端数量
void init_client(CLIENT pClient)
{
	int i;
	//清空数组当前的连接对象
	for(i = 0; i < 20; i++)
	{
		pClient->clifd[i] = -1; //初始值
	}
	//初始连接成功个数为0
	pClient->count = 0;
}

//添加客户端
bool add_client(CLIENT pClient, int confd)
{
	//判断连接客户端数量是否已满
	if(pClient->count >= 20)
	{
		printf("当前客户端连接数量已达上限，请排队...\n");
		return false;
	}
	
	//客户端数量不满
	pClient->clifd[pClient->count++] = confd;
	return true;
}

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

//读取数据
void* fun(void* arg)
{
	//设置分离属性，系统回收
	pthread_detach(pthread_self());
	int confd = *(int*)arg;
	//聊天
	char buf[128];
	for(;;)
	{
		memset(buf, 0, sizeof(buf));
		//接收数据
		recv(confd, buf, sizeof(buf), 0); //普通接收数据
		printf("读取内容为:%s\n", buf);
		
		
		if(!strcmp(buf, "quit"))
		{
			break;
		}
	}
}

int main(int argc, char* argv[])
{
	//获取服务端套接字
	int tcpsock = tcpServerSock(argv[1]);
	if(-1 == tcpsock)
		return -1;
	
	//初始化客户端
	CLIENT pClient = malloc(sizeof(client)); 
	if(NULL == pClient)
	{
		perror("malloc failed");
		return -1;
	}
	init_client(pClient);
	
	//循环等待获取
	int confd; //连接套接字
	pthread_t thread; //线程id
	for(;;)
	{
		//等待客户端连接
		confd = accept(tcpsock, NULL, NULL);
		if(-1 == confd) continue;
		
		if(!add_client(pClient, confd))
		{
			close(confd);
			break;
		}
		//线程创建
		pthread_create(&thread, NULL, fun, &pClient->clifd[pClient->count - 1]);
	}
	
	return 0;
}