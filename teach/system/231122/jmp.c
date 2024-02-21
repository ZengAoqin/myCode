#include <signal.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <setjmp.h>

//跳转的标记
jmp_buf env;

void fun(int sig)
{
	switch(sig)
	{
		case SIGUSR1:
		{
			longjmp(env, 1); //跳转到setjmp(env)，并且函数结果为1
			break;
		}
		case SIGUSR2:
		{
			longjmp(env, 2);
			break;
		}
		default:
		{
			break;
		}
	}
}

int main(int argc, char** argv)
{
	printf("current pid:%d\n", getpid());
	int ret = setjmp(env);
	printf("call setjmp ret = %d\n", ret);
	switch(ret)
	{
		case 1:
		{
			printf("env=1\n");
			break;
		}
		case 2:
		{
			printf("env=2\n");
			break;
		}
		default:
		{
			printf("env=%d\n", ret);
			break;
		}
	}
	
	//注册信号SIGUSR1
	signal(SIGUSR1, fun);
	signal(SIGUSR2, fun);
	
	for(;;);
	
	return 0;
}