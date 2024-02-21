#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

#define P_PATH  "/home/softeem/myfifo"

int main(int argc, char* argv[])
{
	//创建有名管道文件
	int fd;
	int ret = mkfifo(P_PATH, 0777);
	//创建失败的原因是文件已经存在，直接打开管道文件即可
	if(-1 == ret && errno == EEXIST)
	{
		//打开文件
		fd = open(P_PATH, O_RDWR);
		if(-1 == fd)
		{
			perror("open failed");
			return -1;
		}
	}
	else if(-1 == ret) //创建有名管道文件失败
	{
		perror("mkfifo failed");
		return -1;
	}
	else if(0 == ret) //创建有名管道成功
	{
		//打开文件
		fd = open(P_PATH, O_RDWR);
		if(-1 == fd)
		{
			perror("open failed");
			return -1;
		}
	}
	
	//进程2从管道读取数据
	char buf[100];
	for(;;)
	{
		bzero(buf, sizeof(buf));
		//从有名管道文件中读取内容
		read(fd, buf, sizeof(buf));
		//打印读取的内容
		printf("进程1的发送内容:%s", buf); 
		//如果读取bye的时候退出
		if(strncmp(buf, "bye", 3) == 0) 
		{
			break;
		}
	}
	close(fd);
	return 0;
}


