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

//正序
int compare_up(const void* m, const void* n)
{
	return *(int*)m - *(int*)n;
}

//逆序
int compare_down(const void* m, const void* n)
{
	return *(int*)n - *(int*)m;
}

int main(int argc, char* argv[])
{
	int arr[] = {3,7,5,9,4,8,1,6,2,0};
	
	printf("qsort之前的数据\n");
	show(arr, sizeof(arr)/sizeof(int));
	//void qsort(void *base, size_t nmemb, size_t size,
    //              int (*compar)(const void *, const void *));
	//qsort(arr, sizeof(arr)/sizeof(int), sizeof(int), compare_up);
	//printf("qsort之后的数据\n");
	//show(arr, sizeof(arr)/sizeof(int));
	
	qsort(arr, sizeof(arr)/sizeof(int), sizeof(int), compare_down);
	//bubble(arr, sizeof(arr)/sizeof(int), atoi(argv[1]));
	printf("qsort之后的数据\n");
	show(arr, sizeof(arr)/sizeof(int));
	
	return 0;
}
