#include <signal.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>


//信号响应处理函数
void fun(int sig)
{
	printf("当前获取的信号为%d\n", sig);
}

int main(int argc, char* argv[])
{
	printf("当前进程号:%d\n", getpid());
	signal(SIGALRM, fun); //注册时钟信号捕获
	for(;;)
	{
		printf("before call alarm\n");
		alarm(10); //收到SIGALRM信号之后，10秒自动给当前进程发送时钟信号
		printf("after call alarm\n");
		pause(); //一直等待信号的发送，挂起进程
	}
	return 0;
}