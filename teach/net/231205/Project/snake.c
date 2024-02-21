#include "snake.h"

//蛇的初始化
SNAKE queue_init()
{
	//定义蛇的结构体对象
	SNAKE s = malloc(sizeof(snake));
	if(NULL == s)
	{
		fprintf(stderr, "line[%d] malloc queue_init failed\n", __LINE__);
		return NULL;
	}
	
	//初始化指针
	s->first = NULL;
	s->last = NULL;
	
	//初始化数据
	s->lenth = 0;
	
	return s;
}

//创建新的节点
POINT queue_create_node(int x, int y)
{
	POINT n = malloc(sizeof(point));
	if(NULL == n)
	{
		fprintf(stderr, "line[%d] malloc queue_create_node failed\n", __LINE__);
		return NULL;
	}
	
	n->x = x;
	n->y = y;
	n->next = NULL;
	
	return n;
}

//蛇头移动---新增了一个节点
void queue_in(SNAKE q, POINT n)
{
	if(q->lenth == 0) //第一个数据入队
	{
		q->first = n;
		q->last = n;
		q->lenth++;
	}
	else
	{
		q->last->next = n;
		q->last = n;
		q->lenth++;
	}
}

//蛇尾移动---删除蛇头节点
void queue_out(SNAKE q)
{
	//判断是否是空队列
	if(q->lenth == 0)
		return;
	
	POINT tmp = q->first;
	q->first = q->first->next;
	
	q->lenth--;
	
	//判断是否是空队列
	if(q->lenth == 0)
		q->last = NULL;
	
	free(tmp);
	tmp = NULL;
}

//蛇的销毁
void queue_destroy(SNAKE q)
{
	while(q->first != q->last)
		queue_out(q);
	
	free(q->first);
	q->first = NULL;
	q->last = NULL;
	q->lenth--;
	
	free(q);
	q = NULL;
}