#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char* argv[])
{
	//a.创建UDP套接字 socket(UDP协议)udpsock
	int udpscok = socket(AF_INET, SOCK_DGRAM, 0);
	if(-1 == udpscok)
	{
		perror("udp socket failed");
		return -1;
	}
	//b.准备自己的ip地址 struct sockaddr_in addr;
	struct sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = inet_addr("0.0.0.0");	//IPv4地址 htonl("0.0.0.0");
	addr.sin_port = htons(6655);	//端口
	
	//c.绑定套接字和地址数据：bind(udpsock, addr)
	int ret = bind(udpscok, (struct sockaddr*)&addr, sizeof(addr));
	if(-1 == ret)
	{
		perror("bind failed");
		return -1;
	}
	
	printf("I'm here 1\n");
	//d.接收各方发送的UDP数据报并且接收对端地址数据recvfrom
	struct sockaddr_in sendAddr;
	memset(&sendAddr, 0, sizeof(sendAddr)); //清空发送方信息结构体
	char buf[256] = {0};
	socklen_t len;
	recvfrom(udpscok, buf, sizeof(buf), 0, (struct sockaddr*)&sendAddr, &len);
	printf("I'm here 2\n");
	//文件名:文件大小
	char filename[128] = {0};
	int filesize = 0,readnum = 0;
	//拆分成两个变量（文件名和文件大小）
	sscanf(buf, "%d:%s", &filesize, filename);
	char saveFilename[256] = {0}; //创建的文件名
	//拼接一个新的文件路径
	sprintf(saveFilename, "%s/%s", argv[1], filename);
	printf("保存到%s\n", saveFilename);
	int fd = open(saveFilename, O_CREAT|O_RDWR, 0666);
	if(-1 == fd)
	{
		perror("open failed");
		return -1;
	}
	
	char rbuf[1024];
	//循环读取内容
	while(filesize > 0)
	{
		//清空rbuf
		memset(rbuf, 0, sizeof(rbuf));
		readnum = recvfrom(udpscok, rbuf, sizeof(rbuf), 0, (struct sockaddr*)&sendAddr, &len);
		write(fd, rbuf, readnum);
		printf("接收到数据为%s 接收到的字节数为%d\n", rbuf, readnum);
		filesize -= readnum;
	}
	
	//e.关闭接收端的套接字close
	close(udpscok);
	return 0;
}