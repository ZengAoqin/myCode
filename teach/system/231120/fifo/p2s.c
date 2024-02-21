#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

#define P_PATH  "/home/softeem/myfifo"

//有名管道文件创建
int fifo_file(const char* path)
{
	//判断管道文件是否存在
	if(access(path, F_OK) != 0) //管道文件不存在
	{
		//创建有名管道文件
		int ret = mkfifo(path, 0777);
		if(ret == -1) //判断创建是否失败
		{
			perror("mkfifo faied");
			return -1;
		}
		printf("有名管道文件创建成功\n");
	}
	else
	{
		printf("有名管道文件存在\n");
	}
}

//打开有名管道文件
int fifo_open(const char* path)
{
	//打开有名管道文件
	int fd = open(path, O_RDWR);
	if(fd == -1)
	{
		perror("open fifo file failed");
	}
	
	return fd;
}

//删除管道文件
int delete_fifo(const char* path)
{
	int ret = unlink(path);
	if(-1 == ret)
	{
		perror("unlink failed");
	}
	
	return ret;
}

int main(int argc, char* argv[])
{
	//创建有名管道文件
	fifo_file(P_PATH);
	
	//打开有名管道文件
	int fd = fifo_open(P_PATH);
	if(-1 == fd) return -1;
	
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
	
	//删除有名管道文件
	delete_fifo(P_PATH);
	return 0;
}

