#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

void list_insert_tail(pList head, pList node)
{
	//p是为了找到最后一个节点
	pList p = head;
	while(p->pNext != NULL)
	{
		p = p->pNext;
	}
	
	p->pNext = node;
	node->pNext = NULL;
}

void list_insert_tailEx(pList head, pList node)
{
	//pTemp保存是最后一个节点
	pList pTemp = head;
	pList p = head->pNext;
	while(p!= NULL)
	{
		pTemp = p;
		p = p->pNext;
	}

	node->pNext = NULL;
	pTemp->pNext = node;
}

//从头部插入
void list_insert_head(pList head, pList node)
{
	if(NULL == node || NULL == head)
	{
		printf("不能传入空指针\n");
		return;
	}
	
	node->pNext = head->pNext;
	head->pNext = node;
}

//从某个数据的后面插入数据
void list_insert_data_back(pList head, pList newnode, pList node)
{
	if(NULL == node || NULL == head)
	{
		printf("不能传入空指针\n");
		return;
	}
	
	pList p = head->pNext;
	
	while(p!= NULL)
	{
		if(p == node)
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

//从某个数据的前面插入数据
void list_insert_data_front(pList head, pList newnode, pList node)
{
	pList p = head;
	pList q = p->pNext;
	
	while(q != NULL)
	{
		if(q == node)
		{
			break;
		}
		p = q;
		q = p->pNext;
	}
	
	if(q == NULL)
	{
		printf("没有找到该节点\n");
		return;
	}
	
	p->pNext = newnode;
	newnode->pNext = q;
}

bool list_find(const pList head, pList node)
{
	if(NULL == node || NULL == head)
	{
		printf("不能传入空指针\n");
		return false;
	}
	
	pList p = head->pNext;
	
	while(p != NULL)
	{
		if(p == node)
			break;
		
		p = p->pNext;
	}
	
	return (p != NULL) ? true:false;
}

void list_delete(pList head, pList node)
{
	pList p = head;
	pList q = p->pNext;
	
	while(q != NULL)
	{
		if(q == node)
			break;
		
		p = q;
		q = p->pNext;
	}
	
	//没有找到相关节点
	if(q == NULL)
		return;
	
	p->pNext = q->pNext;
	
	q->pNext = NULL;
	free(q);
	q = NULL;
}

void list_modify(pList head, int newData, pList oldNode)
{
	//先找到对应的节点
	if(list_find(head, oldNode))
	{
		//修改数据域
		oldNode->data = newData;
	}
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
	pList node1 = create_node(15);
	list_insert_tailEx(head, node1);//head-15
	pList node2 = create_node(3);
	list_insert_tailEx(head, node2); //head-15-3
	pList node3 = create_node(5);
	list_insert_tailEx(head, node3); //head-15-3-5
	
	pList node4 = create_node(99);
	list_insert_head(head, node4);  //head-99-15-3-5
	pList node = create_node(11);
	showList(head);
	list_insert_data_back(head, node, node3); //head-99-15-3-5-11-null
	printf("********************\n");
	showList(head);
	
	list_modify(head, 22, node);
	printf("********************\n"); //head-99-15-3-5-22-null
	showList(head);
	/*
	pList node2 = create_node(33);
	list_insert_data_front(head, node2, 3); //head-99-15-33-3-5-11-22
	printf("********************\n");
	showList(head);
	pList p2 = list_find(head, 5);
	if(p2 != NULL)
		printf("data = %d\n", p2->data);
	
	list_delete(head, 33); //head-99-15-3-5-11-22
	printf("********************\n");
	printf("********************\n");
	showList(head);
	
	list_modify(head, 6, 3);
	printf("********************\n");
	printf("********************\n");
	showList(head);
	*/
	return 0;
}