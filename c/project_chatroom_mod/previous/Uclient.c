#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

#define BROADCAST "192.168.2.255"
#define PORT "6666"
#define PASSWORD "123456"


char name[10];

//设置当前时间
void setTime(char* currentTime)
{
	bzero(currentTime, sizeof(currentTime));
	time_t It = time(NULL); //获取系统秒数
	struct tm *ptime = NULL; //获取时间的结构体
	ptime = localtime(&It); //将时间格式转换为结构体
	sprintf(currentTime, "%d年%d月%d日 %02d:%02d:%02d", ptime->tm_year+1900, ptime->tm_mon+1, ptime->tm_mday, \
			ptime->tm_hour, ptime->tm_min, ptime->tm_sec);
}

//发送消息
void sendMsg(int udpsock)
{
	//设置广播属性为可用
	int value = 1;
	socklen_t len = sizeof(value);
	setsockopt(udpsock, SOL_SOCKET, SO_BROADCAST, &value, len);
	
	//定义接收端的结构体
	struct sockaddr_in recvAddr;
	memset(&recvAddr, 0, sizeof(recvAddr));
	recvAddr.sin_family = AF_INET;					//协议族
	recvAddr.sin_addr.s_addr = inet_addr(BROADCAST); 	//ip地址
	recvAddr.sin_port = htons(atoi(PORT));		//端口号
	
	//sendto发送消息
	char buf[1034], msg[1024];
	for(;;)
	{
		printf("\n请输入群发消息:");

		//清空buf
		bzero(buf, sizeof(buf));
		bzero(msg, sizeof(msg));
		fgets(msg, sizeof(msg), stdin);

		//拼接用户名
		sprintf(buf, "%s %s", name, msg);

		//发送消息
		sendto(udpsock, buf, strlen(buf), 0, (struct sockaddr*)&recvAddr, sizeof(recvAddr));
		if(!strcmp(msg, "quit\n"))
		{
			break;
		}

		sleep(1);
	}
}

//接收消息线程
void* recvMsgs(void* arg)
{
	//获取udp套接字
	int udpsock = *(int*)arg;

	//创建接收端结构体
	struct sockaddr_in recvAddr;
	memset(&recvAddr, 0, sizeof(recvAddr));
	recvAddr.sin_family = AF_INET; //协议族
	recvAddr.sin_port = htons(atoi(PORT)); //端口号
	recvAddr.sin_addr.s_addr = htonl(INADDR_ANY); //IPV4的地址
	
	//绑定套接字和地址数据 bind
	int ret = bind(udpsock, (struct sockaddr*)&recvAddr, sizeof(recvAddr));
	if(-1 == ret)
	{
		perror("bind failed!!");
		pthread_exit(NULL);
	}
	
	//接收各方发送的UDP的数据报并且接收对端地址数据 recvfrom
	struct sockaddr_in sendaddr; //发送端的地址
	socklen_t len = sizeof(sendaddr);	//数据大小
	char buf[1034], msg[1024], sendName[10], currentTime[20];
	ssize_t recvSize;
	for(;;)
	{
		//清空buf
		memset(buf, 0, sizeof(buf));
		//接收数据
		recvSize = recvfrom(udpsock, buf, sizeof(buf), 0, (struct sockaddr*)&sendaddr, &len);

		//拆分用户名
		sscanf(buf, "%s %s", sendName, msg);
		if(!strcmp(msg, "quit"))
		{
			break;
		}
		
		setTime(currentTime);
		printf("\n-----时间:[%s]-----\n", currentTime);
		printf("用户：%s(%s)发送:%s\n", sendName, inet_ntoa(sendaddr.sin_addr), msg);
	}
	
	//退出线程
	pthread_exit(NULL);
}

//用户登录
void logIn()
{
	char password[15];
	printf("-------------欢迎来到UDP聊天室(quit退出)-------------\n");

	for(;;)
	{
		printf("请输入用户名：");
		scanf("%s", name);
		printf("请输入密码：");
		scanf("%s", password);
		char c = getchar(); //吃掉换行符

		if(!strcmp(password, PASSWORD))
		{
			printf("登录成功\n");
			break;
		}
		else
		{
			printf("登录失败\n");
		}
	}
}

int main(int argc, char* argv[])  //组播 224.0.0.100 广播 192.168.2.255
{
	//用户登录
	logIn();
	
	//创建udp套接字
	int udpsock = socket(AF_INET, SOCK_DGRAM, 0);
	if(-1 == udpsock)
	{
		perror("udpsock failed");
		return -1;
	}
	
	//创建线程用于接收消息
	pthread_t thread;
	pthread_create(&thread, NULL, recvMsgs, &udpsock);

	//主线程发送消息
	sendMsg(udpsock);

	//回收线程资源
	pthread_join(thread, NULL);

	//关闭套接字
	close(udpsock);

	return 0;
}