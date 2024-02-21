#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

//线程1任务函数
void* fun1(void* arg)
{
	for(;;)
	{
		printf("fun1\n");
		sleep(3);
	}
}

void* fun2(void* arg) 
{
	for(;;)
	{
		printf("fun2 = %s\n", (char*)arg);
		sleep(2);
	}
}

int main(int argc, char* argv[])
{
	//定义2个线程号
	pthread_t thread1, thread2;
	int ret = pthread_create(&thread1, NULL, fun1, NULL);
	if(0 != ret)
	{
		perror("create pthread failed");
		return -1;
	}
	
	ret = pthread_create(&thread2, NULL, fun2, (void*)"you are so handsome");
	if(0 != ret)
	{
		perror("create pthread failed");
		return -1;
	}
	
	//主线程任务
	for(;;)
	{
		printf("main\n");
		sleep(5);
	}
	return 0;
}