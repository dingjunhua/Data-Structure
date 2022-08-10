#pragma once
#include <stdio.h>
#include <stdlib.h>

typedef int BTDataType;

typedef struct BinaryTree
{
	BTDataType data;
	struct BinaryTree* left;
	struct BinaryTree* right;
}BTNode;



BTNode* BuyNode(BTDataType x);//创建节点
BTNode* CreatBinaryTree();//创建二叉树
void PreOrder(BTNode * root);// 二叉树前序遍历
void InOrder(BTNode* root);// 二叉树中序遍历
void PostOrder(BTNode* root);// 二叉树后序遍历
int BinaryTreeSize(BTNode * root); //二叉树节点个数
int BinaryTreeLeafSize(BTNode* root);//二叉树叶子节点个数
int BinaryTreeLevelKSize(BTNode* root, int k);//二叉树第k层节点个数
BTNode* BinaryTreeFind(BTNode* root, BTDataType x);//二叉树查找值为x的节点
int BinaryTreeDeep(BTNode* root);//二叉树的深度

