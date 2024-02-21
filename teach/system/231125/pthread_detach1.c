#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

void* fun(void* arg)
{
	sleep(1);
	printf("线程运行结束\n");
	pthread_exit("线程game over...");
}

int main(int argc, char* argv[])
{
	// a.定义一个属性变量对象 pthread_attr_t
	pthread_attr_t attr;
	
	//b.初始化属性变量对象   pthread_attr_init
	int ret = pthread_attr_init(&attr);
	if(ret != 0)
	{
		perror("pthread_attr_init error");
		return -1;
	}
	
	//c.设置线程的分离属性   pthread_attr_setdetachstate
	ret = pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
	if(ret != 0)
	{
		perror("pthread_attr_setdetachstate failed");
		return -1;
	}
	
	//d.用分离属性创建线程   pthread_create
	pthread_t thread;
	//ret = pthread_create(&thread, &attr, fun, NULL); //分离性
	ret = pthread_create(&thread, NULL, fun, NULL); //结合性
	if(ret != 0)
	{
		perror("PTHREAD_CREATE_DETACHED failed");
		return -1;
	}
	
	printf("主线程准备回收子线程...\n");
	void *var; //接收子线程返回值
	pthread_join(thread, &var);
	printf("回收的资源为: %s\n", (char*)var);
	
	//销毁属性对象         pthread_attr_destroy
	pthread_attr_destroy(&attr);
	return 0;
}