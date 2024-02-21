#include <stdio.h>
#include <sys/socket.h>
#include <string.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
	//创建套接字
	int sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if(-1 == sockfd)
	{
		perror("socket failed");
		return -1;
	}
	
	//连接Server端
	struct sockaddr_in ServerAddr;
	memset(&ServerAddr, 0, sizeof(ServerAddr));
	ServerAddr.sin_family = AF_INET;
	//ServerAddr.sin_addr.s_addr = inet_addr(argv[1]); //IPV4 地址
	inet_pton(AF_INET, argv[1], &ServerAddr.sin_addr); //IPV4 地址
	ServerAddr.sin_port = htons(atoi(argv[2]));
	
	//连接服务器
	int ret = connect(sockfd, (struct sockaddr*)&ServerAddr, sizeof(ServerAddr));
	if(-1 == ret)
	{
		perror("connet failed");
		return -1;
	}
	
	//连接成功发送消息
	char buf[128];
	for(;;)
	{
		printf("请输入发送内容\n");
		memset(buf, 0, sizeof(buf));
		fgets(buf, sizeof(buf), stdin);
		buf[strlen(buf)-1] = '\0';
		ret = send(sockfd, buf, strlen(buf), 0);
		printf("当前发送的数据为%d字节\n", ret);
		if(!strcmp(buf, "quit"))
			break;
	}
	
	//关闭连接
	close(sockfd);
	return 0;
}