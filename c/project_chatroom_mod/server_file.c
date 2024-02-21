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
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <errno.h>


#define CLIENT_MAX		20		//最多客户端连接数量
#define R_MAX			128		//最多读取字节数
#define B_MAX			138	
#define PORT "5678"             //端口号
#define BUFFER_SIZE 1024


//客户端的基础信息结构体
typedef struct client
{
	int confd;					//连接成功的客户端的套接字
	struct sockaddr_in addr;	//记录客户端的地址信息
	char username[10];			//用户名
	int count;					//记录客户端的个数
}client, *CLIENT;

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

int main(int argc, char* argv[])
{
	//获取服务端的套接字
	int tcpfd = tcpServerSock(PORT);
	
	//设置初始数据
	struct sockaddr_in addr;			//定义地址的结构体对象
	socklen_t len = sizeof(addr);		//地址长度
	int maxfd = tcpfd;					//用来保存存在最大的文件描述符
	fd_set rsets;						//读文件数据的集合
	struct timeval timeout;				//超时时间的结构体
	int i = 0, j = 0;					//i用来表示不同位置的下标
	client clients[CLIENT_MAX];			//客户端连接的数量
	char buf[R_MAX], Buf[B_MAX], wbuf[B_MAX], temp_1[B_MAX];
	int confd = 0, cliCounts = 0;		//连接成功客户端的套接字
	int ret = 0;
	char msg[R_MAX], sendName[10];
	int fd = 0, rwt = 0;
	char currentTime[20];
	char *temp = NULL;
	int type;
	char filename[128], path[256];
	int TIME;
	
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
		printf("准备监听 当前在线人数：%d\n", cliCounts);
		//监听文件描述符
		//int select(int nfds, fd_set *restrict readfds, fd_set *restrict writefds, fd_set *restrict errorfds, struct timeval *restrict timeout);
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
				printf("新用户上线:%s\n", inet_ntoa(addr.sin_addr));

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
					memset(Buf, 0, sizeof(Buf));
					memset(wbuf, 0, sizeof(wbuf));
					memset(temp_1, 0, sizeof(temp_1));
					
					// 接收数据类型
					if (recv(clients[i].confd, &type, sizeof(type), 0) == -1) 
					{
						perror("Failed to receive data type");
						exit(1);
					}

					if (type == 1) 		//服务器接受消息类型
					{
						recv(clients[i].confd, buf, sizeof(buf), 0); //普通数据接收
						strcpy(temp_1, buf);
						
						//拆分用户名获得信息
						// sscanf(buf, "%s %s", sendName, msg);
						temp = strtok(temp_1, "::");
						strcpy(sendName, temp);
						temp = strtok(NULL, "::");
						strcpy(msg, temp);

						strcpy(clients[i].username, sendName);		 //存放用户名

						//拼接writebuf
						getTime(currentTime);
						sprintf(wbuf, "用户 %s[ip:%s][confd:%d] 于%s 发送消息:%s\n", sendName, inet_ntoa(clients[i].addr.sin_addr), clients[i].confd, currentTime, msg);
						printf("%s", wbuf);

						//打开文件
						fd = open("./record.txt", O_RDWR|O_CREAT, 0777);
						if(fd == -1)
						{
							perror("open file failed\n");
							return -1;
						}

						//写入文件
						lseek(fd, 0, SEEK_END);
						rwt = write(fd, wbuf, strlen(wbuf));
						if(rwt == -1)
						{
							perror("write failed\n");
							return -1;
						}

						close(fd);

						printf("当前在线用户：");
						for(j = 0; j < cliCounts; j++)
						{
							printf("%s ", clients[j].username);
						}
						printf("\n");

						//客户端要退出
						if(!strcmp("quit", msg) || !strcmp("", msg))
						{
							//关闭文件描述符
							close(clients[i].confd);
							//向前覆盖
							for(j = i; j < cliCounts-1; j++)
							{
								clients[j] = clients[j+1];
							}
							cliCounts--;
							break;
						}
						
						//拼接onlineBuf
						sprintf(Buf, "%s::%d", buf, cliCounts);

						//向所有客户端发送消息
						for(j = 0; j < cliCounts; j++)
						{
							type = 3;			//服务器发送消息类型
							send(clients[j].confd, &type, sizeof(type), 0);

							send(clients[j].confd, Buf, strlen(Buf), 0);
						}
					} 
					else if (type == 2)  		//服务器接收文件类型
					{
						ret = mkdir("./serverfile/", 0777);
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

						// // 接收文件名
						// recv(clients[i].confd, filename, strlen(filename), 0);
						// sprintf(path, "./download/%s", filename);
						
						// srand(time(NULL));
						// int randomNumber = 100000 + rand() % (999999 - 100000 + 1);

						TIME = time(NULL);
						sprintf(path, "./serverfile/%d.jpg", TIME);

						if(!receiveFile(clients[i].confd, path));
						{
							printf("File received\n");
						}

						//向所有客户端发送文件
						for(j = 0; j < cliCounts; j++)
						{
							type = 4;			//服务器发送文件类型
							send(clients[j].confd, &type, sizeof(type), 0);

							if(!sendFile(clients[j].confd, path))
							{
								printf("发送文件成功\n");
							}
						}
					} 
				}
			}
		}
	}
	return 0;
}