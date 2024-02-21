#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

//显示数组的数据
void show(int* arr, int len)
{
	for(int i = 0; i < len; i++)
	{
		printf("-%d-", *(arr+i));
	}
	printf("\n");
}

//升序
void fast_sort_up(int* arr, int left, int right)
{
	int i = left, j = right; //获取每轮新的左边界和右边界
	int key = arr[i]; //获取左边界第一个元素为key值
	
	if(left >= right) return;
	
	while(i<j)
	{
		//因为坑位在左边，从右边界开始
		while(arr[j] >= key && i < j)
		{
			j--;
		}
		
		//找到可以替换的坑位，坑位换在右边
		arr[i] = arr[j];
		//此时坑位在右边，从左边界开始
		while(arr[i] <= key && i < j)
		{
			i++;
		}
		//找到可以替换的坑位
		arr[j] = arr[i];
	}
	//当i和j相遇，坑位换成key值
	arr[i] = key;
	
	printf("key = %d\n", key);
	show(arr, 10);
	//用递归处理左子数组
	fast_sort_up(arr, left, i-1); //因为key值的左边的数比key小，右边的数比key大
	//用递归处理右子数组
	fast_sort_up(arr, i+1, right);
}

//降序
void fast_sort_down(int* arr, int left, int right)
{
	int i = left, j = right; //获取每轮新的左边界和右边界
	int key = arr[i]; //获取左边界第一个元素为key值
	
	if(left >= right) return;
	
	while(i<j)
	{
		//因为坑位在左边，从右边界开始
		while(arr[j] <= key && i < j)
		{
			j--;
		}
		
		//找到可以替换的坑位，坑位换在右边
		arr[i] = arr[j];
		//此时坑位在右边，从左边界开始
		while(arr[i] >= key && i < j)
		{
			i++;
		}
		//找到可以替换的坑位
		arr[j] = arr[i];
	}
	//当i和j相遇，坑位换成key值
	arr[i] = key;
	
	//用递归处理左子数组
	fast_sort_down(arr, left, i-1); //因为key值的左边的数比key小，右边的数比key大
	//用递归处理右子数组
	fast_sort_down(arr, i+1, right);
	
}

void fast_sort(int* arr, int len, bool flag)
{
	if(flag)
	{
		fast_sort_up(arr, 0, len-1);
	}
	else
	{
		fast_sort_down(arr, 0, len-1);
	}
}


int main(int argc, char* argv[])
{
	int arr[] = {3,7,5,9,4,8,1,6,2,0};
	
	printf("快速排序之前的数据\n");
	show(arr, sizeof(arr)/sizeof(int));
	
	fast_sort(arr, sizeof(arr)/sizeof(int), atoi(argv[1]));
	printf("快速排序之后的数据\n");
	show(arr, sizeof(arr)/sizeof(int));
	
	return 0;
}