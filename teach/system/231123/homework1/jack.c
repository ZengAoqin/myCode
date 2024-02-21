#include <sys/types.h>
#include <sys/ipc.h>
#include <stdio.h>
#include <sys/msg.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>

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
	
	//初始化消息结构体对象
	msgbuf Msg; //消息对象
	pid_t pid = fork();
	if(-1 == pid)
	{
		perror("fork failed");
		return -1;
	}
	
	if(pid > 0) //当前进程发送666消息类型
	{
		//初始化消息结构体对象
		Msg.mtype = 666; //指定消息类型为666 
		//循环发送消息
		for(;;)
		{
			bzero(Msg.mtext, sizeof(Msg.mtext));
			printf("请输入发送的内容\n");
			//scanf("%s", sendMsg.mtext);
			fgets(Msg.mtext, sizeof(Msg.mtext), stdin);

			//发送消息对象
			msgsnd(msgid, &Msg, sizeof(Msg), 0); //发送消息并且设置阻塞
			if(!strcmp(Msg.mtext, "quit\n")) //退出
			{
				kill(pid, 9); //杀死子进程
				break;
			}
		}
	}
	else if(pid == 0) //子进程
	{
		//循环接收消息
		for(;;)
		{
			memset(&Msg, 0, sizeof(Msg));
			//接收指定消息类型为777
			msgrcv(msgid, &Msg, sizeof(Msg), 777, 0);
			printf("指定接收消息666的数据%s", Msg.mtext);
			if(!strcmp(Msg.mtext, "quit\n"))
			{
				kill(getppid(), 9); //杀死父进程
				break;
			}
		}
	}
	
	//删除消息队列
	msgctl(msgid, IPC_RMID, NULL);
	
	return 0;
}