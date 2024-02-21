#include <signal.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	//将字符串转换为整型数据
	pid_t pid = atoi(argv[1]);
	int sig = atoi(argv[2]);
	//kill是我们的信号的发送 进程号 信号
	kill(pid, sig);
	return 0;
}