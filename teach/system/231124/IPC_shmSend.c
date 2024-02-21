#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <errno.h>
#include <sys/shm.h>
#include <string.h>


int main(int argc, char** argv[])
{
	//申请系统健值
	key_t key = ftok(".", 10);
	if(-1 == key)
	{
		perror("ftok failed");
		return -1;
	}
	
	//申请IPC共享内存
	int shmID = shmget(key, 512*2, IPC_CREAT|IPC_EXCL|0777);
	if(-1 == shmID && errno == EEXIST) //若存在直接打开
	{
		shmID = shmget(key, 512*2, 0666);  //打开IPC共享内存
	}
	else if(-1 == shmID) //错误
	{
		perror("shmget failed");
		return -1;
	}
	
	//映射IPC共享内存
	char* p = (char*)shmat(shmID, NULL, 0);
	if(NULL == p)
	{
		perror("shmat failed");
		return -1;
	}
	
	//写入内容
	char str[512];
	bzero(str, sizeof(str));
	printf("请输入数据\n");
	fgets(str, sizeof(str), stdin);
	str[strlen(str)-1] = '\0'; //处理换行
	strcpy(p, str);
	
	//获取共享内存属性
	struct shmid_ds buf;
	shmctl(shmID, IPC_STAT, &buf);
	printf("IPC共享的大小:%ld\n", buf.shm_segsz);
	
	return 0;
}