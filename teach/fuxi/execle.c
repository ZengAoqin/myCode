#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int argc, char* argv[])
{
	//创建子进程
	pid_t pid = fork();
	int ret;
	if(pid > 0) //当前进程
	{
		printf("当前进程\n");
		wait(NULL);
	}
	else if(pid == 0) //子进程
	{
		printf("子进程\n");
		//设置新的环境变量
		char* envp[]={"AAAAAAAAAAA==11111111", "BBBBBBBBBBBB=123456", NULL};
		//修改envion这个全局变量的值
		ret = execle("/mnt/hgfs/Share/fuxi/main", "main", "abc", "def", NULL, envp);
		if(-1 == ret)
		{
			perror("error\n");
		}
		exit(0);
	}
	return 0;
}