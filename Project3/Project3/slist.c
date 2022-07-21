#define _CRT_SECURE_NO_WARNINGS
#include "slist.h"




void SListPushBack(SLNode** ps, SListDateType x)//单链表尾插
{
	SLNode* newnode = SListCreatNode(x);
	if (*ps == NULL)
	{
		*ps = newnode;
	}
	else
	{
		SLNode* tail = *ps;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		tail->next = newnode;
	}

}
void SListPopBack(SLNode** ps)//单链表尾删
{
	assert(*ps);
	SLNode* tail = *ps;
	SLNode* prev = NULL;
	if (tail->next == NULL)//如果只有一个链表
	{
		*ps = NULL;
		free(tail);
		tail = NULL;
	}
	else
	{
		while (tail->next)
		{
			prev = tail;
			tail = tail->next;
		}
		prev->next = NULL;
		free(tail);
		tail = NULL;
	}

}
void SListPushFront(SLNode** ps, SListDateType x)//单链表头插
{
	SLNode* newnode = SListCreatNode(x);
	newnode->next = *ps;
	*ps = newnode;
}
void SListPopFront(SLNode** ps)//单链表头删
{
	assert(*ps);
	SLNode* cur = *ps;
	*ps = cur->next;
	free(cur);
	cur = NULL;
}





SLNode* SListCreatNode(SListDateType x)//单链表节点创建
{
	SLNode* newnode = (SLNode*)malloc(sizeof(SLNode));
	if (newnode == NULL)
	{
		printf("申请空间失败！\n");
		exit(-1);
	}
	newnode->date = x;
	newnode->next = NULL;
	return newnode;
}
void SListPrint(SLNode* ps)//打印链表
{
	SLNode* cur = ps;
	while (cur != NULL)
	{
		printf("%d ", cur->date);
		cur = cur->next;
	}
	printf("\n");
}
SLNode* SListFind(SLNode* ps, SListDateType x)//单链表查找
{
	while (ps)
	{
		if (ps->date == x)
		{
			return ps;
		}
		else
		{
			ps = ps->next;
		}
	}
	return NULL;
}
void SListInsertAfter(SLNode* pos, SListDateType x)//单链表在pos之后插入x
{
	assert(pos);
	SLNode* newnode = SListCreatNode(x);
	newnode->next = pos->next;
	pos->next = newnode;
}
void SListEraseAfter(SLNode* pos)//单链表删除pos之后的值
{
	assert(pos);
	if (pos->next ==NULL)
	{
		return;
		
	}
	else
	{
		SLNode* cur = pos->next;
		pos->next = cur->next;
		free(cur);
		cur = NULL;
	}
}
void SListDestory(SLNode** ps)//删除单链表
{
	SLNode* cur = *ps;
	while (cur)
	{
		SLNode* next = cur->next;
		free(cur);
		cur = next;
	}
	*ps = NULL;
}