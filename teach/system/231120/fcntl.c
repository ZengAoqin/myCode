#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
	pid_t pid;
	
	//以追加的形式打开文件
	int fd = open("test.txt", O_TRUNC | O_RDWR | O_CREAT, 0777);
	if(-1 == fd)
	{
		perror("open failed");
		return -1;
	}
	
	printf("fd = %d\n", fd);
	fcntl(fd, F_SETFD, 0);//关闭fd的close-on-exec标志
	
	//向文件写入数据"hello c program\n"
	write(fd, "hello c program\n", strlen("hello c program!\n"));
	
	pid = fork();
	if(pid < 0)
	{
        perror("fork");
        return -1;
    }
    if(pid == 0) //子进程
    {
        printf("fd = %d\n", fd);
        
        int ret = execl("./main", "./main", (char *)&fd, NULL);
        if(ret < 0)
        {
            perror("execl");
            exit(-1);
        }
        exit(0);
    }
	
	return 0;
}
