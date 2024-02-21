#include <stdio.h>
#include <sys/socket.h>
#include <string.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdbool.h>
#include <pthread.h>

#define CONNECT_MAX 20 				//最大连接数

//客户端地址信息
typedef struct clientinfo
{
	int confd; 						//连接成功的套接字
	struct sockaddr_in clientAddr; 	//客户端地址信息
}clientinfo, *CLIENT_INFO;

//管理人数
typedef struct clientManager
{
	//数据域
	clientinfo ClientInfo;
	//指针域
	struct clientManager* next;
}clientM,*CLIENT_M;

CLIENT_M pCliManager = NULL;
CLIENT_M find(CLIENT_M head, CLIENT_M* prev, int confd);

//创建客户端管理头结点
CLIENT_M init_client_manager()
{
	CLIENT_M p = malloc(sizeof(clientM));
	if(NULL == p)
	{
		perror("malloc CLIENT_M head failed");
		return NULL;
	}
	
	//初始化数据域
	memset(&p->ClientInfo, 0, sizeof(p->ClientInfo));
	//初始化指针域
	p->next = NULL;
	
	return p;
}

//创建客户端节点信息
CLIENT_M create_client_info(int confd, struct sockaddr_in clientAddr)
{
	CLIENT_M node = malloc(sizeof(clientM));
	if(NULL == node)
	{
		perror("malloc CLIENT_M node failed");
		return NULL;
	}
	
	//赋值数据域
	node->ClientInfo.confd = confd;
	node->ClientInfo.clientAddr = clientAddr;
	
	//初始化指针域
	node->next = NULL;
	
	return node;
}

//插入客户端节点信息
void insert_head(CLIENT_M head, CLIENT_M node)
{
	if(NULL == head || NULL == node)
	{
		perror("head is null or node is null");
		return;
	}
	
	node->next = head->next;
	head->next = node;
}

//删除客户端节点信息
void delete_node(CLIENT_M head, int confd)
{
	if(NULL == head)
	{
		perror("head is null ");
		return;
	}
	
	/*
	CLIENT_M p = head->next;
	CLIENT_M temp = head;
	while(p != NULL)
	{
		if(p->ClientInfo.confd == confd)
			break;
		
		temp = p;
		p = p->next;
	}
	
	if(p == NULL) return;
	*/
	CLIENT_M temp = malloc(sizeof(clientM));
	CLIENT_M p = find(head, &temp, confd);
	if(p == NULL) return;
	
	//找到节点
	temp->next = p->next;
	
	free(temp);
	temp = NULL;
	p->next = NULL;
	free(p);
	p = NULL;
}

CLIENT_M find(CLIENT_M head, CLIENT_M* prev, int confd)
{
	CLIENT_M p = head->next;
	CLIENT_M temp = head;
	*prev = NULL;
	while(p != NULL)
	{
		if(p->ClientInfo.confd == confd)
			break;
		
		temp = p;
		p = p->next;
	}
	
	if(p == NULL) return NULL;
	*prev = temp;
	return p;
}

//获取当前节点数量
int getClientCount(CLIENT_M head)
{
	int clientCount = 0;
	CLIENT_M p = head->next;
	while(p != NULL)
	{
		clientCount++;
		p = p->next;
	}
	
	return clientCount;
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
	CLIENT_M temp = malloc(sizeof(clientM));
	CLIENT_M p = find(pCliManager, &temp, confd);
	//聊天
	char buf[128];
	for(;;)
	{
		memset(buf, 0, sizeof(buf));
		//接收数据
		recv(confd, buf, sizeof(buf), 0); //普通接收数据
		printf("来自[%s]读取内容为:%s\n", inet_ntoa(p->ClientInfo.clientAddr.sin_addr),buf);
		if(!strcmp(buf, "quit"))
		{
			break;
		}
	}
	
	//删除节点信息
	delete_node(pCliManager, confd);
	free(temp);
	temp = NULL;
	printf("当前连接数量:%d\n", getClientCount(pCliManager));
}

int main(int argc, char* argv[])
{
	//获取服务端套接字
	int tcpsock = tcpServerSock(argv[1]);
	if(-1 == tcpsock)
		return -1;
	
	//初始化客户端
	pCliManager = init_client_manager();
	
	//循环等待获取
	int confd; //连接套接字
	
	pthread_t thread; //线程id
	struct sockaddr_in clientAddr;
	socklen_t len = sizeof(clientAddr);
	for(;;)
	{
		//等待客户端连接
		memset(&clientAddr, 0, sizeof(clientAddr));
		confd = accept(tcpsock, (struct sockaddr*)&clientAddr, &len);
		if(-1 == confd) continue;
		
		if(getClientCount(pCliManager) >= CONNECT_MAX)
		{
			close(confd);
			break;
		}
		
		//创建客户端节点信息
		CLIENT_M node = create_client_info(confd, clientAddr);
		//插入客户端节点信息
		insert_head(pCliManager, node);
		
		//线程创建
		pthread_create(&thread, NULL, fun, &confd);
	}
	
	return 0;
}