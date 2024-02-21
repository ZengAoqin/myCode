#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void* fun(void* arg)
{
	//设置子线程为不可取消状态，不保存线程原来的取消状态
	 pthread_setcancelstate(PTHREAD_CANCEL_DISABLE, NULL);
	 for(;;)
	 {
		 printf("线程正在执行任务\n");
		 sleep(1);
	 }
}

int main(int argc, char* argv[])
{
	//定义线程id
	pthread_t thread;
	//创建线程对象
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
	return 0;
}