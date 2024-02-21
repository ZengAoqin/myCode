#include <stdio.h>
#include "list.h"
#include <stdlib.h>

typedef struct kernellist
{
	int data; //数据域
	struct list_head mine; //指针域
}kList, *pkList;

//初始化头节点
pkList create_head()
{
	//申请头结点对象
	pkList head = malloc(sizeof(kList));
	
	if(head == NULL)
	{
		printf("head error malloc\n");
		return NULL;
	}
	
	//初始化节点指针域
	INIT_LIST_HEAD(&(head->mine));
	return head;
}

//创建新节点
pkList create_node(int data)
{
	pkList _new = malloc(sizeof(kList));
	
	if(_new == NULL)
	{
		printf("_new error malloc\n");
		return NULL;
	}
	
	//初始化数据域
	_new->data = data;
	//初始化节点指针域
	INIT_LIST_HEAD(&(_new->mine));
	return _new;
}

//list_add(struct list_head *new, struct list_head *head)
//头部插入
void insert_head(pkList head, pkList _new)
{
	list_add(&_new->mine,&head->mine);
}

//list_add_tail(struct list_head *new, struct list_head *head)
//尾部插入
void insert_tail(pkList head, pkList _new)
{
	list_add_tail(&_new->mine, &head->mine);
}

//显示数据
//list_for_each_entry(pos, head, member)
void kernellist_display(pkList head)
{
	pkList pos = NULL;
	printf("head-");
	list_for_each_entry(pos, &head->mine, mine)
	{
		printf("%d-", pos->data);
	}
	printf("head\n");
}

int main(int argc, char* argv[])
{
	pkList head = create_head();
	printf("next = %p, prev = %p head = %p\n", head->mine.next, head->mine.prev, head);
	printf("head->mine = %p\n", &head->mine);
	printf("head->data = %p\n", &head->data);
	pkList _new = NULL;
	for(int i = 1; i <= 3; i++)
	{
		_new = create_node(i*10);
		insert_head(head, _new);
	}
	
	kernellist_display(head);
	
	printf("p = %ld\n", sizeof(kList));
	return 0;
}











