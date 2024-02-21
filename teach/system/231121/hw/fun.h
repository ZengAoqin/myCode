#ifndef _FUN_H
#define _FUN_H

#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <string.h>
#include <fcntl.h>


#define P_PATH  "/home/softeem/myfifo"    	//有名管道文件路径
#define P_LOG   "/home/softeem/log.txt"		//写入指定的文件

//精灵进程的初始化
extern int deamoin_int(void);
//有名管道文件创建
extern int fifo_file(const char* path);
//打开有名管道文件
extern int fifo_open(const char* path);

#endif