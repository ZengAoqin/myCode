#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

void* fun1(void* arg)
{
	for(;;)
	{
		printf("线程1的线程id:%ld\n", pthread_self());
		sleep(2);
	}
}

void* fun2(void* arg)
{
	for(;;)
	{
		printf("线程2的线程id:%ld\n", pthread_self());
		printf("我是线程2%s\n", (char*)arg);
		sleep(2);
	}
}

int main(int argc, char* argv[])
{
	//定义两个线程
	pthread_t thread1, thread2;
	int ret = pthread_create(&thread1, NULL, fun1, NULL);
	if(ret)
	{
		perror("create thread1 failed");
		return -1;
	}
	
	ret = pthread_create(&thread2, NULL, fun2, "武汉第一深情");
	if(ret)
	{
		perror("create thread2 failed");
		return -1;
	}
	
	//主线程任务
	for(;;)
	{
		printf("主线程的线程号:%ld\n", pthread_self());
		sleep(2);
	}
	return 0;
}