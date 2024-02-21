#include "sem_sm.h"
#include <signal.h>
#include <stdlib.h>

int shmID;
int semID;
char* p = NULL;
pid_t pid;

void fun(int sig)
{
	printf("p = %p\n", p);
	destory(shmID, semID);
	//printf("p = %p\n", p);
	//printf("pid = %d\n", pid);
	//kill(pid, 9);
	kill(getpid(), 9);
}

int main(int argc, char* argv[])
{
	//信号SIGINT注册，fun响应
	signal(SIGINT, fun);
	//共享内存初始化
	shm_init();
	//信号量的初始化
	sem_init(2);
	
	//pid = atoi(argv[1]);
	
	//写入内容
	char str[512];
	
	for(;;)
	{
		//信号量下标为1的元素进行p操作，保证进程执行
		sem_p(semID, 1); //因为下标为1的元素初始值为1，p操作(-1)以后结果为0
		printf("请输入数据\n");
		
		bzero(str, sizeof(str));
		fgets(str, sizeof(str), stdin);
		str[strlen(str)-1] = '\0'; //处理换行
		strcpy(p, str);
		sem_v(semID, 0); //因为下标为0的元素初始值为0，v操作(+1)以后结果为1
		
		if(strcmp(str, "quit") == 0)
		{
			fun(2);
		}
	}
	
	return 0;
}