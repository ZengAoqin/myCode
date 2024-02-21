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
		fprintf(stderr, "line[%d] connect failed\n", __LINE__);
		return -1;
	}
	
	return sockfd;
}

int main(int argc, char* argv[]) //./main 192.168.2.101 4000 1.txt
{
	//获取连接服务器的套接字
	int sockfd = ServerSock(argv[1], argv[2]);
	//获取文件名并发送
	send(sockfd, argv[3], strlen(argv[3]), 0);
	printf("send:%s\n", argv[3]);
	//打开文件操作
	int fd = open(argv[3], O_RDWR);
	if(-1 == fd)
	{
		fprintf(stderr, "line[%d] open failed\n", __LINE__);
		return -1;
	}
	
	//计算文件的大小
	int filesize = lseek(fd, 0, SEEK_END);
	printf("%s文件的大小为：%d\n", argv[3], filesize);
	//将占位符移至文件开头
	lseek(fd, 0, SEEK_SET);
	
	//循环读取并发送
	unsigned char sendinfo[1024];
	//获取每次读取的字节数
	int readnum;
	while(filesize > 0)
	{
		memset(sendinfo, 0, sizeof(sendinfo)); //清空数组
		//每次读取1024个字符
		readnum = read(fd, sendinfo, sizeof(sendinfo));
		send(sockfd, sendinfo, readnum, 0); //发送内容
		filesize -= readnum;
	}
	//关闭文件
	close(fd);
	//d.关闭客户端对象 close
	close(sockfd);
	return 0;
}