#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	int fd1[2],fd2[2]; // fd1[0] 读 fd1[1]写 fd2[0] 读 fd2[1]写
	//创建无名管道
	int ret1 = pipe(fd1); 
	int ret2 = pipe(fd2); 
	if(-1 == ret1 || -1 == ret2)
	{
		perror("pipe failed");
		return -1;
	}
	
	//创建子进程
	char buf[100];
	pid_t pid = fork();
	if(pid > 0) //当前进程
	{
		for(;;)
		{
			//写数据
			bzero(buf, sizeof(buf));
			printf("请给你儿子打钱\n");
			scanf("%s", buf); //阻塞
			write(fd1[1], buf, strlen(buf));
			if(strcmp(buf, "bye") == 0)
				break;
			
			//读数据
			bzero(buf, sizeof(buf));
			read(fd2[0], buf, sizeof(buf));  //阻塞了
			printf("你给你儿子打了%s\n", buf);
			if(strcmp(buf, "bye") == 0)
				break;
		}
		wait(NULL);
	}
	else if(pid == 0) //子进程
	{
		for(;;)
		{
			//读数据
			bzero(buf, sizeof(buf));
			read(fd1[0], buf, sizeof(buf));  //阻塞了
			printf("你父亲给你打了%s\n", buf);
			if(strcmp(buf, "bye") == 0)
				break;
			
			//写数据
			bzero(buf, sizeof(buf));
			printf("请给你儿子打钱\n");
			scanf("%s", buf); //阻塞
			write(fd2[1], buf, strlen(buf));
			if(strcmp(buf, "bye") == 0)
				break;
		}
		
		exit(0);
	}
	
	return 0;
}