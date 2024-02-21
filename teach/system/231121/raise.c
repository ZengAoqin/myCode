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
	signal(SIGUSR1, fun); //注册SIGUSR1用户信号捕获
	int num = 0;
	for(;;)
	{
		sleep(2);
		num++;
		num %= 2;
		if(num == 0)
		{
			raise(SIGUSR1); //自己给自己发送信号
		}
	}
	return 0;
}