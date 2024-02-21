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
			insert_tree(root->left, node)
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
