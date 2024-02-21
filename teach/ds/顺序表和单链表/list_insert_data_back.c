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

pList create_node(int data)
{
	//定义一个节点
	pList newnode = malloc(sizeof(list));
	if(NULL == newnode)
	{
		printf("申请节点失败\n");
		return NULL;
	}
	
	newnode->data = data;
	newnode->pNext = NULL;
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

//从头部插入
void list_insert_head(pList head, int data)
{
	pList newNode = malloc(sizeof(list));
	if(NULL == newNode)
	{
		printf("申请节点失败\n");
		return;
	}
	newNode->data = data;
	newNode->pNext = head->pNext;
	head->pNext = newNode;
}

//从某个数据的后面插入数据
void list_insert_data_back(pList head, pList newnode, int data)
{
	pList p = NULL;
	p = head->pNext;
	
	while(p!= NULL)
	{
		if(p->data == data)
			break;
		
		p = p->pNext;
	}
	
	if(p == NULL)
	{
		printf("没有找到该节点\n");
		return;
	}
	
	newnode->pNext = p->pNext;
	p->pNext = newnode;
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
	list_insert_tailEx(head, 15);//head-15
	list_insert_tailEx(head, 3); //head-15-3
	list_insert_tailEx(head, 5); //head-15-3-5
	list_insert_head(head, 99);  //head-99-15-3-5
	list_insert_tailEx(head, 22); //head-99-15-3-5-22
	pList node = create_node(11);
	showList(head);
	list_insert_data_back(head, node, 5); //head-99-15-3-5-11-22
	printf("********************\n");
	showList(head);
	return 0;
}