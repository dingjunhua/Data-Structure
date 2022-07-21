#define _CRT_SECURE_NO_WARNINGS
#include "slist.h"




void SListPushBack(SLNode** ps, SListDateType x)//������β��
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
void SListPopBack(SLNode** ps)//������βɾ
{
	assert(*ps);
	SLNode* tail = *ps;
	SLNode* prev = NULL;
	if (tail->next == NULL)//���ֻ��һ������
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
void SListPushFront(SLNode** ps, SListDateType x)//������ͷ��
{
	SLNode* newnode = SListCreatNode(x);
	newnode->next = *ps;
	*ps = newnode;
}
void SListPopFront(SLNode** ps)//������ͷɾ
{
	assert(*ps);
	SLNode* cur = *ps;
	*ps = cur->next;
	free(cur);
	cur = NULL;
}





SLNode* SListCreatNode(SListDateType x)//������ڵ㴴��
{
	SLNode* newnode = (SLNode*)malloc(sizeof(SLNode));
	if (newnode == NULL)
	{
		printf("����ռ�ʧ�ܣ�\n");
		exit(-1);
	}
	newnode->date = x;
	newnode->next = NULL;
	return newnode;
}
void SListPrint(SLNode* ps)//��ӡ����
{
	SLNode* cur = ps;
	while (cur != NULL)
	{
		printf("%d ", cur->date);
		cur = cur->next;
	}
	printf("\n");
}
SLNode* SListFind(SLNode* ps, SListDateType x)//���������
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
void SListInsertAfter(SLNode* pos, SListDateType x)//��������pos֮�����x
{
	assert(pos);
	SLNode* newnode = SListCreatNode(x);
	newnode->next = pos->next;
	pos->next = newnode;
}
void SListEraseAfter(SLNode* pos)//������ɾ��pos֮���ֵ
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
void SListDestory(SLNode** ps)//ɾ��������
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