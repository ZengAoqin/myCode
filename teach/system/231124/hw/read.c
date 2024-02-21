#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <errno.h>
#include <sys/shm.h>
#include <sys/sem.h>

int main(int argc, char** argv)
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
	
	//信号量的初始化
	int semID = semget(key, 2, IPC_CREAT|IPC_EXCL|0777);
	if(-1 == semID && errno == EEXIST) //因为存在退出
	{
		semID = semget(key, 2, 0666);
	}
	else if(-1 == semID)
	{
		perror("semget failed");
		return -1;
	}
	
	//因为此时没有数据，要写入数据，所以要申请空间，是p操作
	struct sembuf var;
	var.sem_num = 0; //0表示数组下标
	var.sem_op = -1; //p操作读取数据
	var.sem_flg = SEM_UNDO;
	
	unsigned short varData;
	int value = semctl(semID, 0, GETVAL, &varData); //第一个0是下标，数组下标0里面具体的值
	printf("下标为0的值是:varData = %d, value = %d\n", varData, value);
	
	for(;;)
	{
		printf("进行p操作\n");
		semop(semID, &var, 1);
		//读取内容
		printf("读取数据%s\n", p);
	}
	
	
	return 0;
}