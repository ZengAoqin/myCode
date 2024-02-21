#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

void* fun(void* arg)
{
	//获取线程的识别号
	pthread_t thread = pthread_self();
	//设置线程为分离线程
	int ret = pthread_detach(thread);
	if(ret != 0)
	{
		perror("pthread_detach failed");
		exit(-1);
	}
	printf("线程运行结束\n");
	sleep(3);
	pthread_exit("线程game over...");
}

int main(int argc, char* argv[])
{
	//创建子线程
	pthread_t thread;
	int ret = pthread_create(&thread, NULL, fun, NULL); //默认结合性
	if(ret != 0)
	{
		perror("pthread_create failed");
		return -1;
	}
	usleep(10);
	//回收线程
	printf("主线程准备回收子线程...\n");
	void *var; //接收子线程返回值
	pthread_join(thread, &var);
	printf("回收的资源为: %s\n", (char*)var);
	return 0;
}