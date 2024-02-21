#include <signal.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

//定义全局变量
int testData = 10;	

void func(int sig)
{
	//根据接收信号的不同，设置不同的参数
	if(sig == SIGUSR1)
	{
		testData = 200;
	}
	else if(sig == SIGUSR2)
	{
		testData = 100;
	}
}

int main(int argc, char** argv)
{
	signal(SIGUSR1, func);
	signal(SIGUSR2, func);
	
	printf("testData = %d, pid=%d\n", testData, getpid());
	
	int n = 0;
	while(n++ < 10)
		sleep(1);

	printf("testData = %d, pid=%d\n", testData, getpid());
	return 0;
}