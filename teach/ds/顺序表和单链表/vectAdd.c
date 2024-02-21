#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

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

//在顺序表新增数据
bool vector_insert(Pdata dataTable, int data)
{
	if(dataTable->index >= MAX)
	{
		printf("该顺序表已满\n");
		return false;
	}
	
	//下标域+1
	dataTable->index++;
	//数据域赋值
	dataTable->arr[dataTable->index] = data;
	return true;
}

void showDataTable(Data data)
{
	//判断顺序表是否为空
	if(data.index < 0)
	{
		printf("顺序表为空\n");
	}
	
	//通过下标域的个数获取数据域的值
	for(int i = 0; i <= data.index; i++)
	{
		printf("%d\t", data.arr[i]);
	}
	printf("\n");
}

void showDataTableEx(const Pdata dataTable)
{
	//判断顺序表是否为空
	if(dataTable->index < 0)
	{
		printf("顺序表为空\n");
	}
	
	//通过下标域的个数获取数据域的值
	for(int i = 0; i <= dataTable->index; i++)
	{
		printf("%d\t", dataTable->arr[i]);
	}
	printf("\n");
}

int main(int argc, char* argv[])
{
	//通过vector_init获取顺序表的指针
	Pdata DataTable = vector_init();
	//显示内容
	showDataTableEx(DataTable);
	//测试数据
	for(int i = 0; i < 5; i++)
	{
		if(vector_insert(DataTable, i+1) == false)
		{
			printf("新增数据失败\n");
		}
	}
	printf("******************\n");
	showDataTableEx(DataTable);
	return 0;
}