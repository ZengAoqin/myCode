#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX 10

//定义顺序表
typedef struct Data
{
	//数据域
	int arr[MAX];
	//下标域
	int index;
}Data,*Pdata;

//顺序表初始化：获取指向顺序表的指针
Pdata vector_init()
{
	//申请指向指针并申请内存
	Pdata head = malloc(sizeof(Data));
	if(NULL == head)
	{
		printf("当前内存空间申请失败\n");
		return NULL;
	}
	
	//初始化数据域
	memset(head->arr, 0, sizeof(head->arr));
	//初始化下标域
	head->index = -1; //表示没有任何数据存储
	
	//返回结构体指针
	return head;
}

int main(int argc, char* argv[])
{
	//通过vector_init获取顺序表的指针
	Pdata DataTable = vector_init();
	return 0;
}