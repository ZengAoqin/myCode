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

int main(int argc, char* argv[])  //组播 224.0.0.100 广播 192.168.2.255
{
	//创建套接字
	int udpsock = socket(AF_INET, SOCK_DGRAM, 0);
	if(-1 == udpsock)
	{
		perror("udpsock failed");
		return -1;
	}
	
	//设置广播属性为可用
	int value = 1;
	socklen_t len = sizeof(value);
	setsockopt(udpsock, SOL_SOCKET, SO_BROADCAST, &value, len);
	//setsockopt
	
	//定义接收端的结构体
	struct sockaddr_in recvAddr;
	memset(&recvAddr, 0, sizeof(recvAddr));
	recvAddr.sin_family = AF_INET;					//协议族
	recvAddr.sin_addr.s_addr = inet_addr(argv[1]); 	//ip地址
	recvAddr.sin_port = htons(atoi(argv[2]));		//端口号
	
	//sendto
	char buf[1024];
	for(;;)
	{
		//清空buf
		bzero(buf, sizeof(buf));
		fgets(buf, sizeof(buf), stdin);
		sendto(udpsock, buf, strlen(buf), 0, (struct sockaddr*)&recvAddr, sizeof(recvAddr));
		if(!strcmp(buf, "quit\n"))
			break;
	}
	
	close(udpsock);
	return 0;
}