#include "dlist.h"

//交换两个节点
void swap(pDList p, pDList q)
{
	DList temp = *p;
	temp.next = q->next;
	temp.prev = q->prev;
	
	q->next = p->next;
	q->prev = p->prev;
	*p = *q;
	
	*q = temp;
}

void fast_sort(pDList left, pDList right, pDList head)
{
	if(left == right) return;
	
	//i向右走，j向左走
	pDList i = left->next, j = right;
	while(i != j)
	{
		//如果i->data大于 left->data(作为key值)，就交换i和j，j向前走
		printf("key = %d, i->data = %d\n", left->data, i->data);
		if(i->data > left->data)
		{
			swap(i,j);
			j = j->prev;
		}
		else
		{
			i = i->next;
		}
		showDList(head);
	}
	
	if(i->data > left->data)
	{
		i = i->prev;
	}
	swap(i, left);
	
	//处理左子串
	fast_sort(left, i, head);
	//处理右子串
	fast_sort(j, right, head);
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
	
	printf("链表节点快速排序之前的数据\n");
	showDList(head);
	
	fast_sort(head->next,head->prev, head);
	printf("链表节点快速排序之后的数据\n");
	showDList(head);
}