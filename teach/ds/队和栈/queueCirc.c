#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

//定义顺序队列
typedef struct queue
{
	int* data;		//数据域
	int length;		//队列的长度
	int rear;		//队列队尾
	int front;		//队列队首
}qu, *pqu;

//初始化队列
pqu queue_init(int size)
{
	//定义队列对象
	pqu queue = malloc(sizeof(qu));
	if(NULL == queue)
	{
		printf("申请队列失败\n");
		return NULL;
	}
	
	//队列初始化
	queue->data = malloc(sizeof(int)*size); //申请数组存储空间
	if(NULL == queue->data)
	{
		printf("申请数组空间失败\n");
		free(queue);
		queue = NULL;
		return NULL;
	}
	queue->front = 0; 		// 队列队首
	queue->rear = 0; 		// 队列队尾
	queue->length = size;   // 队列的长度
	
	return queue;
}

//判断是否是空队列
bool queue_empty(pqu queue)
{
	return queue->rear == queue->front ? true:false;
}

//判断是否是满队列
bool queue_full(pqu queue)
{
	return (queue->rear+1)%(queue->length) == queue->front ? true:false;
}

//入队列
void queue_push(pqu queue, const int* pNum)
{
	//判断是否是满队列
	if(queue_full(queue))
	{
		printf("队列已满\n");
		return;
	}
	
	//入队元素
	//数据域赋值
	queue->data[queue->rear] = *pNum;
	printf("入队列数据%d\n", queue->rear);
	//队伍增长了
	queue->rear++;
	queue->rear = queue->rear%queue->length;
}

//出队列
void queue_pop(pqu queue, int* pNum)
{
	//判断队列是否是空队列
	if(queue_empty(queue))
	{
		printf("空队列\n");
		return;
	}
	
	//出队数据
	*pNum = queue->data[queue->front];
	//队头向后移动一位
	queue->front++;
	queue->front = queue->front%queue->length;
}

int main(int argc, char* argv[])
{
	//初始化队列
	pqu queue = queue_init(10);
	
	int num;
	
	//入队元素
	printf("入队\n");
	for(int i = 1; i <= 10; i++)
	{
		num = i*10;
		queue_push(queue, &num);
		printf("入队数据%d \n", num);
	}
	//printf("\n");
	
	printf("出队\n");
	for(int i = 1; i <= 10; i++)
	{
		queue_pop(queue, &num);
		printf("出队数据%d \n", num);
	}
	//printf("\n");
	
	//入队元素
	printf("入队\n");
	for(int i = 1; i <= 10; i++)
	{
		num = i*10;
		queue_push(queue, &num);
		printf("入队数据%d \n", num);
	}
	
	printf("出队\n");
	for(int i = 1; i <= 10; i++)
	{
		queue_pop(queue, &num);
		printf("出队数据%d \n", num);
	}
	
	return 0;
}


