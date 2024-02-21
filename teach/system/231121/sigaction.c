/*struct sigaction action;

struct sigaction {
               void     (*sa_handler)(int);
               void     (*sa_sigaction)(int, siginfo_t *, void *);
               sigset_t   sa_mask;
               int        sa_flags;
               void     (*sa_restorer)(void);
           };
*/

#include <signal.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>


//信号响应处理函数
void fun(int sig, siginfo_t* info, void* arg)
{
	printf("当前获取的信号为%d\n", sig);
	printf("当前除了信号，进程还赠送了一个整数%d\n", info->si_int);
}

int main(int argc, char* argv[])
{
	printf("当前进程的进程号为%d\n", getpid());
	
	struct sigaction action; //信号结构体
	//初始化信号结构体
	action.sa_sigaction = fun; //函数指针sa_sigaction指向响应函数
	action.sa_flags = SA_SIGINFO; //获取信号和数值
	//接受SIGINT信号
	sigaction(2, &action, NULL);
	//进程响应
	for(;;)
	{
		printf("hello world\n");
		sleep(1);
	}
	return 0;
}
