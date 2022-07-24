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

LTNode* ListNodeCreat(LTDateType x);//�����½ڵ�
void ListNodePushBack(LTNode* phead,LTDateType x);//ѭ��˫������β��
void ListNodePopBack(LTNode* phead);//ѭ��˫������βɾ
void ListNodePushFront(LTNode* phead, LTDateType x);//ѭ��˫������ͷ��
void ListNodePopFront(LTNode* phead);//ѭ��˫������ͷɾ
LTNode* ListNodeInit();//ѭ��˫�������ʼ��
void ListNodePrint(LTNode* phead);//ѭ��˫�������ӡ
LTNode* ListNodeFind(LTNode* phead,LTDateType x);//��������ڵ�
void ListNodeInsert(LTNode* pos, LTDateType x);//��posǰ����ڵ�
void ListNodeErase(LTNode* pos);//ɾ��posλ�õĽڵ�

