#include <signal.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>


//信号响应处理函数
void fun(int sig)
{
	for(int i = 0; i < 5; i++)
	{
		//printf("当前获取的信号为%d\n", sig);
		sleep(1);
	}
	printf("接受信号%d响应函数结束\n", sig);
}

int main(int argc, char* argv[])
{
	for(int i = 1; i <= 64; i++)
	{
		//剔除不存在的信号和不可捕获的信号
		if(i == 9 || i == 19 || i == 32 || i == 33)
		{
			/*
			19:停止(stopped)进程的执行. 注意它和terminate以及interrupt的区别:该进程还未结束, 
			只是暂停执行. 本信号不能被阻塞, 处理或忽略
			*/
			/*
			9.用来立即结束程序的运行. 本信号不能被阻塞、处理和忽略。如果管理员发现某个进程终止不了，可尝试发送这个信号
			*/
			continue;
		}
		//注册信号捕获
		signal(i,fun); //捕获信号，执行自定义的响应动作
	}

	//printf("当前的进程号:%d\n", getpid());
	//捕获信号，完成动作
	/* SIGINT程序终止(interrupt)信号, 在用户键入INTR字符(通常是Ctrl+C)时发出，用于通知前台进程组终止进程 */
	//signal(SIGINT, SIG_DFL); //捕获了SIGINT信号，执行默认的动作 default
	//signal(SIGINT, SIG_IGN); //捕获了SIGINT信号，执行忽略的动作 ignore
	//signal(SIGINT, fun); //捕获信号，执行自定义的响应动作
	//signal(9, fun); //不可捕获，不能忽略
	for(;;)
	{
		pause();
	}
}
