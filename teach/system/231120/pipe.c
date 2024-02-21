#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	int fd[2]; // fd[0] 读 fd[1]写
	//创建无名管道
	int ret = pipe(fd); 
	if(-1 == ret)
	{
		perror("pipe failed");
		return -1;
	}
	
	//创建子进程
	char buf[100];
	pid_t pid = fork();
	if(pid > 0) //当前进程
	{
		printf("当前进程\n");
		//读数据
		bzero(buf, sizeof(buf));
		read(fd[0], buf, sizeof(buf));  //阻塞了
		printf("你儿子给你打了%s\n", buf);
	}
	else if(pid == 0) //子进程
	{
		//写数据
		bzero(buf, sizeof(buf));
		printf("请给你父亲打钱\n");
		scanf("%s", buf);
		write(fd[1], buf, strlen(buf));
	}
	return 0;
}