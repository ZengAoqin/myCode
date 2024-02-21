//10个数，
//第一轮有九次
//第二轮有八次
//第三轮有七次
//... ...
//第九轮有一次
//因为数据要两两比较，正常思维从左往右
//如果满足交换条件，需要交换节点

#include "dlist.h"

void bubble_sort(pDList head)
{
	pDList p = NULL, q = NULL;
	pDList temp = NULL;
	pDList m = NULL;
	int i = 0, j = 0;
	//外层循环从右到左
	for(m = head, q = m->prev; q != head->next; m = m->prev, q = m->prev)
	{
		++i;
		j = 0;
		//内层循环从左到右
		for(temp = head, p = temp->next; p->next != m; temp = temp->next, p = temp->next)
		{
			printf("p->data = %d, p->next->data= %d\n", p->data, p->next->data);
			//比较相邻的两个数
			if(p->data > p->next->data)
			{
				//将当前节点插入到下一个节点之后
				list_move_back(p->next, p);
			}
			++j;
			printf("第%d轮第%d次\n", i, j);
			showDList(head);
		}
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
	
	printf("链表冒泡排序之前的数据\n");
	showDList(head);
	
	bubble_sort(head);
	printf("链表冒泡排序之后的数据\n");
	showDList(head);
}