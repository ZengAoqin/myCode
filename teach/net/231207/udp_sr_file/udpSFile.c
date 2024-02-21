#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char** argv)
{
	//a.创建UDP套接字 socket(UDP协议)udpsock
	int udpsock = socket(AF_INET, SOCK_DGRAM, 0);
	if(-1 == udpsock)
	{
		perror("udpscok failed");
		return -1;
	}
	
	//b.准备发送端的IP地址信息 struct sockaddr_in addr;
	struct sockaddr_in addr;
	memset(&addr, 0, sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr=inet_addr("192.168.2.104"); //IPV4地址
	addr.sin_port = htons(6655);
	
	//打开文件
	int fd = open(argv[1], O_RDONLY);
	if(-1 == fd)
	{
		perror("open failed");
		return -1;
	}
	
	//获取文件名
	char sfilename[128] = {0};
	strcpy(sfilename, argv[1]);
	char* _fn = strrchr(sfilename, '/');
	if(_fn == NULL)
	{
		_fn = sfilename;
	}
	else
	{
		_fn += 1;
	}
	
	//获取文件大小
	int filesize = lseek(fd, 0, SEEK_END);
	char buf[256] = {0};
	sprintf(buf, "%d:%s", filesize, _fn);
	printf("send:%s\n", buf);
	
	//c.发送数据给到接收端，此次发送为(文本+IP+端口号) sendto
	socklen_t len = sizeof(addr);
	sendto(udpsock, buf, strlen(buf), 0, (struct sockaddr*)&addr, len);
	
	//d.关闭发送端的套接字close
	int readnum = 0;
	char sbuf[1024];
	//将占位符移至开头
	lseek(fd, 0, SEEK_SET);
	while(filesize > 0)
	{
		bzero(sbuf, sizeof(sbuf));
		readnum = read(fd, sbuf, sizeof(sbuf));
		sendto(udpsock, sbuf, strlen(sbuf), 0, (struct sockaddr*)&addr, len);
		filesize -= readnum;
	}
	
	close(fd);
	close(udpsock);
	return 0;
}