/*
p2进程创建子线程专门用于接收消息，p2主线程用于发送消息
*/

#include <stdio.h>
#include <pthread.h>
#include <sys/msg.h>
#include <errno.h>
#include <string.h>

//定义消息结构体
typedef struct mymsg
{
	long   mtype;       	/* 消息类型 */
    char   mtext[50];    	/* 消息内容 */
}msg,*MSG;

//子线程专门用于接收消息
void* recv_msg(void* arg)
{
	int* p = (int*)arg;
	msg recvMsg;
	//循环接收消息
	for(;;)
	{
		//清空接收消息的内容
		bzero(recvMsg.mtext, sizeof(recvMsg.mtext));
		msgrcv(*p, &recvMsg, sizeof(recvMsg), 666, 0);
		printf("当前读取的内容为：%s", recvMsg.mtext);
		if(strcmp(recvMsg.mtext, "byebye\n") == 0)
		{
			break;
		}
	}
	
	pthread_exit(NULL); //子线程退出
}

int main(int argc, char* argv[])
{
	//创建key值
	key_t msgkey = ftok(".", 1);
	if(-1 == msgkey)
	{
		perror("ftok failed");
		return -1;
	}
	
	//创建消息id
	int msgid = msgget(msgkey, IPC_CREAT|IPC_EXCL|0666);
	if(msgid == -1 && errno == EEXIST)
	{
		msgid = msgget(msgkey, 0666);
	}
	else if(msgid == -1)
	{
		perror("msgget failed");
		return -1;
	}
	
	//创建子线程
	pthread_t thread;
	int ret = pthread_create(&thread, NULL, recv_msg, (void*)&msgid);
	if(ret != 0)
	{
		perror("pthread_create failed");
		return -1;
	}
	
	msg sendMsg;
	sendMsg.mtype = 888;
	//主线程发送消息
	for(;;)
	{
		//清空数据
		bzero(&sendMsg.mtext, sizeof(sendMsg.mtext));
		printf("请输入你想对p1说的话\n");
		fgets(sendMsg.mtext, sizeof(sendMsg.mtext), stdin);
		msgsnd(msgid, &sendMsg, strlen(sendMsg.mtext), 0); //0代表阻塞
		if(strcmp(sendMsg.mtext, "byebye\n") == 0)
		{
			break;
		}
	}
	
	//回收子线程资源
	pthread_join(thread, NULL);
	
	//删除消息队列资源
	msgctl(msgid, IPC_RMID, NULL);
	return 0;
}