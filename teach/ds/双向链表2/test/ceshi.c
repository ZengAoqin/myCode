#include <stdio.h>
#include <stdlib.h>

struct TT
{
	void *prev;
	void *next;
};
typedef struct Test
{
	int data;
	struct TT my;
}Test,*pTest;


//初始化双向链表
pTest list_init()
{
	//定义一个节点头
	pTest head = malloc(sizeof(Test));
	if(NULL == head)
	{
		printf("申请头节点失败\n");
		return NULL;
	}

	//初始化指针域
	head->my.prev = &(head->my);
	head->my.next = &(head->my);
	return head;
}

int main(int argc, char* argv[])
{
	pTest head = list_init();
	printf("head = %p, prev = %p, next = %p\n", head, head->my.prev, head->my.next);
	return 0;
}