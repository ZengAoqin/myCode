#include <signal.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	//将字符串转换为整型数据
	pid_t pid = atoi(argv[1]);
	
	for(int i = 1; i <= 64; i++)
	{
		//剔除不存在信号和不可捕获的信号
		if(i == 9 || i == 19 || i == 32 || i == 33)
			continue;
		//发送信号
		kill(pid, i);
	}
	return 0;
}