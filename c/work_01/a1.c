#include <signal.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

void fun1(int sig)
{
	
	printf("Child process 1 is killed by parent!\n");
}

void fun2(int sig)
{
	printf("Child process 2 is killed by parent!\n");
}

int main(int argc, char* argv[])
{
	pid_t pid1,pid2;
	
	pid1 = fork();
	
	if (pid1 == 0) {
        // 子进程1
		//注册信号捕获
		signal(SIGINT, fun1);
		//一直等待信号的发送，挂起进程
		pause();
		exit(0);
    } else if (pid1 > 0) {
        // 父进程
		kill(pid1, SIGINT);
        // 创建第二个子进程
		pid2 = fork(); 
        
        if (pid2 == 0) {
			//注册信号捕获
			signal(SIGUSR1, fun2);
			pause();
			exit(0);
        } else if (pid2 > 0) {
            // 父进程
			kill(pid2, SIGINT);
        } 
    } 
	
	return 0;
}