#include "fun.h"

int main(int argc, char* argv[])
{
	//当前进程为精灵进程
	deamoin_int();
	
	//打开指定文件
	int text_fd = open(P_LOG, O_RDWR|O_CREAT|O_TRUNC, 0777);
	if(text_fd == -1)
	{
		perror("open error");
		return -1;
	}
	
	//创建有名管道
	fifo_file(P_PATH);
	//获取有名管道的文件描述符
	int fifo_fd = fifo_open(P_PATH);
	
	char buf[100];
	for(;;)
	{
		//清空数据
		bzero(buf, sizeof(buf));
		//从管道中读取数据
		read(fifo_fd, buf, sizeof(buf));
		//写入到指定文件
		write(text_fd, buf, strlen(buf));
	}
	
	return 0;
}