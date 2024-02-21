/*
1.编写一段程序，使用系统调用函数fork( )创建两个子进程，
   再用系统调用函数signal( )让父进程捕捉信号SIGINT
（用kill命令来触发），当捕捉到中断信号后，
 父进程用系统调用函数kill( )向两个子进程发出信号，
 子进程捕捉到父进程发来的信号后，分别输出下列信息后终止： 
		Child process 1 is killed by parent!
		Child process 2 is killed by parent!
         或者
		Child process 2 is killed by parent!
        Child process 1 is killed by parent!
父进程等待两个子进程终止后，输出以下信息后终止：
        Parent process exit!
*/

#include <signal.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

pid_t pid1,pid2; //子进程号1和子进程号2

//当前进程接受SIGINT信号的响应函数
void parent_fun(int sig)
{
	kill(pid1, SIGUSR1); //给子进程号1发送信号SIGUSR1
	kill(pid2, SIGUSR1); //给子进程号2发送信号SIGUSR1
}

//子进程1接受SIGUSR1信号的响应函数
void son1_fun(int sig)
{
	printf("Child process 1 is killed by parent!\n");
}

//子进程2接受SIGUSR1信号的响应函数
void son2_fun(int sig)
{
	printf("Child process 2 is killed by parent!\n");
}

int main(int argc, char** argv)
{
	printf("当前进程号:%d\n", getpid());
	//创建子进程1
	pid1 = fork();
	if(pid1 > 0) //当前进程
	{
		pid2 = fork();
		if(pid2 > 0) //当前进程
		{
			signal(SIGINT, parent_fun);
			//因为有两个子进程，所以等待两次
			wait(NULL);
			wait(NULL);
			printf("Parent process exit!\n");
		}
		else if(pid2 == 0) //子进程2
		{
			signal(SIGUSR1, son2_fun);
			pause();
		}
	}
	else if(pid1 == 0) //子进程1
	{
		signal(SIGUSR1, son1_fun);
		pause();
	}
	return 0;
}