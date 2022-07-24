#define _CRT_SECURE_NO_WARNINGS
#include "list.h"


LTNode* ListNodeCreat(LTDateType x)//创建新节点
{
	LTNode* newnode = (LTNode*)malloc(sizeof(LTNode));
	if (newnode == NULL)
	{
		perror("ListNodeCreat");
	}
	newnode->date = x;
	newnode->next = NULL;
	newnode->prev = NULL;
	return newnode;
}	




void ListNodePushBack(LTNode* phead, LTDateType x)//循环双向链表尾插
{
	assert(phead);
	LTNode* tail = phead->prev;
	LTNode* newnode = ListNodeCreat(x);
	//newnode链接
	tail->next = newnode;
	newnode->next = phead;
	newnode->prev = tail;
	phead->prev = newnode;
}
void ListNodePopBack(LTNode* phead)//循环双向链表尾删
{
	assert(phead);
	assert(phead->next != phead);
	LTNode* tail = phead->prev;
	LTNode* prev = tail->prev;
	//删除
	prev->next = phead;
	phead->prev = prev;
	free(tail);
	tail = NULL;
}
LTNode* ListNodeInit()//循环双向链表初始化
{
	LTNode* phead = (LTNode*)malloc(sizeof(LTNode));
	if (phead == NULL)
	{
		perror("ListNodeInit");
	}
	phead->prev = phead;
	phead->next = phead;
	return phead;
}

void ListNodePrint(LTNode* phead)//循环双向链表打印
{
	LTNode* cur = phead->next;
	while (cur != phead  )
	{
		printf("%d ", cur->date);
		cur = cur->next;
	}
	printf("\n");
}
void ListNodePushFront(LTNode* phead, LTDateType x)//循环双向链表头插
{
	LTNode* next = phead->next;
	LTNode* newnode = ListNodeCreat(x);
	//插入
	phead->next = newnode;
	next->prev = newnode;
	newnode->prev = phead;
	newnode->next = next;
}
void ListNodePopFront(LTNode* phead)//循环双向链表头删
{
	assert(phead);
	assert(phead->next != phead);
	LTNode* next = phead->next;
	LTNode* next_next = next->next;
	//删除
	phead->next = next_next;
	next_next->prev = phead;
	free(next);
	next = NULL;
}
LTNode* ListNodeFind(LTNode* phead,LTDateType x)//查找链表元素
{
	LTNode* cur = phead->next;
	while (cur != phead)
	{
		if (cur->date == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}
void ListNodeInsert(LTNode* pos, LTDateType x)//在pos前插入节点
{
	assert(pos);
	LTNode* newnode = ListNodeCreat(x);
	LTNode* posPrev = pos->prev;
	//插入
	posPrev->next = newnode;
	newnode->prev = posPrev;
	newnode->next = pos;
	pos->prev = newnode;
}
void ListNodeErase(LTNode* pos)//删除pos位置的节点
{
	assert(pos);
	assert(pos->next != pos);
	LTNode* posPrev = pos->prev;
	LTNode* posNext = pos->next;
	//删除
	posPrev->next = posNext;
	posNext->prev = posPrev;
	free(pos);
	pos = NULL;
}