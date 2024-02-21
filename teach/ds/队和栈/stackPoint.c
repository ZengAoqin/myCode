#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

//#define MAX 100

//设计顺序栈
typedef struct stack
{
	//int arr[MAX];
	int* data; 		//数据域
	int size;		//动态大小设定
	int top;		//记录最新栈顶
}stack, *pS;

pS stack_init(int size)
{
	//申请栈表空间
	pS myStack = malloc(sizeof(stack));
	if(myStack == NULL)
	{
		printf("申请栈表空间失败\n");
		return NULL;
	}
	
	myStack->data = malloc(size*sizeof(int)); //大小 = 元素类型大小*个数
	if(myStack->data == NULL)
	{
		printf("无法申请足够空间\n");
		free(myStack);
		myStack = NULL;
		return NULL;
	}
	myStack->size = size;
	myStack->top = 0;
	
	return myStack;
}

//空栈
bool is_stack_empty(pS stack)
{
	return stack->top == 0;
}

//满栈
bool is_stack_full(pS stack)
{
	return stack->top == stack->size;
}

//入栈 返回值 入栈失败 返回-1 ，入栈成功返回data
void stack_push(pS stack, const int* data)
{
	if(is_stack_full(stack))
	{
		printf("栈表已经满了\n");
		return ;
	}
	
	stack->data[stack->top++] = *data;
}

//出栈 返回值 出栈失败 返回-1，出栈成功返回data
void statck_pop(pS stack, int *data)
{
	if(is_stack_empty(stack))
	{
		printf("栈表已经空了\n");
		return ;
	}
	
	*data = stack->data[--stack->top];
}


int main(int argc, char* argv[])
{
	pS myStack = stack_init(10);
	
	int n;
	printf("入栈结果:\n");
	for(int i = 1; i <= 5; i++)
	{
		stack_push(myStack, &i);
		printf("%d-", i);
	}
	printf("\n");
	
	printf("出栈结果:\n");
	for(int i = 1; i <= 5; i++)
	{
		statck_pop(myStack, &n);
		printf("%d-", n);
	}
	printf("\n");
	
	return 0;
}