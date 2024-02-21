#include "dlist.h"

//链表插入排序
void list_insert_sort1(pDList head)
{
	/*head
     拆分为两个链表
	 H--3--7--5--9--4--8--1--6--2--0- 无序链表，添加新头节点
	*/
	pDList H = dList_init();
	pDList p = NULL, dest = NULL;
	H->prev = head->prev;
	H->next = head->next;
	head->prev->next = H;
	head->next->prev = H;
	
	//将原来的头结点断联
	head->prev = head;
	head->next = head;
	
	printf("***************\n");
	while(H->next != H)
	{
		p = H->next; //获取第一个节点
		dest = find_list_large_node(head, p);
		printf("********\n");
		list_move_back(dest, p);
		//if(H->next != H)
		showDList(head);
	}
	
	H->prev = NULL;
	H->next = NULL;
	free(H);
	H = NULL;
}


//链表插入排序
void list_insert_sort(pDList head)
{
	pDList node = NULL;
	pDList p = head->next->next, q = NULL;
	
	while(p != head)
	{
		node = p;
		p = p->next;
		for(q = p->prev->prev; q != head; q = q->prev)
		{
			if(node->data > q->data)
			{
				list_move_back(q, node);
				break;
			}
		}
		if(q == head)
		{
			list_move_back(q, node);
		}
		showDList(head);
	}
	
	//showDList(head);
}

void list_insert_sort3(pDList head)
{
	pDList p = NULL,q = NULL,temp = NULL;
	for(p = head->next->next;p != head;p = temp)
	{
		//保留p的下一个位置
		temp = p->next;
		for(q = p->prev;q != head && p->data > q->data;q = q->prev )
		{
			//temp的数据和q的数据相比，如果当前位置的p的数据(temp)小于前面一个（q）
			//就要把temp插入到q的前面
			disconnect_node(p);
			insert_list_tail(q,p);
			q = p;//矫正q的位置
		}
		//测试运行次数
		printf("p->data = %d\n",p->data);
		show_dList(head);
		
	}
}

int main(int argc, char* argv[])
{
	int arr[] = {3,7,5,9,4,8,1,6,2,0};
	//int arr[] = {3,7};
	pDList node = NULL;
	pDList head = dList_init();
	
	for(int i = 0; i < 10; i++)
	{
		node = create_node(arr[i]);
		insert_list_tail(head, node);
	}
	
	//printf("链表插入排序之前的数据\n");
	//showDList(head);
	
	list_insert_sort(head);
	printf("链表插入排序之后的数据\n");
	showDList(head);
}