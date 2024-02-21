#include "head.h"
#include <string.h>

//创建表头
INFO create_head()
{
	//定义一个节点头
	INFO head = malloc(sizeof(info));
	if(NULL == head)
	{
		printf("申请头节点失败\n");
		return NULL;
	}

	//初始化指针域
	head->prev = head;
	head->next = head;
	
	return head;
}

//创建双向链表的节点
INFO create_node(pStudent pData)
{
	//定义一个节点
	INFO newnode = malloc(sizeof(info));
	if(NULL == newnode)
	{
		printf("申请节点失败\n");
		return NULL;
	}
	
	strcpy(newnode->stuInfo.strID, pData->strID);
	strcpy(newnode->stuInfo.strName, pData->strName);
	newnode->stuInfo.age = pData->age;
	strcpy(newnode->stuInfo.strSex, pData->strSex);
	newnode->stuInfo.fgrade = pData->fgrade;
	
	newnode->prev = NULL;
	newnode->next = NULL;
	
	return newnode;
}

//判断双向链表是否是空链表
/*
返回值: 0: 空链表（只有头节点）
		1：不是空链表
		-1： 链表头为空
*/
int isEmpty(INFO head)
{
	int nRet = -1;
	if(head != NULL)
	{
		if(head->next == head)
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

//头部插入
void double_list_insert_head(INFO head, INFO node)
{
	int nRet = isEmpty(head);
	if(nRet == -1)
	{
		return;
	}
	else
	{
		head->next->prev = node;
		node->next = head->next;
		node->prev = head;
		head->next = node;
	}
}

//尾部插入
void double_list_insert_tail(INFO head, INFO node)
{
	int nRet = isEmpty(head);
	if(nRet == -1)
	{
		return;
	}
	else
	{
		INFO p = head;
		while(p->next != head)
		{
			p = p->next;
		}
		
		p->next = node;
		node->prev  = p;
		node->next = head;
		head->prev = node;
	}
}

bool double_list_find(INFO head, INFO node)
{
	if(head == NULL || node == NULL)
	{
		printf("不能传空指针\n");
		return false;
	}
	
	INFO p = head->next;
	while(p != head)
	{
		if(p == node)
		{
			break;
		}
		p = p->next;
	}
	
	return (p != head) ? true:false;
}

//修改节点
void double_list_modify(INFO head, INFO node, pStudent pData)
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
	
	strcpy(node->stuInfo.strID, pData->strID);
	strcpy(node->stuInfo.strName, pData->strName);
	node->stuInfo.age = pData->age;
	strcpy(node->stuInfo.strSex, pData->strSex);
	node->stuInfo.fgrade = pData->fgrade;
}

//删除节点
void double_list_delete(INFO head, INFO node)
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
	
	node->prev->next = node->next;
	node->next->prev = node->prev;
	
	node->prev = NULL;
	node->next = NULL;
	free(node);
	node = NULL;
}
