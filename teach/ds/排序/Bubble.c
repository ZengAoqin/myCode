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
void bubble(int* arr, int len, bool flag)
{
	int i,j;
	for(i = 0; i < len-1; i++)
	{
		for(j = 0; j < len-1-i; j++)
		{
			if(flag) //升序
			{
				if(arr[j] > arr[j+1])
				{
					arr[j] = arr[j]^arr[j+1];
					arr[j+1]= arr[j]^arr[j+1];
					arr[j] = arr[j]^arr[j+1];
				}
			}
			else
			{
				if(arr[j] < arr[j+1])
				{
					arr[j] = arr[j]^arr[j+1];
					arr[j+1]= arr[j]^arr[j+1];
					arr[j] = arr[j]^arr[j+1];
				}
			}
			
			printf("第%d轮%d次数据\n", i+1,j+1);
			show(arr, len);
		}
	}
}

int main(int argc, char* argv[])
{
	int arr[] = {3,7,5,9,4,8,1,6,2,0};
	
	printf("冒泡排序之前的数据\n");
	show(arr, sizeof(arr)/sizeof(int));
	
	bubble(arr, sizeof(arr)/sizeof(int), atoi(argv[1]));
	printf("冒泡排序之后的数据\n");
	show(arr, sizeof(arr)/sizeof(int));
	
	return 0;
}