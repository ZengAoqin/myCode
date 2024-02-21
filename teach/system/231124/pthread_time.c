/*
使用函数ctime获取时间，然后使用子线程不断打印获取
*/

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>
#include <string.h>

#if 0
struct tm *localtime(const time_t *timep);
struct tm {
               int tm_sec;    /* Seconds (0-60) */
               int tm_min;    /* Minutes (0-59) */
               int tm_hour;   /* Hours (0-23) */
               int tm_mday;   /* Day of the month (1-31) */
               int tm_mon;    /* Month (0-11) */
               int tm_year;   /* Year - 1900 */
               int tm_wday;   /* Day of the week (0-6, Sunday = 0) */
               int tm_yday;   /* Day in the year (0-365, 1 Jan = 0) */
               int tm_isdst;  /* Daylight saving time */
           };

#endif

//通过线程获取实时时间
void* myTime(void* arg)
{
	time_t It; //时间格式
	struct tm *ptime = NULL; //获取时间的结构体
	char str[20]; 
	for(;;)
	{
		It = time(NULL); //获取系统秒数
		ptime = localtime(&It); //将时间格式转换为结构体
		bzero(str, sizeof(str));
		sprintf(str, "%d年%d月%d日 %02d:%02d:%02d", ptime->tm_year+1900, ptime->tm_mon+1, ptime->tm_mday, \
				ptime->tm_hour, ptime->tm_min, ptime->tm_sec);
		printf("日期:%s \n", str);
		sleep(1); //延迟1秒
	}
	
	pthread_exit(NULL);
}

int main(int argc, char* argv[])
{
	//定义线程号
	pthread_t thread;
	int ret = pthread_create(&thread, NULL, myTime, NULL);
	if(ret)
	{
		perror("create thread1 failed");
		return -1;
	}
	//资源回收
	pthread_join(thread, NULL);
	return 0;
}