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
	//创建TCP的套接字
	int tcpfd = socket(AF_INET, SOCK_STREAM, 0);
	if(-1 == tcpfd)
	{
		perror("tcpfd failed");
		return -1;
	}
	
	//准备接收端地址信息
	struct sockaddr_in recvAddr;
	memset(&recvAddr, 0, sizeof(recvAddr));
	recvAddr.sin_family = AF_INET;
	recvAddr.sin_addr.s_addr = inet_addr(argv[1]);
	recvAddr.sin_port = htons(atoi(argv[2]));
	
	//连接服务器
	int ret = connect(tcpfd, (struct sockaddr*)&recvAddr, sizeof(recvAddr));
	if(-1 == ret)
	{
		perror("connet failed");
		return -1;
	}
	
	//聊天
	for(;;) //测试数据
	{
		send(tcpfd, "123", 3, 0); //发送了123
		sleep(1);
		send(tcpfd, "qwert", 5, 0); //发送了qwert
		sleep(1);
		send(tcpfd, "ABCC", 4, MSG_OOB); //发送紧急外带数据C，普通数据是AB
		sleep(1);
		send(tcpfd, "asdfa", 5, 0);  //发送了asdfa
		sleep(1);					
		send(tcpfd, "tyui", 4, 0);  //发送了tyui
		sleep(1);
		send(tcpfd, "asdff", 5, MSG_OOB); //发送紧急外带数据f，普通数据是asd
		sleep(1);
		send(tcpfd, "ZBASDF", 6, 0);  //发送了ZBASDF
		sleep(1);
		send(tcpfd, "byeT", 4, 0);  //发送了byeT
		sleep(1);
	}
	return 0;
}