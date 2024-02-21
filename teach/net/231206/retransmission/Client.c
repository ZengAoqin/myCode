#include <stdio.h>
#include <sys/socket.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

//获取连接服务端的套接字
int ConnectServerSock(const char* IP, const char* port)
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
		sockfd = -1;
		perror("连接失败");
	}
	
	return sockfd;
}

//线程接收数据
void* recvFun(void* arg)
{
	//获取连接服务端的套接字
	int sockfd = *(int*)arg;
	char buf[128];
	for(;;)
	{
		//清空buf
		memset(buf, 0, sizeof(buf)); 
		read(sockfd, buf, sizeof(buf));
		printf("%s", buf);
		if(!strcmp(buf, "byebye\n"))
			break;
	}
	
	//子线程退出
	pthread_exit(NULL);
}

int main(int argc, char* argv[]) //./main 192.168.2.101 4000
{
	//获取连接服务端的套接字
	int sockfd = ConnectServerSock(argv[1], argv[2]);
	
	//创建子线程接收数据
	pthread_t thread;
	pthread_create(&thread, NULL, recvFun, &sockfd);
	//畅聊
	char buf[128];
	int ret;
	for(;;)
	{
		memset(buf, 0, sizeof(buf)); //清空数组
		printf("请输入发送的内容\n");
		fgets(buf, sizeof(buf), stdin);
		ret = send(sockfd, buf, strlen(buf), 0);
		printf("当前发送数据为%d个字节\n", ret);
		if(!strcmp(buf, "byebye\n"))
		{
			break;
		}
	}
	
	//回收子线程资源
	pthread_join(thread, NULL);
	
	//关闭服务端套接字 close
	close(sockfd);
	return 0;
}