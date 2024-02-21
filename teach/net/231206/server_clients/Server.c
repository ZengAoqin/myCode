#include <stdio.h>
#include <sys/socket.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

//TCP通信
typedef struct Clients
{
	int confd;						//存放连接成功的客户端的套接字
	struct sockaddr_in ClientAddr;	//存放客户端的地址数据
}Client_Info, *CLIENT_INFO;

//获取服务端的sockfd套接字
int serverSock(const char* port)
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
	ServerAddr.sin_port = htons(atoi(port)); //设置端口号
	ServerAddr.sin_addr.s_addr = htonl(INADDR_ANY); //获取服务器的IP地址
	int ret = bind(sockfd, (struct sockaddr *)&ServerAddr, sizeof(ServerAddr));
	if(-1 == ret)
	{
		fprintf(stderr, "line[%d] bind failed\n", __LINE__);
		return -1;
	}
	
	//c.设置套接字进入被动监听状态，即设置套接字的监听 listen
	ret = listen(sockfd, 10);
	if(-1 == ret)
	{
		fprintf(stderr, "line[%d] listen failed\n", __LINE__);
		return -1;
	}
	
	return sockfd;
}

//线程任务
void* recvFun(void* arg)
{
	//设置当前线程的分离属性，让系统回收资源
	pthread_detach(pthread_self());
	
	CLIENT_INFO p = (CLIENT_INFO)arg;
	
	//收到连接请求，获取客户端的连接套接字confd，用于数据的接收和发送 recv/send
	char buf[128];
	for(;;)
	{
		memset(buf, 0, sizeof(buf)); //清空buf
		//从TCP套接字接收数据
		recv(p->confd, buf, sizeof(buf), 0);
		printf("[%s]客户端发送的内容为:%s", inet_ntoa(p->ClientAddr.sin_addr), buf);
		
		if(!strcmp(buf, "byebye\n") || !strcmp(buf, ""))
			break;
	}
	
	//关闭服务端对象 close
	close(p->confd);
	printf("[%s]客户端退出连接\n", inet_ntoa(p->ClientAddr.sin_addr));
}

int main(int argc, char* argv[])
{
	//获取服务端的sockfd套接字
	int sockfd = serverSock(argv[1]);
	
	//等待不同客户端连接服务器
	struct sockaddr_in ClientAddr; 	//定义结构体对象
	memset(&ClientAddr, 0, sizeof(ClientAddr)); //清空操作
	socklen_t len = sizeof(ClientAddr);
	//客户端的套接字
	int confd;
	//定义不同客户端存储结构体数组
	Client_Info clientInfo[100];
	int i = 0; //辅助数组进行下标管理
	pthread_t thread; //线程ID
	for(;;)
	{
		confd = accept(sockfd, (struct sockaddr *)&ClientAddr, &len);
		if(-1 == confd)
		{
			perror("confd failed");
			continue; //连接失败，进入下一个客户端的连接
		}
		
		//判断是否已满
		if(i >= 100)
		{
			printf("服务器已达到连接数量上限\n");
			break;
		}
		//将连接成功的客户端保存到结构体数组中
		clientInfo[i].confd = confd; //客户端的套接字
		memcpy(&clientInfo[i].ClientAddr, &ClientAddr, sizeof(ClientAddr));
		printf("[%s]客户端连接成功\n", inet_ntoa(ClientAddr.sin_addr));
		pthread_create(&thread, NULL, recvFun, clientInfo+i);
		i++; //记录下一个
	}

	return 0;
}