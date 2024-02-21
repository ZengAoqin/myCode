//节点设计
struct node
{
	int data;			//数据域
	struct node* next;	//指针域
};

struct queuelist
{
	struct node* front;		//队首
	struct node* rear;		//队尾
	int length;				//队列长度
};

//链式队列初始化
//申请链式队列对象
//队首指针和队尾指针指向NULL


//链式队列入队
//申请新节点 struct node*
//新节点数据初始化 数据域和指针域
//将新节点插入到队列尾部
//队列长度自增


//链式队列出队
//判断是否是空队列
//定义临时节点保存队首，方便释放
//指定零时节点的next指向节点为新的队首
//获取零时节点的数据
//释放零时节点
//队列长度自减