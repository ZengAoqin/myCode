#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include <sys/wait.h>

#define P_PATH  "/home/softeem/myfifo"
#define P_PATH_E  "/home/softeem/myfifoE"

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

/*
改造p1s.c和p2s.c这两个文件，分别在各自进程中创建父子进程，完成收发操作
          形成双向通信
*/

int main(int argc, char* argv[])
{
	char buf[100];
	int fd;
	pid_t pid = fork();
	switch(pid)
	{
		case 0: //子进程
		{
			//创建有名管道文件
			fifo_file(P_PATH);
				
			//打开有名管道文件
			fd = fifo_open(P_PATH);
			if(-1 == fd) return -1;
			
			for(;;) //子进程读取
			{
				bzero(buf, sizeof(buf));
				//从有名管道文件中读取内容
				read(fd, buf, sizeof(buf));
				//打印读取的内容
				printf("当前进程的发送内容:%s", buf); 
				//如果读取bye的时候退出
				if(strncmp(buf, "bye", 3) == 0) 
				{
					break;
				}
			}
			break;
		}
		case -1: //创建进程失败
		{
			perror("fork failed");
			break;
		}
		default: //当前进程
		{
			//创建有名管道文件
			fifo_file(P_PATH_E);
	
			//打开有名管道文件
			fd = fifo_open(P_PATH_E);
			
			for(;;) //当前进程写入
			{
				bzero(buf, sizeof(buf));
				//打印读取的内容
				printf("请输入发送给子进程的内容\n");
				fgets(buf, sizeof(buf), stdin);
				//从有名管道文件中读取内容
				write(fd, buf, sizeof(buf));
				//如果读取bye的时候退出
				if(strncmp(buf, "bye", 3) == 0) 
				{
					break;
				}
				usleep(100);
			}
			break;
		}
	}
	
	if(pid == 0) //子进程
	{
		close(fd);
		//删除有名管道文件
		delete_fifo(P_PATH);
		exit(0);
	}
	else if(pid > 0) //当前进程
	{
		wait(NULL);
	}
	
	close(fd);
	
	return 0;
}


