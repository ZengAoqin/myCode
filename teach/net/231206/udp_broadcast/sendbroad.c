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
	int udpsock = socket(AF_INET, SOCK_DGRAM, 0);
	if(-1 == udpsock)
	{
		perror("udp socket failed");
		return -1;
	}
	printf("udp的套接字编号为:%d\n", udpsock);
	
	//获取套接字的广播属性
	int val;
	int len = sizeof(val); 	//长度
	getsockopt(udpsock, SOL_SOCKET, SO_BROADCAST, &val, &len); //获取
	printf("当前获取广播属性的值%d %d\n", val, len);
	
	//设置广播属性为真
	int on = 1;
	setsockopt(udpsock, SOL_SOCKET, SO_BROADCAST, &on, sizeof(on)); //设置
	
	getsockopt(udpsock, SOL_SOCKET, SO_BROADCAST, &val, &len); //获取
	printf("设置以后的广播属性的值%d %d\n", val, len);
	
	//b.准备对端的IP地址信息 struct sockaddr_in addr;
	struct sockaddr_in recvAddr;
	memset(&recvAddr, 0, sizeof(recvAddr));
	recvAddr.sin_family = AF_INET; //协议族
	recvAddr.sin_port = htons(atoi(argv[2])); //设置端口号
	recvAddr.sin_addr.s_addr = inet_addr(argv[1]); //IPV4的地址
	
	//c.发送数据给到接收端，此次发送为(文本+IP+端口号) sendto
	char buf[128];
	int n;
	for(;;)
	{
		//准备发送数据
		memset(buf, 0, sizeof(buf));
		fgets(buf, sizeof(buf), stdin);
		//写入数据
		n = sendto(udpsock, buf, strlen(buf), 0, (struct sockaddr*)&recvAddr, sizeof(recvAddr));
		if(!strcmp(buf, "bye\n"))
			break;
	}
	
	//d.关闭发送端的套接字close
	close(udpsock);
	
	return 0;
}