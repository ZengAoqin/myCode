#include <stdio.h>
#include <sys/socket.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char* argv[]) //./main 192.168.2.101 4000
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
	ServerAddr.sin_port = htons(atoi(argv[2])); //设置端口号
	ServerAddr.sin_addr.s_addr = inet_addr(argv[1]); //IPV4的地址
	//启动连接服务器
	connect(sockfd, (struct sockaddr *)&ServerAddr, sizeof(ServerAddr));
	
	//c.请求连接成功，通过套接字sockfd进行数据的接收和发送 recv/send
	char buf[128];
	ssize_t ret;
	for(;;)
	{
		sleep(1);
		//memset(buf, 0, sizeof(buf)); //清空数组
		//printf("请输入发送的内容\n");
		//fgets(buf, sizeof(buf), stdin);
		ret = send(sockfd, "handsome!", strlen("handsome!"), MSG_OOB);
		printf("当前发送的数据为%ld字节\n", ret);
	}
	//d.关闭客户端对象 close
	close(sockfd);
	return 0;
}