#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

extern char** environ; //全局变量，外部声明，用于存放系统中环境参数（用于存放env这个命令的环境参数）

int main(int argc, char* argv[])
{
	//打印数据
	for(int i = 0; environ[i] != NULL; i++)
	{
		printf("%s\n", environ[i]);
		printf("====================%s\n", argv[0]);
		printf("++++++++++++++++++++%s\n", argv[1]);
		printf("********************%s\n", argv[2]);
	}
	return 0;
}