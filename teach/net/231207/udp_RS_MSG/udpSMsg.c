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

int main(int argc, char* argv[])
{
	//创建套接字
	int udpsock = socket(AF_INET, SOCK_DGRAM, 0);
	if(-1 == udpsock)
	{
		perror("udpsock failed");
		return -1;
	}
	
	struct sockaddr_in recvAddr;
	memset(&recvAddr, 0, sizeof(recvAddr));
	recvAddr.sin_family = AF_INET;
	recvAddr.sin_port = htons(atoi(argv[2]));	// 端口号
	recvAddr.sin_addr.s_addr = inet_addr(argv[1]);  // ip 地址
	
	//sendto
	char buf[1024];
	for(;;)
	{
		bzero(buf, sizeof(buf));
		fgets(buf, sizeof(buf), stdin);
		sendto(udpsock, buf, strlen(buf), 0, (struct sockaddr*)&recvAddr, sizeof(recvAddr));
		if(!strcmp(buf, "bye\n"))
			break;
	}
	
	close(udpsock);
	return 0;
}