#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

//#define MAX 100

//设计顺序栈
typedef struct stack
{
	//int arr[MAX];
	char* data; 	//数据域
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
char stack_push(pS stack, char data)
{
	if(is_stack_full(stack))
	{
		printf("栈表已经满了\n");
		return -1;
	}
	
	stack->data[stack->top++] = data;
	return data;
}

//出栈 返回值 出栈失败 返回-1，出栈成功返回data
char statck_pop(pS stack)
{
	if(is_stack_empty(stack))
	{
		printf("栈表已经空了\n");
		return -1;
	}
	
	return stack->data[--stack->top];
}

//定义枚举
typedef enum PAGE_TYPE
{
	PAGE_ONE = 1,  		//第一页，让玩家输入一个正整数
	PAGE_TWO = 2,			//第二页，玩家可以返回上一级、二进制、八进制、十六进制、可退出的操作
	PAGE_THREE = 3,			//第三页，显示二进制、八进制、十六进制
}PAGE_TYPE;

//只做显示
void menu(PAGE_TYPE page, int num, pS stack)
{
	switch(page)
	{
		case PAGE_ONE:
		{
			printf("***************请输入一个正整数***************\n");
			break;
		}
		case PAGE_TWO:
		{
			printf("*************** 1：返回上一级***************\n");
			printf("*************** 2：%d装换成二进制***************\n", num);
			printf("*************** 3：%d装换成八进制***************\n", num);
			printf("*************** 4：%d装换成十六进制***************\n", num);
			printf("*************** 0：退出***************\n");
			break;
		}
		case PAGE_THREE:
		{
			//出栈
			while(!is_stack_empty(stack))
			{
				printf("%c", statck_pop(stack));
			}
			printf("\n");
			break;
		}
		default:
		break;
	}
}

void convert()
{
	PAGE_TYPE currentPage = PAGE_ONE;
	int m = 0,opt = 0,temp = 0;
	pS myStack = stack_init(32);
	bool bFlag = true;
	
	while(bFlag)
	{
		//显示
		menu(currentPage, m, myStack);

		if(currentPage == PAGE_ONE)
		{
			scanf("%d", &m);
			while(getchar() != '\n'); //清空缓冲区
			currentPage = PAGE_TWO;
			//清空栈的数据
			myStack->top = 0;
		}
		else if(currentPage == PAGE_THREE)
		{
			currentPage = PAGE_TWO;
		}
		
		menu(currentPage, m, myStack);
		scanf("%d", &opt);
		while(getchar() != '\n'); //清空缓冲区
		
		switch(opt)
		{
			case 2:
			{
				temp = m;
				while(temp != 0)
				{
					stack_push(myStack, temp%2 + '0');
					temp /= 2; // ===》temp = temp/2;
				}
				currentPage = PAGE_THREE;
				break;
			}
			case 3:
			{
				temp = m;
				while(temp != 0)
				{
					stack_push(myStack, temp%8 + '0');
					temp /= 8; // ===》temp = temp/2;
				}
				currentPage = PAGE_THREE;
				break;
			}
			case 4:
			{
				temp = m;
				while(temp != 0)
				{
					if((temp%16) > 9)
					{
						stack_push(myStack, temp%16 - 10 + 'A');
					}
					else
					{
						stack_push(myStack, temp%16 + '0');
					}
			
					temp /= 16; // ===》temp = temp/2;
				}
				currentPage = PAGE_THREE;
				break;
			}
			case 1:
			{
				currentPage = PAGE_ONE;
				break;
			}
			case 0:
			{
				bFlag = false;
				break;
			}
			default:
			{
				printf("没有这个选项值\n");
				break;
			}
		}
	}
}

int main(int argc, char* argv[])
{
	convert();
	return 0;
}











