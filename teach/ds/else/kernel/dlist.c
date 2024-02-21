#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "list.h"

//定义双向链表
typedef struct doubleList
{
	//数据域
	int data;
	//指针域
	struct list_head mine;
}doubleList,*pDoubleList;

//初始化双向循环链表
pDoubleList list_init()
{
	//定义一个节点头
	pDoubleList head = malloc(sizeof(doubleList));
	if(NULL == head)
	{
		printf("申请头节点失败\n");
		return NULL;
	}

	//初始化指针域
	INIT_LIST_HEAD(&(head->mine));
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
	
	//赋值数据域
	newnode->data = data;
	
	//初始化指针域
	INIT_LIST_HEAD(&(newnode->mine));
	
	return newnode;
}


//判断双向链表是否是空链表
/*
返回值: 0: 空链表（只有头节点）
		1：不是空链表
		-1： 链表头为空
*/
int isEmpty(pDoubleList head)
{
	return list_empty(&head->mine);
}

//********************
//显示双向链表的数据
void showDoubleList(pDoubleList head)
{
	pDoubleList pos = NULL; //定义指针遍历链表
	printf("Double head-");
	list_for_each_entry(pos, &head->mine, mine)
	{
		printf("%d-", pos->data);
	}
	printf("Double head\n");
	
}

//*******************
void double_list_insert_head(pDoubleList head, pDoubleList node)
{
	list_add(&node->mine, &head->mine);
}

void double_list_insert_tail(pDoubleList head, pDoubleList node)
{
	list_add_tail(&node->mine, &head->mine);
}

bool double_list_find(pDoubleList head, pDoubleList node)
{
	if(head == NULL || node == NULL)
	{
		printf("不能传空指针\n");
		return false;
	}
	
	bool falg = false;
	struct list_head *pos = NULL;//遍历对象
	struct list_head *n;//下一个节点
	list_for_each_safe(pos, n, &(head->mine))
	{
		if(pos == &(node->mine))
		{
			falg = true;
			break;
		}
	}
	
	return falg;
}

void double_list_delete(pDoubleList head, pDoubleList node)
{
	pDoubleList p = list_entry(&node->mine, doubleList, mine);
	list_del(&node->mine);
	
	if(p == node)
	{
		printf("11111\n");
		free(node);
		node = NULL;
	}
	else
	{
		printf("22222\n");
	}
	
}

void delete_all(pDoubleList head)
{
	
}


void test()
{
	int a[3] = {100,50,150};
	printf("初始化链表头\n");
	pDoubleList head_A = list_init();
	printf("创建节点\n");
	pDoubleList node = NULL;
	for(int i = 0; i < 3; i++)
	{
		node = create_node(a[i]);
		double_list_insert_head(head_A, node);
	}
	showDoubleList(head_A); //Double head-150-50-100-Double head
	double_list_delete(head_A, node);
	
	if(node == NULL)
	{
		printf("node == NULL \n");
	}
	else
	{
		printf("node != NULL \n");
	}
	showDoubleList(head_A);//Double head-50-100-Double head
	double_list_insert_head(head_A, node);
	showDoubleList(head_A); //Double head-150-50-100-Double head
	
	/*
	if(double_list_find(head_A, node))
	{
		printf("找到了该节点\n");
	}
	else
	{
		printf("没有找到了该节点\n");
	}
	*/
}


int main(int argc, char* argv[])
{
	test();
	return 0;
}










