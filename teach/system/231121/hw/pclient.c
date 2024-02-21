#include "fun.h"
#include <time.h>

int main(int argc, char* argv[])
{
	//创建有名管道文件
	fifo_file(P_PATH);
	//获取有名管道的文件描述符
	int fifo_fd = fifo_open(P_PATH);
	//向有名管道写入数据
	char buf[100];
	pid_t pid;
	time_t t;
	for(;;)
	{
		//生成子进程
		pid = fork();
		if(pid == 0) //子进程
		{
			//清空数据
			bzero(buf, sizeof(buf));
			time(&t); //获取系统时间读秒
			sprintf(buf, "time:%s pid[%d]\n", ctime(&t), getpid());
			//将数据写入到有名管道
			write(fifo_fd, buf, strlen(buf));
			//退出子进程
			exit(0);
		}
		sleep(2);
	}
	return 0;
}