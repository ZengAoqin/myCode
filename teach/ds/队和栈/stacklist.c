#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//节点
typedef struct stack_node
{
	//数据域
	int data;
	struct stack_node* next;		//指向下一个节点
}s_Node;

//链式栈
typedef struct stack
{
	struct stack_node* topNode;		//栈顶节点
	int num;						//栈节点个数
}st, *pst;


//初始化链式表
pst list_stack_init()
{
	//申请链式栈空间
	pst stack = malloc(sizeof(st));
	if(NULL == stack)
	{
		printf("stack 申请失败\n");
		return NULL;
	}
	
	//链式栈初始化 指针指向空 
	stack->topNode = NULL;
	stack->num = 0;
	return stack;
}

//入栈
void stack_push(pst stack, int data)
{
	//申请新节点 struct stack_node
	struct stack_node* newnode = malloc(sizeof(struct stack_node));
	if(NULL == newnode)
	{
		printf("get node failed\n");
		return;
	}
	
	//初始化新节点
	newnode->data = data;
	newnode->next = NULL;
	
	//让新节点成为栈顶
	newnode->next = stack->topNode;
	
	//更新栈顶位置和元素的个数
	stack->topNode = newnode;
	stack->num ++;
}

//出栈
void stack_pop(pst stack, int *n)
{
	//链表是否空
	if(stack-> num == 0)
	{
		printf("链式栈为空\n");
		return;
	}
	
	//获取栈顶元素数据
	//先保存原来栈顶节点
	struct stack_node* p = stack->topNode;
	*n = stack->topNode->data;
	//将取出元素的下一个节点作为栈顶
	stack->topNode = stack->topNode->next;
	//更新元素个数
	stack->num--;
	
	//释放原来栈顶的节点
	p->next = NULL;
	free(p);
	p = NULL;
}

int main(int argc, char* argv[])
{
	pst stack = list_stack_init();
	
	//入栈
	printf("入栈\n");
	for(int i = 1; i <= 5; i++)
	{
		printf("%d--", i*10);
		stack_push(stack, i*10);
	}
	printf("\n");
	
	//出栈
	printf("出栈\n");
	int data;
	while(stack->num != 0)
	{
		stack_pop(stack,&data);
		printf("%d--", data);
	}
	printf("\n");
	return 0;
}






