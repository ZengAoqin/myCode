#include <sys/socket.h>
#include <stdio.h>
#include <arpa/inet.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
	//a.创建UDP套接字 socket(UDP协议)
	int udpsock = socket(AF_INET, SOCK_DGRAM, 0);
	if(-1 == udpsock)
	{
		perror("udpsock failed");
		return -1;
	}
	printf("udpsock = %d\n", udpsock);
	
	//添加套接字的组播属性
	struct ip_mreq groupaddr;
	memset(&groupaddr, 0, sizeof(groupaddr));
	//设置组播地址和加入地址
	inet_pton(AF_INET, "224.0.0.100", &groupaddr.imr_multiaddr); //组播   /*一个局部连接多播地址，路由器不进行转发*/
	inet_pton(AF_INET, "192.168.2.103", &groupaddr.imr_interface); //主机
	//设置组播属性
	setsockopt(udpsock, IPPROTO_IP, IP_ADD_MEMBERSHIP, &groupaddr, sizeof(groupaddr));
	
	//b.给自己准备的ip地址和端口号
	struct sockaddr_in recvAddr;
	memset(&recvAddr, 0, sizeof(recvAddr));
	recvAddr.sin_family = AF_INET; //协议族
	recvAddr.sin_port = htons(atoi(argv[1])); //设置端口号
	recvAddr.sin_addr.s_addr = htonl(INADDR_ANY); //IPV4的地址
	
	//c.绑定套接字和地址数据 bind
	int ret = bind(udpsock, (struct sockaddr*)&recvAddr, sizeof(recvAddr));
	if(-1 == ret)
	{
		perror("bind failed");
		return -1;
	}
	
	//d.接收各方发送的UDP的数据报并且接收对端地址数据 recvfrom
	struct sockaddr_in sendaddr; //发送端的地址
	socklen_t len = sizeof(sendaddr);	//数据大小
	char buf[128];
	ssize_t recvSize;
	for(;;)
	{
		//清空buf
		memset(buf, 0, sizeof(buf));
		//接收数据
		recvSize = recvfrom(udpsock, buf, sizeof(buf), 0, (struct sockaddr*)&sendaddr, &len);
		printf("接收到[%s]发送端的内容为%s,接收的字节数为%ld\n", inet_ntoa(sendaddr.sin_addr), buf, recvSize);
		if(!strcmp(buf, "bye\n"))
		{
			break;
		}
	}
	
	//关闭套接字
	close(udpsock);
	return 0;
}