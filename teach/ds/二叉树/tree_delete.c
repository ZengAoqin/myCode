/*如果去删除一个树节点
①这个节点没有左节点，也没有右节点
②这个节点有左节点，没有右节点
③这个节点没有左节点，有右节点
⑤即有右节点，又有左节点
*/
#include <stdlib.h>
#include <stdio.h>

//定义二叉树
typedef struct tree
{
	int data;			//数据域
	struct tree* left;	//左节点
	struct tree* right;	//右节点
}tree, *TREE;

//创建节点
TREE create_node(int data)
{
	//申请节点
	TREE node = malloc(sizeof(tree));
	if(NULL == node)
	{
		printf("malloc node failed\n");
		return NULL;
	}
	
	//初始化数据
	node->data = data;
	node->left = NULL;
	node->right = NULL;
}

//插入节点，满足"小----中----大"
void insert_tree(TREE root, TREE node)
{
	//判断插入节点和当前root的关系节点
	if(root->data > node->data)
	{
		//那么当前插入节点在根节点的左节点上
		if(root->left == NULL) //如果根节点的左节点指向空
		{
			root->left = node; //将根节点的左节点指向插入的node
		}
		else
		{
			insert_tree(root->left, node);
		}
	}
	else if(root->data < node->data)
	{
		//那么当前插入节点在根节点的右节点上
		if(root->right == NULL) //如果根节点的右节点指向空
		{
			root->right = node; //将根节点的右节点指向插入的node
		}
		else
		{
			insert_tree(root->right, node);
		}
	}
}

TREE find_tree(TREE root, int data)
{
	TREE pTree = NULL;
	if(root->data > data)
	{
		//在根节点左侧找
		if(root->left == NULL)
		{
			printf("查找节点失败\n");
		}
		else
		{
			pTree = find_tree(root->left, data);
		}
	}
	else if(root->data < data)
	{
		//在根节点右侧找
		if(root->right == NULL)
		{
			printf("查找节点失败\n");
		}
		else
		{
			pTree = find_tree(root->right, data);
		}
	}
	else
	{
		pTree = root;
	}
	
	return pTree;
}

TREE delete_tree(TREE root, int data)
{
	TREE pTree = NULL;
	if(root->data > data)
	{
		//在根节点左侧找
		if(root->left == NULL)
		{
			printf("没有找到要删除的节点\n");
		}
		else
		{
			root->left = delete_tree(root->left, data);
		}
	}
	else if(root->data < data)
	{
		//在根节点右侧找
		if(root->right == NULL)
		{
			printf("没有找到要删除的节点\n");
		}
		else
		{
			root->right = delete_tree(root->right, data);
		}
	}
	else //当前根节点等于data root->data == data，root节点为删除节点
	{
		if(root->left != NULL)
		{
			//查找左节点最大值
			pTree = root->left;
			while(pTree->right != NULL)
			{
				pTree = pTree->right;
			}
			//将找到左节点最大值节点的数据替换删除节点值
			root->data = pTree->data;
			root->left = delete_tree(root->left, pTree->data);
		}
		else if(root->right != NULL)
		{
			//找到右节点最小值
			pTree = root->right;
			while(pTree->left != NULL)
			{
				pTree = pTree->left;
			}
			//将找到右节点最小值节点的数据替换删除节点值
			root->data = pTree->data;
			root->right = delete_tree(root->right, pTree->data);
		}
		else
		{
			free(root);
			root = NULL;
			
			return NULL;
		}
	}
	
	return root; //返回根节点
}

//先序遍历
void front_show(TREE root)
{	
	//根打印
	printf("-%d-", root->data);
	
	//再打印左节点
	if(root->left != NULL)
	{
		front_show(root->left);
	}
	
	//再打印右节点
	if(root->right != NULL)
	{
		front_show(root->right);
	}
}

//中序遍历(左根右)
void middle_show(TREE root)
{
	//先输出左节点
	if(root->left != NULL)
	{
		middle_show(root->left);
	}
	
	//再输出根节点
	printf("-%d-", root->data);
	
	//再打印右节点
	if(root->right != NULL)
	{
		middle_show(root->right);
	}
}

//后序遍历(左右根)
void back_show(TREE root)
{
	//先输出左节点
	if(root->left != NULL)
	{
		back_show(root->left);
	}
	
	//再打印右节点
	if(root->right != NULL)
	{
		back_show(root->right);
	}
	
	//再输出根节点
	printf("-%d-", root->data);
}

int main(int argc, char* argv[])
{
	//定义数组
	int arr[9] = {20,18,15,19,25,21,23,28,10};
	//设置二叉树的根节点
	TREE root = create_node(arr[0]);
	//插入节点
	TREE node = NULL;
	for(int i = 1; i < 9; i++)
	{
		node = create_node(arr[i]); //新节点
		insert_tree(root, node);    //插入节点
	}
	
	node = NULL;
	node = find_tree(root, 100);
	if(node != NULL)
	{
		printf("查询到的数据为%d\n", node->data);
	}
	
	printf("根左右排序\n");
	front_show(root);
	printf("\n");
	
	printf("左根右排序\n");
	middle_show(root);
	printf("\n");
	
	printf("左右根排序\n");
	back_show(root);
	printf("\n");
	
	int data;
	printf("请输入要删除的节点数据\n");
	scanf("%d", &data);
	delete_tree(root, data);
	middle_show(root);
	printf("\n");
	
	printf("根左右排序\n");
	front_show(root);
	printf("\n");
	
	return 0;
}