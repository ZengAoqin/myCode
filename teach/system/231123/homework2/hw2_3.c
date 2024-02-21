#include <sys/types.h>
#include <sys/ipc.h>
#include <stdio.h>
#include <sys/msg.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>

void fun(int sig)
{
	printf("pid:%d, sig: %d\n", getpid(), sig);
}

/*
挂起信号不会被子进程继承，但信号阻塞掩码会被继承
*/
int main(int argc, char** argv)
{
	//获取当前进程号
	printf("当前进程号%d\n", getpid());
	//定义响应函数
	signal(2, fun);
	signal(3, fun);
	
	sigset_t set; //信号集
	sigemptyset(&set); //清空信号集
	sigaddset(&set, 2); //加入信号2到信号集set
	sigaddset(&set, 3); //加入信号3到信号集set
	sigprocmask(SIG_BLOCK, &set, NULL); //设置set信号集为阻塞
	printf("阻塞状态\n");
	sleep(20);
	printf("非阻塞状态\n");
	
	printf("创建子进程\n");
	pid_t pid = fork();
	if(pid > 0) //当前进程，父进程
	{
		printf("当前进程\n");
		sigprocmask(SIG_UNBLOCK, &set, NULL); //设置set信号集为解除阻塞
		for(;;)
		{
			pause(); //挂起
		}
	}
	else if(pid == 0) //子进程
	{
		printf("子进程 pid: %d\n", getpid());
		sleep(10);
		sigprocmask(SIG_UNBLOCK, &set, NULL); //设置set信号集为解除阻塞
		for(;;)
		{
			pause(); //挂起
		}
	}
	
	
}

