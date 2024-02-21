#ifndef _LCD_H
#define _LCD_H

#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>
#include <linux/fb.h>
#include <stropts.h>

#define LCD_PATH "/dev/ubuntu_lcd"
#define LCD_SIZE 800*480*4
#define LCD_WIDTH 800					//LCD模拟器的宽度
#define LCD_HEIGH 480					//LCD模拟器的高度

//定义结构体描述设备
typedef struct lcd
{
	int lcdfd;							//lcd文件描述符
	unsigned int* mmp;					//内存映射地址
}lcd, *LCD;

//lcd设备初始化
extern LCD lcd_init();
//lcd设备销毁
extern void lcd_destroy(LCD lcd_device);
//图片的显示
extern void showBmp(int x, int y, const char* bmpName, LCD lcd_device);
//清空屏幕
extern void clearLCD(LCD lcd_device, unsigned int color);
//显示正方形
extern void show_square(LCD lcd_device, int x, int y, int lenth, int color);

#endif