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
	printf("sig: %d start \n", sig);
	sleep(1);
	printf("sig: %d end \n", sig);
}

/*
进程在响应信号时，信号会相互嵌套
*/

int main(int argc, char** argv)
{
	printf("当前进程号%d\n", getpid());
	//注册信号2、3、4的响应函数fun
	signal(2, fun);
	signal(3, fun);
	signal(4, fun);
	//一直挂起
	for(;;)
	{
		pause();
	}
	return 0;
}