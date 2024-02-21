#include <sys/types.h>
#include <sys/ipc.h>
#include <stdio.h>
#include <sys/msg.h>
#include <errno.h>
#include <string.h>

#define PATH "/home/softeem"
#define DATA 10

typedef struct msgbuf 
{
	long   mtype;       	/*消息类型*/
    char   mtext[50];    	/*消息内容*/
}msgbuf;

int main(int argc, char** argv)
{
	//申请系统key值
	key_t key = ftok(PATH, DATA);
	if(-1 == key)
	{
		perror("ftok failed");
		return -1;
	}
	
	//申请消息队列
	int msgid = msgget(key, IPC_CREAT|IPC_EXCL|0777);
	if(-1 == msgid && errno == EEXIST) //消息队列存在而产生的error
	{
		//直接打开消息队列
		msgid = msgget(key, 0666);
	}
	else if(-1 == msgid)
	{
		perror("msgget failed");
		return -1;
	}
	
	//int msgsnd(int msqid, const void *msgp, size_t msgsz, int msgflg);
	//初始化消息结构体对象
	msgbuf sendMsg1; //消息对象1
	msgbuf sendMsg2; //消息对象2
	//初始化消息结构体对象1
	sendMsg1.mtype = 666;
	strcpy(sendMsg1.mtext, "what's up666");
	
	//初始化消息结构体对象2
	sendMsg2.mtype = 777;
	strcpy(sendMsg2.mtext, "helloworld");
	
	msgsnd(msgid, &sendMsg1, sizeof(sendMsg1), 0); //发送消息并且设置阻塞
	msgsnd(msgid, &sendMsg2, sizeof(sendMsg2), 0); //发送消息并且设置阻塞
	
	//获取消息队列属性
	//int msgctl(int msqid, int cmd, struct msqid_ds *buf);
	//IPC_STAT
	struct msqid_ds ms_ds;
	msgctl(msgid, IPC_STAT, &ms_ds);
	printf("msg_qnum:%ld\n", ms_ds.msg_qnum);
	return 0;
}