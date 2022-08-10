#define _CRT_SECURE_NO_WARNINGS
#include "binarytree.h"



void test01()
{
	BTNode* root = CreatBinaryTree();
	PreOrder(root);
	printf("\n");
	InOrder(root);
	printf("\n");
	PostOrder(root);
	printf("\n");
	printf("二叉树节点个数：%d\n", BinaryTreeSize(root));
	printf("二叉树叶子节点个数：%d\n",BinaryTreeLeafSize(root));
	printf("二叉树第K层的节点个数：%d\n", BinaryTreeLevelKSize(root, 2));
	printf("二叉树查找值为x的节点：%p\n", BinaryTreeFind(root, 5));
	printf("二叉树的深度：%d\n", BinaryTreeDeep(root));
}

int main()
{
	test01();
	return 0;
}