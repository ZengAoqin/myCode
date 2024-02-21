#ifndef _SNAKE_H
#define _SNAKE_H

#include "lcd.h"
#include "ts.h"
#include <stdlib.h>
#include <stdio.h>

//蛇的节点结构体
typedef struct point
{
	//数据域
	int x;					//x轴坐标
	int y;					//y轴坐标
	//指针域
	struct point* next;		//指向下一个节点的指针
}point, *POINT;

//蛇的控制结构体
typedef struct snake
{
	POINT first;			//蛇尾 
	POINT last;				//蛇头
	int lenth;				//蛇身长度
}snake, *SNAKE;

//蛇的初始化
extern SNAKE queue_init();
//创建新的节点
extern POINT queue_create_node(int x, int y);
//蛇头移动---新增了一个节点
extern void queue_in(SNAKE q, POINT n);
//蛇尾移动---删除蛇尾节点
extern void queue_out(SNAKE q);
//蛇的销毁
extern void queue_destroy(SNAKE q);

#endif