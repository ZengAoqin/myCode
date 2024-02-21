#include <signal.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

//信号响应函数
void fun(int sig)
{
	printf("current process recv signal:%d\n", sig);
}

int main(int argc, char** argv)
{
	//创建子进程
	int ret;
	pid_t pid = fork();
	if(pid > 0) //当前进程
	{
		//注册SIGINT信号的响应函数
		signal(SIGINT, fun);
		
		//定义信号集
		sigset_t set;
		
		//清空信号集
		sigemptyset(&set);
		//将所有的信号加入到信号集合
		sigfillset(&set);
		//判断某个信号是否存在于集合
		ret = sigismember(&set, SIGINT);
		if(ret < 0)
		{
			perror("sigismember failed");
			return -1;
		}
		else if(ret == 0)
		{
			printf("SIGINT不存在信号集\n");
		}
		else 
		{
			printf("SIGINT存在信号集\n");
		}
		
		//设置信号集的阻塞状态
		sigprocmask(SIG_BLOCK, &set, NULL);
		
		//在10秒以内SIGINT信号接收无效
		for(int i = 0; i < 10; i++)
		{
			sleep(1);
			printf("%d秒过去了\n", i+1);
		}
		//设置信号集的解除阻塞状态
		sigprocmask(SIG_UNBLOCK, &set, NULL);
		wait(NULL);
	}
	else if(pid == 0) //子进程
	{
		sleep(1);
		//发送信号
		kill(getppid(), SIGINT);
		//打印数据
		printf("I send SIGINT\n");
		exit(0);
	}
	return 0;
}