/*1.编写一个程序，利用多进程以及无名管道，实现下述命令的执行效果：ls | wc -w*/

#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>


int main(int argc, char* argv[])
{
	//无名管道数组 fd[0] read端 fd[1] write端
	int fd[2];
	//创建无名管道
	int ret = pipe(fd);
	if(-1 == ret)
	{
		perror("pipe failed");
		return -1;
	}
	
	//标准输入 0，标准输出 1，标准错误 2
	pid_t pid = fork();
	if(pid > 0) //当前进程
	{
		close(fd[1]);  //关闭write端
		//将管道的里面的read端内容重定向到标准输入，就是0
		dup2(fd[0],0);
		printf("父进程 1\n");
		//执行函数族中的execlp
		execlp("wc", "wc", "-w", NULL); //通过wc -w进行统计
		printf("父进程 2\n");
		printf("父进程 3\n");
	}
	else if(pid == 0) //子进程
	{
		//printf("子进程 1\n");
		//printf("子进程 2\n");
		sleep(1);
		close(fd[0]);  //关闭read端
		//由于ls的结果输出在屏幕，就是在标准输出，代表的结果是1
		//需要将ls的结果输入到管道，也就是将屏幕显示的内容重定向屏幕，就是重定向到1
		dup2(fd[1], 1);
		printf("子进程3\n");
		//执行函数族中的execl
		execl("/bin/ls", "ls", NULL); //ls命令
		printf("子进程 3\n");
	}
	return 0;
}

#if 0
int main (int argc,char* argv[])
{
	//无名管道数组 fd[0] r fd[1] w
	int fd[2];
	//创建无名管道
	int ret = pipe(fd);
	if(-1 == ret)
	{
		perror("pipe failed");
		return -1;
	}
	char buf[100];
	//标准输入是 0 标准输出 1 标准错误 2
	pid_t pid = fork();
	if(pid > 0)//当前进程
	{
		close(fd[1]);	//关闭write端
		//将管道里面的read端内容重定向到标准输入，就是0
		dup2(fd[0],0);
		printf("父进程1\n");
		//read(fd[0],buf,sizeof(buf));
		//printf("%s",buf);
		//执行函数族中的execlp
		//printf("%ld\n",stdout);
		execlp("wc","wc","-w",NULL);//通过wc -w进行统计
	}
	else if(pid == 0)//子进程
	{
		//printf("子进程1\n");
		close(fd[0]);	//关闭read端
		//由于ls的结果输出在屏幕，就是在标准输出，代表结果是1
		//需要将ls的结果输入到管道，也就是将屏幕显示的内容重定向屏幕，就是重定向到1
		dup2(fd[1],1);
		//printf("子进程 2\n");
		printf("子进程 3\n");
		printf("子进程 4\n");
		//执行函数族execl
		execl("/bin/ls","ls",NULL);
	}
	return 0;
}
#endif
