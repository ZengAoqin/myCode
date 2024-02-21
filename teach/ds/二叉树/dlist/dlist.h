#ifndef _D_LIST_H
#define _D_LIST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct doubleList
{
	int data;		//数据域
	struct doubleList* prev;		//前驱指针
	struct doubleList* next;		//后继指针
}DList, *pDList;


//函数申明
extern pDList dList_init();											//初始化双向链表
extern pDList create_node(int data);								//创建新节点
extern void insert_list_head(pDList head, pDList newNode);			//从头部插入节点
extern void insert_list_tail(pDList head, pDList newNode);			//从尾部插入节点
extern void delete_free(pDList node);								//从链表上删除节点，并且释放节点
extern void delete_no_free(pDList node);							//从链表上删除节点，但不释放节点
extern void showDList(pDList head);									//显示链表数据

//节点移动
//将destNode节点移动srcNode前面
extern void list_move_front(pDList srcNode, pDList destNode);
//将destNode节点移动srcNode后面
extern void list_move_back(pDList srcNode, pDList destNode);
//将一个链表拆分为两个链表 h1->node1 h2->node2
extern void tok_list(pDList h1, pDList h2, pDList node1, pDList node2);
//寻找
extern pDList find_list_large_node(pDList head, pDList node);
#endif