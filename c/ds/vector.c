#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define MAX 10


typedef struct Data
{
    int arr[10];
    int index;
}vector;

//初始化顺序表
vector* init()
{
    //申请指向指针并申请内存
    vector* head = malloc(sizeof(vector));
    if(NULL == head)
    {
        printf("当前内存空间申请失败\n");
		return NULL;
    }

    memset(head->arr, 0, sizeof(head->arr));
    head->index = -1;

    return head;
}

//输出所有数据
void show(vector* dataTable)
{
    if(dataTable->index < 0)
    {
        printf("顺序表为空");
        return;
    }

    for(int i = 0; i <= dataTable->index; i++)
    {
        printf("%d ", dataTable->arr[i]);
    }
    printf("\n");
}

//插入数据
int insert(vector* dataTable, int data)
{
    if(dataTable->index >= MAX)
    {
        printf("该顺序表已满\n");
        return -1;
    }

    dataTable->index++;
    dataTable->arr[dataTable->index] = data;

    return 0;
}

//根据数据删除数据
int deleteByData(vector* dataTable, int data)
{
    int i;

    if(dataTable->index < 0)
    {
        printf("顺序表为空 无法删除\n");
        return -1;
    }

	for(i = 0; i <= dataTable->index; i++)
	{
		if(data == dataTable->arr[i])
			break;
	}

    for(int j = i; j < dataTable->index; j++)
    {
        dataTable->arr[j] = dataTable->arr[j + 1];
    }

    dataTable->arr[dataTable->index] = 0;
    dataTable->index--;

    return 0;
}

//根据index删除数据
int deleteByIndex(vector* dataTable, int index)
{
    if(dataTable->index < 0)
    {
        printf("顺序表为空 无法删除\n");
        return -1;
    }

    for(int i = index; i < dataTable->index; i++)
    {
        dataTable->arr[i] = dataTable->arr[i + 1];
    }

    dataTable->arr[dataTable->index] = 0;
    dataTable->index--;

    return 0;
}

//查找数据
int find(vector* dataTable, int data)
{
    int i;

    if(dataTable->index < 0)
    {
        printf("顺序表为空\n");
        return -1;
    }

    for(i = 0; i <= dataTable->index; i++)
    {
        if(data == dataTable->arr[i])
        {
            break;
        }
    }

    if(i > dataTable->index)
    {
        printf("未找到元素\n");
        return -1;
    }

    return i;
}

int update(vector* dataTable, int index, int data)
{
    int i;

    if(dataTable->index < 0)
    {
        printf("顺序表为空\n");
        return -1;
    }

    for(i = 0; i <= dataTable->index; i++)
    {
        if(i == index)
        {
            dataTable->arr[i] = data;
            break;
        }
    }

    if(i > dataTable->index)
    {
        printf("未找到元素\n");
        return -1;
    }
    
    return 0;
}

void free_vector(vector* dataTable)
{
    if(dataTable == NULL)
    {
        printf("顺序表为空\n");
    }
    else
    {
        memset(dataTable->arr, 0, sizeof(dataTable->arr));
        dataTable->index = -1;
        free(dataTable);
        printf("顺序表已清空\n");
    }
}

int main(int argc, char* argv[])
{
    vector* dataTable = init();

    show(dataTable);
    sleep(1);

    for(int i = 0; i < 10; i++)
    {
        if(insert(dataTable, i*10))
        {
            printf("插入失败");
        }
    }

    printf("插入数据：\n");
    show(dataTable);
    sleep(1);

    printf("删除数据70：\n");
    deleteByData(dataTable, 70);
    show(dataTable);
    sleep(1);

    printf("删除第3个数据：\n");
    deleteByIndex(dataTable, 2);
    show(dataTable);
    sleep(1);

    printf("查找值为50的数据下标：\n");
    int ret = find(dataTable, 50);
    printf("%d\n", ret);
    sleep(1);

    printf("修改下标为6的数据值为66：\n");
    ret = update(dataTable, 6, 66);
    show(dataTable);
    sleep(1);

    free_vector(dataTable);

    return 0;
}