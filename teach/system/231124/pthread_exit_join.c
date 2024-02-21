#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

void* fun1(void* arg)
{
	for(int i = 0; i < 5; i++)
	{
		printf("子线程1正在工作%d次\n", i+1);
		sleep(1);
	}
	//子线程1退出
	pthread_exit(NULL);
}

void* fun2(void* arg)
{
	printf("主线程传递的参数%s\n", (char*)arg);
	for(int i = 0; i < 5; i++)
	{
		printf("子线程2正在工作%d次\n", i+1);
		sleep(1);
	}
	
	//子线程2退出
	pthread_exit((void*)"byebye");
}

int main(int argc, char* argv[])
{
	//定义线程号
	pthread_t thread1, thread2;
	//创建子线程
	int ret = pthread_create(&thread1, NULL, fun1, NULL);
	if(ret)
	{
		perror("create thread1 failed");
		return -1;
	}
	
	ret = pthread_create(&thread2, NULL, fun2, "线程2");
	if(ret)
	{
		perror("create thread2 failed");
		return -1;
	}
	
	int i = 0;
	while(i++ < 3)
	{
		printf("主线程正在工作%d次\n", i);
		sleep(1);
	}
	
	ret = pthread_join(thread1, NULL);
	if(ret == 0)
	{
		printf("子线程1资源回收成功\n");
	}
	
	printf("*******************\n");
	
	char* pStr; //获取返回值
	ret = pthread_join(thread2, (void**)&pStr);
	if(ret == 0)
	{
		printf("子线程2资源回收成功, 回收的内容%s\n", pStr);
	}
	return 0;
}