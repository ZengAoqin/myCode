/*
p1进程创建子线程专门用于发送消息，p1主线程用于接收消息
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

//子线程专门用于发送消息
void* send_msg(void* arg)
{
	int* p = (int*)arg;
	msg sendmsg;
	sendmsg.mtype = 666;
	//发送消息
	for(;;)
	{
		//清空发送内容
		bzero(sendmsg.mtext, sizeof(sendmsg.mtext));
		printf("请输入你想对p2说的话\n");
		fgets(sendmsg.mtext, sizeof(sendmsg.mtext), stdin);
		msgsnd(*p, &sendmsg, strlen(sendmsg.mtext), 0); //0代表阻塞
		if(strcmp(sendmsg.mtext, "byebye\n") == 0)
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
	int ret = pthread_create(&thread, NULL, send_msg, (void*)&msgid);
	if(ret != 0)
	{
		perror("pthread_create failed");
		return -1;
	}
	
	msg recvMsg;
	//主线程接收消息
	for(;;)
	{
		//清空数据
		bzero(&recvMsg, sizeof(recvMsg));
		//接收消息
		msgrcv(msgid, &recvMsg, sizeof(recvMsg), 888, 0);
		printf("当前读取的内容为：%s", recvMsg.mtext);
		if(strcmp(recvMsg.mtext, "byebye\n") == 0)
			break;
	}
	
	//回收子线程资源
	pthread_join(thread, NULL);
	
	//删除消息队列资源
	msgctl(msgid, IPC_RMID, NULL);
	return 0;
}

