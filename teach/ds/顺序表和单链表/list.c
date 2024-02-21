#include <stdio.h>
#include <stdlib.h>

//定义单向链表
typedef struct list
{
	//数据域
	int data;
	//指针域
	struct list* pNext; //指向下一个节点
}list,*pList;


pList list_init()
{
	//定义一个节点头
	pList head = malloc(sizeof(list));
	if(NULL == head)
	{
		printf("申请头节点失败\n");
		return NULL;
	}
	//初始化数据域
	head->data = 0;
	//初始化指针域
	head->pNext = NULL;
	return head;
}

int main(int argc,char* argv[])
{
	return 0;
}