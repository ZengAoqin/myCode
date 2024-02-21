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

void list_insert_tail(pList head, int data)
{
	//p是为了找到最后一个节点
	pList p = head;
	while(p->pNext != NULL)
	{
		p = p->pNext;
	}
	
	//定义一个节点头
	pList newNode = malloc(sizeof(list));
	newNode->data = data;
	newNode->pNext = NULL;
	
	p->pNext = newNode;
}

void list_insert_tailEx(pList head, int data)
{
	//pTemp保存是最后一个节点
	pList pTemp = head;
	pList p = head->pNext;
	while(p!= NULL)
	{
		pTemp = p;
		p = p->pNext;
	}
	
	//定义一个节点头
	pList newNode = malloc(sizeof(list));
	newNode->data = data;
	newNode->pNext = NULL;
	
	pTemp->pNext = newNode;
}

void showList(pList head)
{
	if(head->pNext == NULL)
	{
		printf("没有元素\n");
		return;
	}
	
	printf("head-");
	pList p = head->pNext;
	for(; p != NULL; p = p->pNext)
	{
		printf("%d-", p->data);
	}
	printf("null\n");
}

int main(int argc,char* argv[])
{
	pList head = list_init();
	showList(head);
	list_insert_tailEx(head, 15);
	list_insert_tailEx(head, 3);
	list_insert_tailEx(head, 5);
	showList(head);
	return 0;
}