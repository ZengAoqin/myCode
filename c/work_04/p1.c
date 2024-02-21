#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <errno.h>
#include <string.h>

#define PATH "."
#define DATA 10

//定义消息结构体
typedef struct msgbuf
{
	long mtype;
	char mtext[50];
}msgbuf;

//子线程
void* func(void* arg)
{
	//初始化消息结构体
	msgbuf sendMsg;
	sendMsg.mtype = 888;

	//发送888消息
	while (1)
	{
		printf("请输入发送给p2的内容:\n");
		bzero(sendMsg.mtext, sizeof(sendMsg.mtext));
		fgets(sendMsg.mtext, sizeof(sendMsg.mtext), stdin);

		//发送消息队列
		msgsnd(*(int*)arg, &sendMsg, sizeof(sendMsg.mtext), 0);
		if (strcmp(sendMsg.mtext, "bye\n") == 0)
		{
			break;
		}
	}

	//删除消息队列
	msgctl(*(int*)arg, IPC_RMID, NULL);

	//线程退出
	pthread_exit(NULL);
}

int main(int argc, char* argv[])
{
	//申请Key值
	key_t key = ftok(PATH, DATA);
	if (-1 == key)
	{
		perror("ftok failed");
		return -1;
	}

	//申请消息队列
	int msgid = msgget(key, IPC_CREAT | IPC_EXCL | 0777);
	if (-1 == msgid && errno == EEXIST)
	{
		//直接打开消息队列
		msgid = msgget(key, 0666);
	}
	else if (-1 == msgid)
	{
		perror("msgget failed");
	}

	//定义线程号
	pthread_t thread;

	//创建子线程
	int ret = pthread_create(&thread, NULL, func, &msgid);
	if (ret)
	{
		perror("create failed");
	}

	//主线程
	//初始化消息结构体
	msgbuf recvMsg;

	//接收666消息
	while (1)
	{
		bzero(&recvMsg, sizeof(recvMsg));

		//接受消息队列
		msgrcv(msgid, &recvMsg, sizeof(recvMsg.mtext), 666, 0);
		printf("接收到p2的数据:\n%s", recvMsg.mtext);
		if (strcmp(recvMsg.mtext, "bye\n") == 0)
		{
			break;
		}
	}

	//删除消息队列
	msgctl(msgid, IPC_RMID, NULL);

	//子线程资源回收
	ret = pthread_join(thread, NULL);
	if (ret == 0)
	{
		printf("子线程资源回收成功\n");
	}

	return 0;
}