#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

void* fun(void* arg)
{
	// 设置取消状态为不响应取消
	pthread_setcancelstate(PTHREAD_CANCEL_DISABLE, NULL);

	// 设置取消类型为立即响应
	pthread_setcanceltype(PTHREAD_CANCEL_ASYNCHRONOUS, NULL);

	while (1) {
		printf("子线程工作中...\n");
		sleep(1);
	}
}


int main(int argc, char* argv[])
{
	//定义子线程
	pthread_t thread_id;
	int ret = pthread_create(&thread_id, NULL, fun, NULL);
	if (ret)
	{
		perror("create thread1 failed");
		return -1;
	}

	// 主线程等待5s
	sleep(5);

	// 取消子线程
	printf("准备取消子线程\n");
	pthread_cancel(thread_id);
	printf("取消子线程完成\n");


	// 子线程资源回收
	pthread_join(thread_id, NULL);


	return 0;
}