#include "sem_sm.h"
#include <signal.h>

int shmID;
int semID;
char* p = NULL;



void fun(int sig)
{
	printf("p = %p\n", p);
	destory(shmID, semID);
	printf("p = %p\n", p);
	kill(getpid(), 9);
}

int main(int argc, char* argv[])
{
	printf("pid = %d\n", getpid());
	//信号SIGINT注册，fun响应
	signal(SIGINT, fun);
	//共享内存初始化
	shm_init();
	//信号量的初始化
	sem_init(2);
	
	//写入内容
	char str[512];
	
	for(;;)
	{
		//信号量下标为1的元素进行p操作，保证进程执行
		sem_p(semID, 0); 
		printf("读出的数据:%s\n", p);
		sem_v(semID, 1); 
		
		strcpy(str, p);
		if(strcmp(str, "quit") == 0)
		{
			fun(2);
		}
	}
	
	return 0;
}