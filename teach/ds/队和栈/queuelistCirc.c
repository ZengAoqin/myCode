#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

//节点设计
struct node
{
	int data;			//数据域
	struct node* next;	//指针域
};

typedef struct queuelist
{
	struct node* front;		//队首
	struct node* rear;		//队尾
	int length;				//队列长度
}ql, *pql;

//链式队列初始化
pql queue_list_init()
{
	//申请链式队列对象
	pql queue = malloc(sizeof(ql));
	if(NULL == queue)
	{
		printf("get queue failed\n");
		return NULL;
	}
	
	//队首指针和队尾指针指向NULL
	queue->front = NULL;
	queue->rear  = NULL;
	queue->length = 0;
	
	return queue;
}

//链式队列入队
void queue_list_push(pql queue, int data)
{
	//申请新节点 struct node*
	struct node* newNode = malloc(sizeof(struct node));
	if(NULL == newNode)
	{
		printf("get new node failed\n");
		return;
	}
	
	//新节点数据初始化 数据域和指针域
	newNode->data = data;
	newNode->next = NULL;
	
	//将新节点插入到队列尾部
	if(NULL == queue->rear) //队尾为空
	{
		//一个人站队，队尾是自己，队首也是自己
		queue->rear = newNode;
		queue->front = newNode;
		newNode->next = newNode;
	}
	else
	{
		queue->rear->next = newNode; 	//旧队尾下一个是新节点
		queue->rear = newNode;			//新节点设置为队尾
		newNode->next = queue->front;   //新节点的下一个节点指向队首
	}
	
	//队列长度自增
	queue->length++;
	printf("入队成功，入队数据%d，此时队列长度%d\n", newNode->data, queue->length);
}

//队列为空判断
bool isEmpty(pql queue)
{
	return queue->length == 0 ? true:false;
	//return queue->front == NULL ? true :false;
	//return queue->rear == NULL ? true :false;
}

//链式队列出队
void queue_list_pop(pql queue, int* data)
{
	//判断是否是空队列
	if(isEmpty(queue))
	{
		printf("队列为空\n");
		return;
	}
	
	//定义临时节点保存队首，方便释放
	struct node* tmp = queue->front;
	//指定零时节点的next指向节点为新的队首
	queue->front = tmp->next;
	//获取零时节点的数据
	*data = tmp->data;
	
	//释放零时节点
	tmp->next = NULL;
	free(tmp);
	tmp = NULL;
	
	//队列长度自减
	queue->length--;
	printf("出队成功，出队数据%d，此时队列长度%d\n", *data, queue->length);
}

int main(int argc, char* argv[])
{
	pql queue = queue_list_init();
	
	//入队
	for(int i = 1; i <= 5; i++)
	{
		queue_list_push(queue, i*20);
	}
	
	int data;
	printf("head-");
	while(!isEmpty(queue))
	{
		queue_list_pop(queue, &data);
	}
	printf("-head\n");
	return 0;
}









