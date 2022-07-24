#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int LTDateType;

typedef struct ListNode
{
	int date;
	struct ListNode* prev;
	struct ListNode* next;
}LTNode;

LTNode* ListNodeCreat(LTDateType x);//创建新节点
void ListNodePushBack(LTNode* phead,LTDateType x);//循环双向链表尾插
void ListNodePopBack(LTNode* phead);//循环双向链表尾删
void ListNodePushFront(LTNode* phead, LTDateType x);//循环双向链表头插
void ListNodePopFront(LTNode* phead);//循环双向链表头删
LTNode* ListNodeInit();//循环双向链表初始化
void ListNodePrint(LTNode* phead);//循环双向链表打印
LTNode* ListNodeFind(LTNode* phead,LTDateType x);//查找链表节点
void ListNodeInsert(LTNode* pos, LTDateType x);//在pos前插入节点
void ListNodeErase(LTNode* pos);//删除pos位置的节点

