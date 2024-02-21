#include <stdio.h>
#include <sys/socket.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

//获取连接成功的套接字对象
int ConfdSock(const char* prot, int* sockfd)
{
	//a.建立TCP连接，创建Socket文件描述符fd(sockfd)，即建立通信端点 socket
	*sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if(-1 == *sockfd)
	{
		fprintf(stderr, "line[%d] socket failed\n", __LINE__);
		return -1;
	}
	else
	{
		printf("成功申请套接字为：%d\n", *sockfd);
	}
	
	//b.绑定套接字文件描述符sockfd与网络地址和端口号，即ip地址+端口号 bind
	//初始化IP地址和端口的结构体
	struct sockaddr_in ServerAddr; 	//定义结构体对象
	memset(&ServerAddr, 0, sizeof(ServerAddr)); //清空操作
	ServerAddr.sin_family = AF_INET; //协议族
	ServerAddr.sin_port = htons(atoi(prot)); //设置端口号
	ServerAddr.sin_addr.s_addr = htonl(INADDR_ANY); //获取服务器的IP地址
	int ret = bind(*sockfd, (struct sockaddr *)&ServerAddr, sizeof(ServerAddr));
	if(-1 == ret)
	{
		fprintf(stderr, "line[%d] bind failed\n", __LINE__);
		return -1;
	}
	
	//c.设置套接字进入被动监听状态，即设置套接字的监听 listen
	listen(*sockfd, 1);
	
	//d.等待客户端连接服务器，发起连接请求 accept
	struct sockaddr_in ClientAddr; 	//定义结构体对象
	memset(&ClientAddr, 0, sizeof(ClientAddr)); //清空操作
	
	socklen_t len = sizeof(ClientAddr);
	int confd = accept(*sockfd, (struct sockaddr *)&ClientAddr, &len);
	if(-1 == confd)
	{
		fprintf(stderr, "line[%d] accept failed\n", __LINE__);
		return -1;
	}
	printf("连接成功的套接字%d\n", confd);
	
	return confd;
}

int main(int argc, char* argv[])
{
	int sockfd;
	//获取成功的套接字对象
	int confd = ConfdSock(argv[1], &sockfd);
	//接收对方发送的文件名
	char fbuf[32] = {0}; //清空的初始化
	recv(confd, fbuf, sizeof(fbuf), 0);
	printf("send:%s\n", fbuf);
	//拆分文件名和大小
	char filename[20]={0};
	int filesize = 0;
	sscanf(fbuf,"%d:%s", &filesize, filename);
	//设置保存文件的工作路径
	char sbuf[128] = {0};
	getcwd(sbuf, sizeof(sbuf));
	char ssbuf[256] = {0};
	sprintf(ssbuf, "%s/%s", sbuf, filename);
	//创建文件操作
	int fd = open(ssbuf, O_CREAT|O_RDWR, 0666);
	if(-1 == fd)
	{
		fprintf(stderr, "line[%d] open failed\n", __LINE__);
		return -1;
	}
	printf("创建文件%s\n", ssbuf);
	
	//循环读取文件的内容，并通过套接字写入
	unsigned char recvinfo[1024]; //每次发送文件大小
	int readnum; //每次读取的字节数
	while(filesize > 0)
	{
		readnum = read(confd, recvinfo, sizeof(recvinfo));
		printf("%s\n", recvinfo);
		//如果成功读取1024字节，则写入全部1024字节
		write(fd, recvinfo, readnum);
		filesize -= readnum;
	}
	
	close(fd);
	close(confd);
	
	//f.关闭服务端对象 close
	close(sockfd);
	return 0;
}