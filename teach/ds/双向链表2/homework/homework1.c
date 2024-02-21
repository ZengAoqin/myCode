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

//从某个数据的前面插入数据
void list_insert_data_front(pList head, pList newnode, int data)
{
	/*
	pList p = head;
	while(p->pNext != NULL)
	{
		if(p->pNext->data == data)
		{
			break;
		}
		
		p = p->pNext;
	}
	
	if(p->pNext == NULL)
	{
		printf("没有找到该节点\n");
		return;
	}
	
	newnode->pNext = p->pNext;
	p->pNext = newnode;
	*/
	pList p = head;
	pList q = p->pNext;
	
	while(q != NULL)
	{
		if(q->data == data)
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

pList list_find(const pList head, int num)
{
	pList p = head->pNext;
	
	while(p != NULL)
	{
		if(p->data == num)
			break;
		
		p = p->pNext;
	}
	
	return p;
}

void list_delete(pList head, int num)
{
	pList p = head;
	pList q = p->pNext;
	
	while(q != NULL)
	{
		if(q->data == num)
			break;
		
		p = q;
		q = p->pNext;
	}
	
	//没有找到相关节点
	if(q == NULL)
		return;
	
	p->pNext = q->pNext;
	
	free(q);
	q = NULL;
}

void list_modify(pList head, int newData, int oldData)
{
	//先找到对应的节点
	pList p = list_find(head, oldData);
	
	if(p != NULL)
	{
		//修改数据域
		p->data = newData;
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

pList list_disconnect(pList head, int num)
{
	pList p = head;
	pList q = p->pNext;
	
	while(q != NULL)
	{
		if(q->data == num)
			break;
		
		p = q;
		q = p->pNext;
	}
	
	//没有找到相关节点
	if(q == NULL)
		return NULL;
	
	p->pNext = q->pNext;
	
	return q;
}

/*
1、有2个单向链表，把它们合并成一个有序链表
例如：head->1->3->5->7->9
	head->2->4->6->8->10
	
	合并之后： head->1->2->3->4->5->6->7->8->9->10
*/
void homework1()
{
	//定义2个链表
	pList head1 = list_init(); //奇数链表
	pList head2 = list_init(); //偶数链表
	
	for(int i = 1; i < 10; i+=2) //奇数赋值
	{
		list_insert_tail(head1, i);
	}
	
	for(int i = 2; i <= 18; i+=2) //偶数赋值
	{
		list_insert_tail(head2, i);
	}
	
	showList(head1);
	showList(head2);
	
	pList p1 = head1->pNext;
	pList p2 = head2->pNext;
	pList p = NULL;
	
	while(p1 != NULL && p2 != NULL)
	{
		if(p2->data < p1->data)
		{
			p = list_disconnect(head2, p2->data);
			list_insert_data_front(head1, p, p1->data);
			p2 = head2->pNext;
		}
		else
		{
			p1 = p1->pNext;
		}
	}
	
	if(p1 == NULL)
	{
		p1 = head1;
		while(p1->pNext != NULL)
		{
			p1 = p1->pNext;
		}
		
		while(p2 != NULL)
		{
			p = list_disconnect(head2, p2->data);
			list_insert_data_back(head1, p, p1->data);
			p1 = p1->pNext;
			p2 = head2->pNext;
		}
	}
	
	
	showList(head1);
}

int main(int argc,char* argv[])
{
	homework1();
	return 0;
}