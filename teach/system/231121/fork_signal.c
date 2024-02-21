#include <signal.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

void fun(int sig)
{
	printf("当前获取的信号值为%d\n", sig);
}

int main(int argc, char* argv[])
{
	pid_t pid = fork();
	if(pid > 0) //当前进程
	{
		printf("子进程号: pid = %d\n", pid);
		printf("当前进程号: getpid() = %d\n", getpid());
		sleep(3);
		kill(pid, SIGUSR1); //发送信号
		wait(NULL);
	}
	else if(pid == 0) //子进程
	{
		printf("子进程:%d\n", getpid());
		printf("before signal\n");
		sleep(2);
		//注册信号捕获
		signal(SIGUSR1, fun);
		sleep(2);
		printf("after signal\n");
		//一直等待信号的发送，挂起进程
		pause();
	}
	return 0;
}