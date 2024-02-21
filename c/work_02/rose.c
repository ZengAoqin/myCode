#include <sys/types.h>
#include <sys/ipc.h>
#include <stdio.h>
#include <sys/msg.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>

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
	
	pid_t pid = fork();
	if(-1 == pid)
	{
		perror("创建子进程失败");
	}
	//父进程发送消息
	if(pid > 0)
	{
		//初始化消息结构体对象
		msgbuf sendMsg; //消息对象
		//初始化消息结构体对象
		sendMsg.mtype = 666; //指定消息类型为666
		//循环发送消息
		for(;;)
		{
			bzero(sendMsg.mtext, sizeof(sendMsg.mtext));
			printf("请输入发送给JACK的内容:\n");
			//scanf("%s", sendMsg.mtext);
			fgets(sendMsg.mtext, sizeof(sendMsg.mtext), stdin);

			//发送消息对象
			msgsnd(msgid, &sendMsg, sizeof(sendMsg), 0); //发送消息并且设置阻塞
			if(!strcmp(sendMsg.mtext, "quit\n")) //退出
				break;
		}
	}
	//子进程接受消息
	else if(pid == 0)
	{
		//定义接受消息
		msgbuf recvMsg; 
		//循环接收消息
		for(;;)
		{
			memset(&recvMsg, 0, sizeof(recvMsg));
			//接收消息
			msgrcv(msgid, &recvMsg, sizeof(recvMsg), 888, 0);
			printf("接收到JACK的数据:\n%s", recvMsg.mtext);
			if(!strcmp(recvMsg.mtext, "quit\n"))
			{
				break;
			}
		}
	}
	
	//删除消息队列
	msgctl(msgid, IPC_RMID, NULL);
	return 0;
}