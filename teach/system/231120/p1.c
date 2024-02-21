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
	else if(0 == ret)
	{
		//打开文件
		fd = open(P_PATH, O_RDWR);
		if(-1 == fd)
		{
			perror("open failed");
			return -1;
		}
	}
	
	//进程1从管道写数据
	char buf[100];
	for(;;)
	{
		bzero(buf, sizeof(buf));
		printf("请输入对进程2的内容\n");
		fgets(buf, sizeof(buf), stdin);
		write(fd, buf, strlen(buf));
		if(strncmp(buf, "bye", 3) == 0)
		{
			break;
		}
	}
	close(fd);
	return 0;
}


