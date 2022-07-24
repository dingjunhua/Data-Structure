#define _CRT_SECURE_NO_WARNINGS
#include "list.h"


LTNode* ListNodeCreat(LTDateType x)//�����½ڵ�
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




void ListNodePushBack(LTNode* phead, LTDateType x)//ѭ��˫������β��
{
	assert(phead);
	LTNode* tail = phead->prev;
	LTNode* newnode = ListNodeCreat(x);
	//newnode����
	tail->next = newnode;
	newnode->next = phead;
	newnode->prev = tail;
	phead->prev = newnode;
}
void ListNodePopBack(LTNode* phead)//ѭ��˫������βɾ
{
	assert(phead);
	assert(phead->next != phead);
	LTNode* tail = phead->prev;
	LTNode* prev = tail->prev;
	//ɾ��
	prev->next = phead;
	phead->prev = prev;
	free(tail);
	tail = NULL;
}
LTNode* ListNodeInit()//ѭ��˫�������ʼ��
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

void ListNodePrint(LTNode* phead)//ѭ��˫�������ӡ
{
	LTNode* cur = phead->next;
	while (cur != phead  )
	{
		printf("%d ", cur->date);
		cur = cur->next;
	}
	printf("\n");
}
void ListNodePushFront(LTNode* phead, LTDateType x)//ѭ��˫������ͷ��
{
	LTNode* next = phead->next;
	LTNode* newnode = ListNodeCreat(x);
	//����
	phead->next = newnode;
	next->prev = newnode;
	newnode->prev = phead;
	newnode->next = next;
}
void ListNodePopFront(LTNode* phead)//ѭ��˫������ͷɾ
{
	assert(phead);
	assert(phead->next != phead);
	LTNode* next = phead->next;
	LTNode* next_next = next->next;
	//ɾ��
	phead->next = next_next;
	next_next->prev = phead;
	free(next);
	next = NULL;
}
LTNode* ListNodeFind(LTNode* phead,LTDateType x)//��������Ԫ��
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
void ListNodeInsert(LTNode* pos, LTDateType x)//��posǰ����ڵ�
{
	assert(pos);
	LTNode* newnode = ListNodeCreat(x);
	LTNode* posPrev = pos->prev;
	//����
	posPrev->next = newnode;
	newnode->prev = posPrev;
	newnode->next = pos;
	pos->prev = newnode;
}
void ListNodeErase(LTNode* pos)//ɾ��posλ�õĽڵ�
{
	assert(pos);
	assert(pos->next != pos);
	LTNode* posPrev = pos->prev;
	LTNode* posNext = pos->next;
	//ɾ��
	posPrev->next = posNext;
	posNext->prev = posPrev;
	free(pos);
	pos = NULL;
}