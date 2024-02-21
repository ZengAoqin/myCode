#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
	//创建套接字
	int udpsock = socket(AF_INET, SOCK_DGRAM, 0);
	if(-1 == udpsock)
	{
		perror("udpsock failed");
		return -1;
	}
	
	//定义需要绑定的信息
	struct sockaddr_in addr;
	memset(&addr, 0, sizeof(addr));
	addr.sin_family = AF_INET;	//协议族
	addr.sin_addr.s_addr = htonl(INADDR_ANY);	//IPV4地址
	addr.sin_port = htons(atoi(argv[1]));		//端口号
	
	socklen_t len = sizeof(addr);
	//绑定
	int ret = bind(udpsock, (struct sockaddr*)&addr, len);
	if(-1 == ret)
	{
		perror("bind failed");
		return -1;
	}
	
	//谁发送的
	struct sockaddr_in wAddr;
	memset(&wAddr, 0, sizeof(wAddr));
	
	char* buf = malloc(1024*sizeof(char));
	for(;;)
	{
		memset(buf, 0, 1024*sizeof(char));
		ret = recvfrom(udpsock, buf, 1024*sizeof(char), 0, (struct sockaddr*)&wAddr, &len);
		printf("来自[%s]发来的信息:%s", inet_ntoa(wAddr.sin_addr),buf);
		
		if(!strcmp(buf, "quit11111\n"))
			break;
		
		if(!strcmp(buf, ""))
			continue;
	}
	
	free(buf);
	buf = NULL;
	
	close(udpsock);
	return 0;
}