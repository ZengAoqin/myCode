#include "sem_sm.h"

union semun {                 //cmd关键字选择
       int              val;    /* Value for SETVAL */
       struct semid_ds *buf;    /* Buffer for IPC_STAT, IPC_SET */
       unsigned short  *array;  /* Array for GETALL, SETALL */
       struct seminfo  *__buf;  /* Buffer for IPC_INFO (Linux-specific) */
};

//共享内存的初始化
//成功返回0，失败返回-1
int shm_init(void)
{
	//1.申请系统键值
	key_t key = ftok(".", 10);
	if(-1 == key)
	{
		perror("ftok failed");
		return -1;
	}
	
	//2.申请共享内存的id
	shmID = shmget(key, 1024, IPC_CREAT|IPC_EXCL|0777);
	if(-1 == shmID && errno == EEXIST) //存在
	{
		shmID = shmget(key, 1024, 0666);
	}
	else if(-1 == shmID) //错误
	{
		perror("shmget failed");
		return -1;
	}
	
	//3.映射共享内存
	p = (char*)shmat(shmID, NULL, 0);
	if(NULL == p)
	{
		perror("shmat failed");
		return -1;
	}
	printf("p = %p\n", p);
	return 0;
}

//信号量的初始化
//len：信号量数组长度，成功返回0，失败返回-1
int sem_init(int len)
{
	//1.申请系统键值
	key_t key = ftok(".", 10);
	if(-1 == key)
	{
		perror("ftok failed");
		return -1;
	}
	
	//2.申请信号量id
	semID = semget(key, len, IPC_CREAT|IPC_EXCL|0777);
	if(-1 == semID && errno == EEXIST) //存在
	{
		semID = semget(key, len, 0666);
	}
	else if(-1 == semID) //错误
	{
		perror("semget failed");
		return -1;
	}
	
	//信号的初始值设置
	//下标为0的初始值为0
	union semun data;
	data.val = 0;
	semctl(semID, 0, SETVAL, data);
	//下标为1的初始值为1
	data.val = 1;
	semctl(semID, 1, SETVAL, data);
	return 0;
}

//对信号量数组下标n的p操作
void sem_p(int semID, int n)
{
	printf("p操作之前，下标为%d的数值%d\n", n, semctl(semID, n, GETVAL));
	//定义结构体
	struct sembuf var;
	var.sem_num = n; //表示要做信号量的数组下标n的操作
	var.sem_op = -1; //表示申请资源，p操作
	var.sem_flg = SEM_UNDO;	//表示信号量操作后还原
	//重设资源分配 执行一次p操作
	semop(semID, &var, 1);
	printf("p操作之后，下标为%d的数值%d\n", n, semctl(semID, n, GETVAL));
}

//对信号量数组下标n的v操作
void sem_v(int semID, int n)
{
	printf("v操作之前，下标为%d的数值%d\n", n, semctl(semID, n, GETVAL));
	//定义结构体
	struct sembuf var;
	var.sem_num = n; //表示要做信号量的数组下标n的操作
	var.sem_op = 1; //表示释放资源，v操作
	var.sem_flg = SEM_UNDO;	//表示信号量操作后还原
	//重设资源分配 执行一次v操作
	semop(semID, &var, 1);
	printf("v操作之后，下标为%d的数值%d\n", n, semctl(semID, n, GETVAL));
}

//销毁资源
void destory(int shmID, int semID)
{
	//解除映射
	shmdt(p);
	//删除共享内存
	shmctl(shmID, IPC_RMID, NULL);
	//删除信号量
	semctl(semID, 0, IPC_RMID);
}



