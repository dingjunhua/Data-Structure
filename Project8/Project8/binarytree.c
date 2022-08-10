#define _CRT_SECURE_NO_WARNINGS
#include "binarytree.h"


BTNode* BuyNode(BTDataType x)//创建节点
{
	BTNode* newnode = (BTNode*)malloc(sizeof(BTNode));
	if (newnode == NULL)
	{
		printf("malloc fail!\n");
		exit(-1);
	}
	newnode->data = x;
	newnode->left = NULL;
	newnode->right = NULL;
	return newnode;
}
BTNode* CreatBinaryTree()//创建二叉树
{
	BTNode* node1 = BuyNode(1);
	BTNode* node2 = BuyNode(2);
	BTNode* node3 = BuyNode(3);
	BTNode* node4 = BuyNode(4);
	BTNode* node5 = BuyNode(5);
	BTNode* node6 = BuyNode(6);
	BTNode* node7 = BuyNode(7);

	node1->left = node2;
	node1->right = node4;
	node2->left = node3;
	node4->left = node5;
	node4->right = node6;
	node5->left = node7;
	return node1;
}
void PreOrder(BTNode* root)// 二叉树前序遍历
{
	if (root == NULL)
	{
		printf("# ");
		return;
	}
	printf("%d ", root->data);
	PreOrder(root->left);
	PreOrder(root->right);
}
void InOrder(BTNode* root)// 二叉树中序遍历
{
	if (root == NULL)
	{
		printf("# ");
		return;
	}
	InOrder(root->left);
	printf("%d ", root->data);
	InOrder(root->right);
}
void PostOrder(BTNode* root)// 二叉树后序遍历
{
	if (root == NULL)
	{
		printf("# ");
		return;
	}
	PostOrder(root->left);
	PostOrder(root->right);
	printf("%d ", root->data);
}
int BinaryTreeSize(BTNode* root)//二叉树节点个数
{
	if (root == NULL)
	{
		return 0;
	}
	return BinaryTreeSize(root->left) + BinaryTreeSize(root->right) + 1;
}
int BinaryTreeLeafSize(BTNode* root)//二叉树叶子节点个数
{
	if (root == NULL)
	{
		return 0;
	}
	if (root->left == NULL && root->right == NULL)
	{
		return 1;
	}
	return BinaryTreeLeafSize(root->left) + BinaryTreeLeafSize(root->right);
}
int BinaryTreeLevelKSize(BTNode* root, int k)//二叉树第k层节点个数
{
	int n = k;
	if (root == NULL)
	{
		return 0;
	}
	if (n == 1)
	{
		return 1;
	}
	return BinaryTreeLevelKSize(root->left, n - 1) + BinaryTreeLevelKSize(root->right , n-1);
}
BTNode* BinaryTreeFind(BTNode* root, BTDataType x)//二叉树查找值为x的节点
{
	if (root == NULL)
	{
		return NULL;
	}
	if (root->data == x)
	{
		return root;
	}
	BTNode* ret1 = BinaryTreeFind(root->left, x);
	if (ret1)
	{
		return ret1;
	}
	BTNode* ret2 = BinaryTreeFind(root->right, x);
	if (ret2)
	{
		return ret2;
	}
	return NULL;
}
int BinaryTreeDeep(BTNode* root)//二叉树的深度
{
	if (root == NULL)
	{
		return 0;
	}
	int leftDeep = BinaryTreeDeep(root->left) + 1;
	int rightDeep = BinaryTreeDeep(root->right) + 1;
	return leftDeep > rightDeep ? leftDeep : rightDeep;

}