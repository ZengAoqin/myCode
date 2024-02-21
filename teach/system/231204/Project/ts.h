#ifndef _TS_H
#define _TS_H

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <linux/input.h>
#include <string.h>

#define INPUT_EVENT "/dev/ubuntu_event"

//触摸屏的初始化
extern int ts_init();
//触摸屏的销毁
extern void ts_destroy(int fd);
//获取按下的坐标
extern void get_abs(int* x,int* y, int fd);

#endif