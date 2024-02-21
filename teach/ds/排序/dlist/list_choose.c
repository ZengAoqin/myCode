#include "dlist.h"

//链表选择排序
void list_choose_sort(pDList head)
{
	pDList MAX = NULL;
	pDList p = NULL, q = NULL;
	
	for(p = head; p != head->next; p = p->prev)
	{
		MAX = head->next; //默认头节点的下一个节点为最大节点
		//遍历
		for(q = MAX; q != p; q=q->next)
		{
			//循环比较，获取链表中最大值的节点
			if(q->data > MAX->data)
			{
				MAX = q;
			}
		}
		
		list_move_front(p, MAX);
	}
}

int main(int argc, char* argv[])
{
	int arr[] = {3,7,5,9,4,8,1,6,2,0};
	pDList node = NULL;
	pDList head = dList_init();
	
	for(int i = 0; i < 10; i++)
	{
		node = create_node(arr[i]);
		insert_list_tail(head, node);
	}
	
	printf("链表选择排序之前的数据\n");
	showDList(head);
	
	list_choose_sort(head);
	printf("链表选择排序之后的数据\n");
	showDList(head);
}