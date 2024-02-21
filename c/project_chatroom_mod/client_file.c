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
#include <errno.h>

#define SERVERIP "192.168.2.103"
#define PORT "5678"
#define PASSWORD "123456"
#define BUFFER_SIZE 1024


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

//发送文件
int sendFile(int socket_fd, const char* file_path) 
{
	//打开文件
	int fd = open(file_path, O_RDWR, 0777);
    if (fd == -1) 
	{
        perror("open file failed\n");
		return -1;
    }

    char buffer[BUFFER_SIZE];
    int bytesRead;

	//读文件
    while (bytesRead = read(fd, buffer, BUFFER_SIZE))
	{
		//发送buffer
        if (send(socket_fd, buffer, bytesRead, 0) == -1) 
		{
            perror("failed to send file");
            return -1;
        }
    }
    
	close(fd);
	return 0;
}

//接收文件
int receiveFile(int client_fd, const char* file_path) 
{
	printf("path = %s\n", file_path);

    //打开文件
	int fd = open(file_path, O_CREAT|O_RDWR, 0666);
    if (fd == -1) 
	{
        perror("create file failed\n");
		return -1;
    }

    char buffer[BUFFER_SIZE];
    int bytesWrite;
	memset(buffer, 0, sizeof(buffer));

    for(;;)
	{
		//接收buffer
		bytesWrite = recv(client_fd, buffer, sizeof(buffer), 0);
		//写入文件
        if (write(fd, buffer, bytesWrite) == -1) 
		{
            perror("failed to write file");
            return -1;
        }
		
		if (bytesWrite < 1024)
		{
			break;
		}
    }
    
	close(fd);
	return 0;
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
	int type;
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
		
		if(!strcmp(msg, "sendfile"))
		{
			type = 2;		//客户端发送文件类型
			send(sockfd, &type, sizeof(type), 0);

			printf("请输入文件名:");
			memset(msg, 0, sizeof(msg));
			fgets(msg, sizeof(msg), stdin);
			msg[strcspn(msg, "\n")] = '\0';

			//发送文件名
			// send(sockfd, msg, strlen(msg), 0);
			// sleep(1);

			if(!sendFile(sockfd, msg))
			{
				printf("发送文件成功\n");
			}
		}
		else
		{
			type = 1;		//客户端发送消息类型
			send(sockfd, &type, sizeof(type), 0);
			//拼接用户名到buf
			sprintf(buf, "%s::%s", name, msg);
			
			//发送数据
			send(sockfd, buf, strlen(buf), 0);
			if(!strcmp(msg, "quit"))
			{
				break;
			}
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
	int type = 0, ret;
	int TIME;
	
	char buf[138], msg[128], sendName[10], currentTime[20], path[128];
	for(;;)
	{
		//清空buf
		memset(buf, 0, sizeof(buf));

		// 接收数据类型
		if (recv(sockfd, &type, sizeof(type), 0) == -1) 
		{
			perror("Failed to receive data type");
			exit(1);
		}

		if(type == 3)		//客户端接收消息类型
		{
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
			printf("\n\n                 --------时间:[%s]--------            \n", currentTime);
			if(!strcmp(sendName, name))
			{
				printf("                                            我发送了:%s\n                                            当前在线人数为:%d\n", msg, cliCounts);
			}
			else
			{
				printf("用户:%s 发送了:%s\n当前在线人数为:%d\n", sendName, msg, cliCounts);
			}
		}
		else if(type == 4)		//客户端接收文件类型
		{
			ret = mkdir("./clientfile/", 0777);
			if(ret == 0)
			{
				printf("文件夹创建成功\n");
			}
			else if(ret == -1 && errno == EEXIST)
			{
				printf("文件夹已存在\n");
			}
			else
			{
				printf("文件夹创建失败\n");
			}

			// srand(time(NULL));
			// int randomNumber = 100000 + rand() % (999999 - 100000 + 1);

			TIME = time(NULL);
			sprintf(path, "./clientfile/%d.jpg", TIME);

			if(!receiveFile(sockfd, path));
			{
				printf("File received\n");
			}
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
			printf("登录成功！\n");
			break;
		}
		else
		{
			printf("登录失败！\n");
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