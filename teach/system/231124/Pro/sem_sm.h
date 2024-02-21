#ifndef _SEM_SM_H
#define _SEM_SM_H

#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <errno.h>
#include <sys/shm.h>
#include <string.h>
#include <sys/sem.h>
#include <unistd.h>

extern int shmID;	//共享内存的ID
extern int semID;	//信号量ID
extern char* p;		//映射空间

//共享内存的初始化
extern int shm_init(void); //成功返回0，失败返回-1
//信号量的初始化
extern int sem_init(int len); //len：信号量数组长度，成功返回0，失败返回-1
//对信号量数组下标n的p操作
extern void sem_p(int semID, int n);
//对信号量数组下标n的v操作
extern void sem_v(int semID, int n);
//销毁资源
extern void destory(int shmID, int semID);

#endif