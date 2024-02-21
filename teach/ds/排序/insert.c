#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//显示数组的数据
void show(int* arr, int len)
{
	for(int i = 0; i < len; i++)
	{
		printf("-%d-", *(arr+i));
	}
	printf("\n");
}

void insert(int* arr, int len, bool falg)
{
	int i,j,temp;
	if(falg) //升序
	{
		for(i = 1; i < len; i++)
		{
			temp = arr[i];
		
			for(j = i; j > 0 && temp < arr[j-1]; j--)
			{
				arr[j] = arr[j-1];
			}
		
			arr[j] = temp;
		
			printf("第%d轮结果", i);
			show(arr, len);
		}
	}
	else //降序
	{
		for(i = 1; i < len; i++)
		{
			temp = arr[i];
		
			for(j = i; j > 0 && temp > arr[j-1]; j--)
			{
				arr[j] = arr[j-1];
			}
		
			arr[j] = temp;
		
			printf("第%d轮结果", i);
			show(arr, len);
		}
	}
	
}

int main(int argc, char* argv[])
{
	int arr[] = {3,7,5,9,4,8,1,6,2,0};
	
	printf("插入排序之前的数据\n");
	show(arr, sizeof(arr)/sizeof(int));
	
	insert(arr, sizeof(arr)/sizeof(int), atoi(argv[1]));
	printf("插入排序之后的数据\n");
	show(arr, sizeof(arr)/sizeof(int));
	return 0;
}