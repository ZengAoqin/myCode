#include <stdio.h>
#include <stdlib.h>

//定义单向链表
typedef struct doubleList
{
	//数据域
	int data;
	//指针域
	struct doubleList* pRev;	//指向前一个节点
	struct doubleList* pNext; //指向下一个节点
}doubleList,*pDoubleList;

//初始化双向链表
pDoubleList list_init()
{
	//定义一个节点头
	pDoubleList head = malloc(sizeof(doubleList));
	if(NULL == head)
	{
		printf("申请头节点失败\n");
		return NULL;
	}
	//初始化数据域
	head->data = 0;
	//初始化指针域
	head->pRev = NULL;
	head->pNext = NULL;
	return head;
}

//创建双向链表的节点
pDoubleList create_node(int data)
{
	//定义一个节点
	pDoubleList newnode = malloc(sizeof(doubleList));
	if(NULL == newnode)
	{
		printf("申请节点失败\n");
		return NULL;
	}
	
	newnode->data = data;
	newnode->pRev = NULL;
	newnode->pNext = NULL;
	
	return newnode;
}

//判断双向链表是否是空链表
/*
返回值: 0: 空链表
		1：不是空链表
		-1： 链表头为空
*/
int isEmpty(pDoubleList head)
{
	int nRet = -1;
	if(head != NULL)
	{
		if(head->pNext == NULL)
		{
			nRet = 0;
		}
		else
		{
			nRet = 1;
		}
	}
	else
	{
		printf("链表头为空\n");
	}
	
	return nRet;
}

void double_list_insert_head(pDoubleList head, pDoubleList node)
{
	int nRet = isEmpty(head);
	if(nRet == -1)
	{
		return;
	}
	else if(nRet == 0)
	{
		node->pNext = NULL;
		node->pRev = head;
		head->pNext = node;
	}
	else
	{
		head->pNext->pRev = node;
		node->pNext = head->pNext;
		node->pRev = head;
		head->pNext = node;
	}
}

void double_list_insert_tail(pDoubleList head, pDoubleList node)
{
	int nRet = isEmpty(head);
	if(nRet == -1)
	{
		return;
	}
	else
	{
		pDoubleList p = head;
		while(p->pNext != NULL)
		{
			p = p->pNext;
		}
		
		p->pNext = node;
		node->pRev  = p;
		node->pNext = NULL;
	}
}

//显示双向链表的数据
void showDoubleList(pDoubleList head)
{
	pDoubleList p = head;
	if(p == NULL)
	{
		printf("不能传空指针\n");
	}
	else
	{
		p = p->pNext;
		printf("Double head-");
		while(p != NULL)
		{
			printf("%d-", p->data);
			p = p->pNext;
		}
		printf("NULL\n");
	}
}

pDoubleList double_list_find(pDoubleList head, int data)
{
	if(head == NULL)
	{
		printf("不能传空指针\n");
		return NULL;
	}
	pDoubleList p = head->pNext;
	if(p == NULL)
	{
		printf("双向空链表\n");
		return NULL;
	}

	while(p != NULL)
	{
		if(p->data == data)
		{
			break;
		}
		p = p->pNext;
	}
	
	if(p == NULL)
	{
		printf("没有找到数据\n");
		return NULL;
	}
	
	return p;
}


int main(int argc, char* argv[])
{
	pDoubleList head = list_init();
	showDoubleList(head);
	
	pDoubleList node1 = create_node(3);
	double_list_insert_head(head, node1);
	pDoubleList node2 = create_node(13);
	double_list_insert_head(head, node2); //Double head-13-3-NULL
	printf("*******************\n");
	showDoubleList(head);

	pDoubleList node3 = create_node(24);
	double_list_insert_tail(head, node3); //Double head-13-3-24-NULL
	printf("*******************\n");
	showDoubleList(head);
	
	pDoubleList p = double_list_find(head, 24);
	if(p != NULL)
	{
		printf("找到该节点 %d\n", p->data);
	}
	return 0;
}










