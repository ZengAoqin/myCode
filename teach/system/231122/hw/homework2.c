/*
2、用信号模拟司机售票员：创建子进程代表售票员，父进程代表司机，
			1：售票员捕捉SIGINT(代表开车)，发SIGUSR1 给司机，
				司机捕捉到SIGUSR1 信号，后打印“move to next station”
			2: 售票员捕捉SIGQUIT(代表靠站)，发SIGUSR2 给司机，
				司机捕捉到SIGUSR2 信号，后打印“stop the bus”
			3: 司机捕获到SIGTSTP（车到总站），发SIGUSR1给售票员，
				售票员捕捉到SIGUSR1信号，后打印“all get off the bus”，
				全部进程结束
*/

#include <signal.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

//售票员进程号
pid_t pid;
int flag;

//售票员捕获SIGINT、SIGQUIT的响应函数
void to_driver(int sig)
{
	switch(sig)
	{
		case SIGINT:
		{
			kill(getppid(), SIGUSR1);
			break;
		}
		case SIGQUIT:
		{
			kill(getppid(), SIGUSR2);
			break;
		}
		default:
		break;
		
	}
}

//售票员捕获SIGUSR1的响应函数
void saler_print(int sig)
{
	printf("all get off the bus\n");
	flag = 0;
}

//司机捕获SIGUSR1的响应函数
void driver_print_1(int sig)
{
	printf("move to next station\n");
}

//司机捕获SIGUSR2的响应函数
void driver_print_2(int sig)
{
	printf("stop the bus\n");
}

//司机捕获SIGTSTP的响应函数
void to_saler(int sig)
{
	kill(pid, SIGUSR1);
}

int main(int argc, char* argv[])
{
	//创建子进程
	pid = fork();
	if(pid > 0) //父进程代表司机
	{
		//注册SIGUSR1信号的响应函数driver_print_1
		signal(SIGUSR1, driver_print_1);
		//注册SIGUSR2信号的响应函数driver_print_2
		signal(SIGUSR2, driver_print_2);
		//注册SIGTSTP信号的响应函数to_saler
		signal(SIGTSTP, to_saler);
		
		wait(NULL);
	}
	else if(pid == 0) //子进程代表售票员
	{
		flag = 1;
		
		signal(SIGINT, to_driver);
		signal(SIGQUIT, to_driver);
		signal(SIGUSR1, saler_print);
		
		while(flag)
		{
			pause();
		}
		
		exit(0);
	}
	
	return 0;
}