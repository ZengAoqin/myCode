#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <errno.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <unistd.h>


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
	
	//获取信号量的id
	int semID = semget(key, 1, IPC_CREAT|IPC_EXCL|0777);
	if(-1 == semID && errno == EEXIST) //存在产生的错误
	{
		semID = semget(key, 1, 0666);
	}
	else if(-1 == semID)
	{
		perror("semget failed");
	}

	struct sembuf semPData; //信号量动作结构体
	semPData.sem_num = 0; //表示要做信号量的数组元素的下标
	semPData.sem_op = -1; //表示申请资源，p操作
	semPData.sem_flg = SEM_UNDO; //表示信号量操作以后还原
	
	int value;
	
	for(;;)
	{
		//获取信号量数组下标为0的值
		value = semctl(semID, 0, GETVAL);
		printf("信号量为%d\n", value);
		
		//p操作
		semop(semID, &semPData, 1); //1表示结构体的使用个数
		//读取内容
		printf("reader读取数据:%s\n", p);
	}
	
	
	return 0;
}