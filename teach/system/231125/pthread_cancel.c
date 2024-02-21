#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

int i = 0;
void* fun(void* arg)
{
	for(;;)
	{
		printf("线程正在执行任务%d\n", ++i);
		//sleep(1);
	}
	//++i;
}

int main(int argc, char* argv[])
{
	//创建线程
	pthread_t thread;
	int ret = pthread_create(&thread, NULL, fun, NULL);
	if(ret != 0)
	{
		perror("pthread_create failed");
		return -1;
	}
	sleep(5);
	printf("准备取消子线程，1秒后挂断\n");
	pthread_cancel(thread);
	printf("取消子线程完成\n");
	pthread_join(thread, NULL);
	printf("i = %d\n", i);
	return 0;
}