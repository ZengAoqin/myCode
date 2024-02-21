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
	else if(pid == 0)
	{
		printf("子进程\n");
		/*ret = execl("/bin/ls", "ls", "-l", NULL);
		if(-1 == ret)
		{
			perror("execl failed");
		}
		
		ret = execlp("ls", "ls", "-l", NULL);
		if(-1 == ret)
		{
			perror("execl failed");
		}
		*/
		char *argv[]={"ls", "-l", NULL};
		ret = execv("/bin/ls", argv);
		if(-1 == ret)
		{
			perror("execl failed");
		}
		
		exit(0);
	}
	return 0;
}