#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <errno.h>

int main(int argc, char** argv[])
{
	//申请系统健值
	key_t key = ftok(".", 10);
	if(-1 == key)
	{
		perror("ftok failed");
		return -1;
	}
	
	//获取信号量的id
	int semID = semget(key, 2, IPC_CREAT|IPC_EXCL|0777);
	if(-1 == semID && errno == EEXIST) //存在产生的错误
	{
		semID = semget(key, 2, 0666);
	}
	else if(-1 == semID)
	{
		perror("semget failed");
	}
	
	//获取信号量数组下标为0的值
	int value = semctl(semID, 0, GETVAL);
	printf("信号量的获取为%d\n", value);
	
	int ret = semctl(semID, 0, SETVAL, 10);
	if(-1 == ret)
	{
		perror("semctl SETVAL failed");
		return -1;
	}
	
	//获取信号量数组下标为0的值
	value = semctl(semID, 0, GETVAL);
	printf("信号量的获取为%d\n", value);
	
	//对申请信号量进行p操作 -1操作
	struct sembuf semPData; //信号量动作结构体
	semPData.sem_num = 0; //表示要做信号量的数组元素的下标
	semPData.sem_op = -1; //表示申请资源，p操作
	semPData.sem_flg = SEM_UNDO; //表示信号量操作以后还原
	
	printf("**********************************\n");
	
	for(int i = 0; i < 5; i++)
	{
		semop(semID, &semPData, 1); //1表示结构体的使用个数
		printf("信号量中下标为0的值%d\n", semctl(semID, 0, GETVAL));
	}
	
	printf("**********************************\n");
	
	struct sembuf semVData; //信号量动作结构体
	semVData.sem_num = 0; //表示要做信号量的数组元素的下标
	semVData.sem_op = 1; //表示申请资源，v操作
	semVData.sem_flg = SEM_UNDO; //表示信号量操作以后还原
	
	for(int i = 0; i < 10; i++)
	{
		semop(semID, &semVData, 1); //1表示结构体的使用个数
		printf("信号量中下标为0的值%d\n", semctl(semID, 0, GETVAL));
	}
	
	return 0;
}