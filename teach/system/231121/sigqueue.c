#include <signal.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	//获取进程号
	pid_t pid = atoi(argv[1]);
	//int sigqueue(pid_t pid, int sig, const union sigval value);
	//配置额外参数联合体
	union sigval value;
	value.sival_int = 100;
	
	//发送信号
	sigqueue(pid, 2, value);
	return 0;
}