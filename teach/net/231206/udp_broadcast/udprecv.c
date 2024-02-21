#include <stdio.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <netinet/in.h>

int main(int argc, char* argv[])
{
	//a.创建UDP套接字 socket(UDP协议)udpsock
	int udpsock =socket(AF_INET, SOCK_DGRAM, 0);
	
	//b.准备自己的ip地址 struct sockaddr_in addr;
	//定义结构体对象
	struct sockaddr_in addr;
	memset(&addr, 0, sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = htonl(INADDR_ANY);
	addr.sin_port = htons(atoi(argv[1]));
	
	//c.绑定套接字和地址数据：bind(udpsock, addr)
	int ret = bind(udpsock, (struct sockaddr*)&addr, sizeof(addr));
	if(-1 == ret)
	{
		perror("bind failed");
		return -1;
	}
	
	//d.接收各方发送的UDP数据报并且接收对端地址数据recvfrom
	struct sockaddr_in sendAddr;
	memset(&sendAddr, 0, sizeof(sendAddr));
	char buf[128];
	socklen_t len = sizeof(sendAddr);
	for(;;)
	{
		//清空buf
		memset(buf, 0, sizeof(buf));
		//接收数据
		ret = recvfrom(udpsock, buf, sizeof(buf), 0, (struct sockaddr*)&sendAddr, &len);
		printf("接收到来自[%s]发送的消息为:%s", inet_ntoa(sendAddr.sin_addr), buf);
	}
	
	//e.关闭接收端的套接字close
	close(udpsock);
	return 0;
}