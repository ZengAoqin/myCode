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

//删除具体的元素
bool vector_delete(Pdata dataTable, int data)
{
	//判断顺序表是否为空
	if(dataTable->index < 0)
	{
		printf("顺序表为空，无法删除\n");
		return false;
	}
	
	int i;
	for(i = 0; i <= dataTable->index; i++)
	{
		if(data == dataTable->arr[i])
			break;
	}
	
	if(i > dataTable->index)
	{
		printf("删除元素不存在\n");
		return false;
	}
	
	for(int j = i; j < dataTable->index; j++)
	{
		dataTable->arr[j] = dataTable->arr[j+1];
	}
	dataTable->arr[dataTable->index] = 0;
	dataTable->index--;
	
	return true;
}

//删除角标的元素
bool vector_delete_index(Pdata dataTable, int index)
{
	//判断顺序表是否为空
	if(dataTable->index < 0)
	{
		printf("顺序表为空，无法删除\n");
		return false;
	}
	
	if(index < 0 || index > dataTable->index)
	{
		printf("删除的角标不在顺序表的范围\n");
		return false;
	}
	
	for(int i = index; i < dataTable->index; i++)
	{
		dataTable->arr[i] = dataTable->arr[i+1];
	}
	dataTable->arr[dataTable->index] = 0;
	dataTable->index --;
}

//查找数据
int vector_find(Pdata dataTable, int data)
{
	//判断顺序表是否为空
	if(dataTable->index < 0)
	{
		printf("顺序表为空，无法删除\n");
		return -1;
	}
	
	//通过下标域的个数获取数据域的值
	int i;
	for(i= 0; i <= dataTable->index; i++)
	{
		if(data == dataTable->arr[i])
		{
			break;
		}
	}
	
	if(i > dataTable->index)
	{
		printf("没有找到元素\n");
		return -1;
	}
	
	return i;
}

//修改数据
bool vector_modfiy(Pdata dataTable, int newData, int oldData)
{
	//判断顺序表是否为空
	if(dataTable->index < 0)
	{
		printf("顺序表为空，无法删除\n");
		return false;
	}
	
	int nIndex = vector_find(dataTable, oldData);
	if(nIndex == -1)
	{
		printf("没有找到该元素\n");
		return false;
	}
	
	dataTable->arr[nIndex] = newData;
	
	return true;
}

//显示顺序表内容
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

//显示顺序表内容
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
	
	printf("******************\n");
	printf("******************\n");
	vector_delete(DataTable, 3);
	printf("******************\n");
	printf("******************\n");
	showDataTableEx(DataTable);
	printf("******************\n");
	printf("******************\n");
	printf("******************\n");
	vector_delete_index(DataTable , 1);
	showDataTableEx(DataTable);
	
	int nRet = vector_find(DataTable, 4);
	if(nRet != -1)
	{
		printf("当前元素的角标是%d\n", nRet);
	}
	
	vector_modfiy(DataTable, 100, 4);
	printf("******************\n");
	printf("******************\n");
	printf("******************\n");
	printf("******************\n");
	showDataTableEx(DataTable);
	return 0;
}