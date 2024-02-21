#include "fun.h"

//精灵进程的初始化
int deamoin_int()
{
	//1.忽略SIGHUP信号	----SIGHUP是终端关闭的信号，放置因为终端关闭而结束进程
	signal(SIGHUP, SIG_IGN);
	
	//2.创建子进程，父进程退出---父进程是bash终端的第一个进程，意味着是进程组组长
	pid_t pid = fork(); //创建子进程
	if(pid > 0) exit(0); //当前进程
	
	//3.创建子进程的新会话----创建新会话的进程不能是进程组组长setid
	int ret = setsid();
	if(ret == -1) 
	{
		perror("setsid error");
		exit(-1);
	}
	
	//4.创建子进程,退出父进程---当前父进程是一个前一个子进程,与原终端有关系，需要结束
	pid = fork();
	if(pid > 0) //当前进程
		exit(0); //父进程退出
	
	//5.子进程创建新会话----新的子进程会创建会话组，称为新组长setpgrp
	setpgrp(); //set process group
	
	//6.屏蔽文件权限----为了精灵进程不受文件影响(重置文件权限掩码)
	umask(0);
	
	//7.关闭所有的文件描述符----把进程的所有默认打开文件关闭
	int maxfd = sysconf(_SC_OPEN_MAX);  //最大文件描述符
	for(int i = 0; i < maxfd; i++)
	{
		close(i);
	}
	
	//8.修改精灵进程运行路径到根目录---放置目录被误删之后导致精灵进程结束
	chdir("/");
	
	return 0;
}

//有名管道文件创建
int fifo_file(const char* path)
{
	//判断管道文件是否存在
	if(access(path, F_OK) != 0) //管道文件不存在
	{
		//创建有名管道文件
		int ret = mkfifo(path, 0777);
		if(ret == -1) //判断创建是否失败
		{
			perror("mkfifo faied");
			return -1;
		}
		printf("有名管道文件创建成功\n");
	}
	else
	{
		printf("有名管道文件存在\n");
	}
}

//打开有名管道文件
int fifo_open(const char* path)
{
	//打开有名管道文件
	int fd = open(path, O_RDWR);
	if(fd == -1)
	{
		perror("open fifo file failed");
	}
	
	return fd;
}

//删除管道文件
int delete_fifo(const char* path)
{
	int ret = unlink(path);
	if(-1 == ret)
	{
		perror("unlink failed");
	}
	
	return ret;
}