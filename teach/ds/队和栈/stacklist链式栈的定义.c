
//节点
struct stack_node
{
	//数据域
	int data;
	struct stack_node* next;		//指向下一个节点
};

//链式栈
typedef struct stack
{
	//数据域
	struct stack_node* node;		//节点
	int num;						//栈节点个数
}st, *pst;


//初始化链式表
pst list_stack_init()
{
	//申请链式栈空间
	
	//链式栈初始化 指针指向空 
}

//入栈
//申请新节点 struct stack_node
//初始化新节点
//让新节点成为栈顶
//更新栈顶位置和元素的个数

//出栈
//链表是否空
//获取栈顶元素数据
//将取出元素的下一个节点作为栈顶
//更新元素的个数