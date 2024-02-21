#include <sys/types.h>
#include <sys/ipc.h>
#include <stdio.h>
#include <sys/msg.h>
#include <errno.h>
#include <string.h>

#define PATH "/home/softeem"
#define DATA 10

//定义了消息结构体
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
	
	//定义接受消息
	msgbuf recvMsg; 
	
	//循环接收消息
	for(;;)
	{
		memset(&recvMsg, 0, sizeof(recvMsg));
		//接收消息
		msgrcv(msgid, &recvMsg, sizeof(recvMsg), 666, 0);
		printf("指定接收消息666的数据%s", recvMsg.mtext);
		if(!strcmp(recvMsg.mtext, "quit\n"))
		{
			break;
		}
	}
	
	//删除消息队列
	msgctl(msgid, IPC_RMID, NULL);
	return 0;
}