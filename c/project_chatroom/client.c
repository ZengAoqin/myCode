#include <stdio.h>
#include <pthread.h>
#include <sys/socket.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <netinet/in.h>
#include <time.h>

#define SERVERIP "192.168.2.103"
#define PORT "6666"
#define PASSWORD "123456"


char name[10];

//获取当前时间
void getTime(char* currentTime)
{
	bzero(currentTime, sizeof(currentTime));
	time_t It = time(NULL); //获取系统秒数
	struct tm *ptime = NULL; //获取时间的结构体
	ptime = localtime(&It); //将时间格式转换为结构体
	sprintf(currentTime, "%d-%d-%d %02d:%02d:%02d", ptime->tm_year+1900, ptime->tm_mon+1, ptime->tm_mday, \
			ptime->tm_hour, ptime->tm_min, ptime->tm_sec);
}

//获取连接服务器的套接字
int ServerSock(const char* IP, const char* port)
{
	//a.建立TCP套接字，创建sockfd，即建立通信端点 Socket
	int sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if(-1 == sockfd)
	{
		fprintf(stderr, "line[%d] socket failed\n", __LINE__);
		return -1;
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
		fprintf(stderr, "line[%d] connect failed\n", __LINE__);
		return -1;
	}
	
	return sockfd;
}

//发送消息
void sendMsg(int sockfd)
{
	char buf[138], msg[128];
	for(;;)
	{
		printf("\n用户：%s 请输入群发消息:", name);
		
		//清空buf
		memset(buf, 0, sizeof(buf));
		memset(msg, 0, sizeof(msg));
		fgets(msg, sizeof(msg), stdin);
		// 去掉末尾的换行符
    	msg[strcspn(msg, "\n")] = '\0';
		
		//拼接用户名到buf
		sprintf(buf, "%s::%s", name, msg);
		
		//发送数据
		send(sockfd, buf, strlen(buf), 0);
		if(!strcmp(msg, "quit"))
		{
			break;
		}
		
		sleep(1);
	}
}

//子线程用来接收消息
void* recvMsgs(void* arg)
{
	//获取TCP套接字
	int sockfd = *(int*)arg;
	
	int cliCounts;
	char *temp;
	
	char buf[138], msg[128], sendName[10], currentTime[20];
	for(;;)
	{
		//清空buf
		memset(buf, 0, sizeof(buf));
		//接收服务器的数据
		recv(sockfd, buf, sizeof(buf), 0);
		
		//拆分人数和用户名
		// sscanf(buf, "%s %s %d", sendName, msg, &cliCounts);
        cliCounts = atoi(&buf[strlen(buf)-1]);
		temp = strtok(buf, "::");
		strcpy(sendName, temp);
		temp = strtok(NULL, "::");
		strcpy(msg, temp);
		
		getTime(currentTime);
		printf("\n\n            --------时间:[%s]--------            \n", currentTime);
		if(!strcmp(sendName, name))
		{
			printf("                                            我发送了:%s\n                                            当前在线人数为:%d\n", msg, cliCounts);
		}
		else
		{
			printf("用户:%s 发送了:%s\n当前在线人数为:%d\n", sendName, msg, cliCounts);
		}
	}
	
	//退出线程
	// pthread_exit(NULL);
}

//用户登录
void logIn()
{
	char password[15];
	printf("------------------------欢迎来到TCP聊天室(quit退出)------------------------\n");

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

//主线程用来发送消息，子线程用来接收消息
int main(int argc, char* argv[])
{
	//获取连接服务器的套接字
	int sockfd = ServerSock(SERVERIP, PORT);
	
	//用户登录
	logIn();
	
	//创建线程对象
	pthread_t thread;
	pthread_create(&thread, NULL, recvMsgs, &sockfd);
	
	//主线程用来发送消息
	sendMsg(sockfd);
	
	//取消线程
	pthread_cancel(thread);
	
	//回收线程资源
	pthread_join(thread, NULL);
	
	//关闭套接字
	close(sockfd);
	return 0;
}