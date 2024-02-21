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

//flag : true 升序 1-2-3 false 降序 3-2-1
void choose(int* arr, int len, bool flag)
{
	int i,j,index;
	for(i = 0; i < len; i++)
	{
		index = 0;
		for(j = 1; j < len-i; j++)
		{
			if(flag) //升序
			{
				if(arr[index] < arr[j])
				{
					index = j;
				}
			}
			else
			{
				if(arr[index] > arr[j])
				{
					index = j;
				}
			}
		}
		
		//如果选择到数据不在本轮最后一位，交换数据
		if(index != len-1-i)
		{
			arr[index] = arr[index]^arr[len-1-i];
			arr[len-1-i] = arr[index]^arr[len-1-i];
			arr[index] = arr[index]^arr[len-1-i];
		}
		printf("第%d结果数据", i+1);
		show(arr, len);
	}
}

int main(int argc, char* argv[])
{
	int arr[] = {3,7,5,9,4,8,1,6,2,0};
	
	printf("选择排序之前的数据\n");
	show(arr, sizeof(arr)/sizeof(int));
	
	choose(arr, sizeof(arr)/sizeof(int), atoi(argv[1]));
	printf("选择排序之后的数据\n");
	show(arr, sizeof(arr)/sizeof(int));
	
	return 0;
}




