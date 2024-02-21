#include <sys/socket.h>
#include <stdio.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
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
	
	//获取套接字的广播属性
	int value;
	int len = sizeof(value);
	
	getsockopt(udpsock, SOL_SOCKET, SO_BROADCAST, &value, &len); //获取
	printf("当前获取广播属性的值%d %d\n", value, len);
	
	//设置广播属性为真
	int on = 1;
	len = sizeof(on);
	setsockopt(udpsock, SOL_SOCKET, SO_BROADCAST, &on, sizeof(on)); //设置
	
	//b.准备对端的ip地址和端口号
	struct sockaddr_in recvAddr;
	memset(&recvAddr, 0, sizeof(recvAddr));
	recvAddr.sin_family = AF_INET; //协议族
	recvAddr.sin_port = htons(atoi(argv[2])); //设置端口号
	recvAddr.sin_addr.s_addr = inet_addr(argv[1]); //IPV4的地址
	
	//c. 发送消息给对端 sendto
	ssize_t ret;
	char buf[128];
	for(;;)
	{
		//清空buf
		memset(buf, 0, sizeof(buf));
		printf("请输入消息内容\n");
		fgets(buf, sizeof(buf), stdin);
		//向UDP套接字发送数据
		ret = sendto(udpsock, buf, strlen(buf), 0, (struct sockaddr *)&recvAddr, sizeof(recvAddr));
		printf("发送的字节数为:%ld\n", ret);
		if(!strcmp(buf, "bye\n"))
		{
			break;
		}
	}
	
	//d.关闭套接字
	close(udpsock);
	return 0;
}