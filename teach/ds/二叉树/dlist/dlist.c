#include "dlist.h"

//初始化双向链表
pDList dList_init()
{
	pDList head = malloc(sizeof(DList));
	if(NULL == head)
	{
		printf("head malloc failed\n");
		return NULL;
	}
	
	head->prev = head;
	head->next = head;
	return head;
}

//创建新节点
pDList create_node(int data)
{
	pDList node = malloc(sizeof(DList));
	if(NULL == node)
	{
		printf("node malloc failed\n");
		return NULL;
	}
	
	node->data = data;
	node->prev = NULL;
	node->next = NULL;
	return node;
}

//内部函数插入新节点
static void list_add(pDList new, pDList prev, pDList next)
{
	next->prev = new;
	new->next = next;
	new->prev = prev;
	prev->next = new;
}

//从头部插入节点
void insert_list_head(pDList head, pDList newNode)
{
	list_add(newNode, head, head->next);
}

//从尾部插入节点
void insert_list_tail(pDList head, pDList newNode)
{
	list_add(newNode, head->prev, head);
}

//内部函数删除节点
void list_del(pDList prev, pDList next)
{
	next->prev = prev;
	prev->next = next;
}

//从链表上删除节点，并且释放节点
void delete_free(pDList node)
{
	list_del(node->prev, node->next);
	node->prev = NULL;
	node->next = NULL;
	free(node);
	node = NULL;
}			

//从链表上删除节点，但不释放节点
void delete_no_free(pDList node)
{
	list_del(node->prev, node->next);
	node->prev = NULL;
	node->next = NULL;
}

#define list_for_each(pos, head) \
for (pos = (head)->next; pos != (head); \
pos = pos->next)	

//显示链表数据	
void showDList(pDList head)
{
	pDList pos = NULL;
	list_for_each(pos, head)
	{
		printf("--%d--", pos->data);
	}
	printf("\n");
}

//将pDListDest节点移动srcNode前面
void list_move_front(pDList srcNode, pDList destNode)
{
	delete_no_free(destNode);
	list_add(destNode, srcNode->prev, srcNode);
}

//将destNode节点移动srcNode后面
void list_move_back(pDList srcNode, pDList destNode)
{
	delete_no_free(destNode);
	list_add(destNode, srcNode, srcNode->next);
}

pDList find_list_large_node(pDList head, pDList node)
{
	pDList p = head->prev;
	
	for(; p != head; p = p->prev)
	{
		if(p->data < node->data)
		{
			break;
		}
	}
	
	return p;
}

//将一个链表拆分为两个链表 h1->node1 和 h2->node2
void tok_list(pDList h1, pDList h2, pDList node1, pDList node2)
{
	h1->prev = node1;
	node1->next = h1;
	
	h2->prev = node2;
	node2->next = h2;
}
														
