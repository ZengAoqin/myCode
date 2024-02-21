#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

bool double_list_find(pDoubleList head, pDoubleList node)
{
	if(head == NULL || node == NULL)
	{
		printf("不能传空指针\n");
		return false;
	}
	
	pDoubleList p = head->pNext;
	while(p != NULL)
	{
		if(p == node)
		{
			break;
		}
		p = p->pNext;
	}
	
	return (p != NULL) ? true:false;
}


void double_list_insert_node_front(pDoubleList head, pDoubleList node,pDoubleList newNode)
{
	if(node == NULL || newNode == NULL)
	{
		printf("节点指针不能为空\n");
		return;
	}
	
	if(!double_list_find(head, node))
	{
		return;
	}
	
	newNode->pRev = node->pRev;
	newNode->pNext = node; 
	node->pRev->pNext = newNode;
	node->pRev = newNode;

}

void double_list_insert_node_back(pDoubleList head, pDoubleList node,pDoubleList newNode)
{
	if(node == NULL || newNode == NULL)
	{
		printf("节点指针不能为空\n");
		return;
	}
	
	if(!double_list_find(head, node))
	{
		return;
	}
	
	newNode->pNext = node->pNext;
	newNode->pRev = node;
	if(node->pNext != NULL)
		node->pNext->pRev = newNode;

	node->pNext = newNode;
}

void double_list_delete(pDoubleList head, pDoubleList node)
{
	if(node == NULL || head == NULL)
	{
		printf("节点指针不能为空\n");
		return;
	}
	
	if(!double_list_find(head, node))
	{
		return;
	}
	
	node->pRev->pNext = node->pNext;
	if(node->pNext != NULL)
		node->pNext->pRev = node->pRev;
	node->pRev = NULL;
	node->pNext = NULL;
	free(node);
	node = NULL;
}

void double_list_modify(pDoubleList head, pDoubleList node,int data)
{
	if(node == NULL || head == NULL)
	{
		printf("节点指针不能为空\n");
		return;
	}
	
	if(!double_list_find(head, node))
	{
		return;
	}
	
	node->data = data;
}

//显示双向循环链表的数据
void showDoubleListCircul(pDoubleList head)
{
	pDoubleList p = head;
	if(p == NULL)
	{
		printf("不能传空指针\n");
		return;
	}
	
	printf("Double head-");
	
	p = p->pNext;
	while(p != head)
	{
		printf("%d-", p->data);
		p = p->pNext;
	}
	printf("Double head\n");
}

void double_list_circul(pDoubleList head)
{
	if(head == NULL)
	{
		printf("节点指针不能为空\n");
		return;
	}
	
	pDoubleList p = head; 
	
	//p找到链表的最后一个节点
	while(p->pNext != NULL)
	{
		p = p->pNext;
	}
	
	p->pNext = head;
	head->pRev = p;
}


void double_list_No_Circul(pDoubleList head)
{
	if(head == NULL)
	{
		printf("节点指针不能为空\n");
		return;
	}
	
	pDoubleList p = head; 
	
	//p找到链表的最后一个节点
	while(p->pNext != head)
	{
		p = p->pNext;
	}
	
	p->pNext = NULL;
	head->pRev = NULL;
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

	pDoubleList node3 = create_node(25);
	double_list_insert_tail(head, node3); //Double head-13-3-25-NULL
	printf("*******************\n");
	showDoubleList(head);
	
	pDoubleList node4 = create_node(24);
	if(double_list_find(head, node4))
	{
		printf("找到该节点 %d\n", node4->data);
	}
	else
	{
		printf("找不到该节点 \n");
	}
	
	pDoubleList node5 = create_node(77);
	double_list_insert_node_front(head, node2, node5); //Double head-77-13-3-25-NULL
	printf("*******************\n");
	showDoubleList(head);
	
	double_list_insert_node_back(head, node3, node4); //Double head-77-13-3-25-24-NULL
	printf("*******************\n");
	showDoubleList(head);
	
	double_list_delete(head, node5); //Double head-13-3-25-24-NULL
	printf("*******************\n");
	showDoubleList(head);
	
	double_list_delete(head, node4); //Double head-13-3-25-NULL
	printf("*******************\n");
	showDoubleList(head);
	
	double_list_modify(head, node1, 1);//Double head-13-1-25-NULL
	printf("*******************\n");
	showDoubleList(head);
	
	double_list_circul(head);//Double head-13-1-25-Double head
	showDoubleListCircul(head);
	
	double_list_No_Circul(head);
	printf("*******************\n");
	showDoubleList(head);
	return 0;
}










