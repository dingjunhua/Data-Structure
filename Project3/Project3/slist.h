#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int SListDateType;

typedef struct Slist
{
	SListDateType date;
	struct Slist* next;

}SLNode;










void SListPushBack(SLNode** ps, SListDateType x);//单链表尾插
void SListPopBack(SLNode** ps);//单链表尾删
void SListPushFront(SLNode** ps, SListDateType x);//单链表头插
void SListPopFront(SLNode** ps);//单链表尾删
SLNode* SListCreatNode(SListDateType x);//单链表节点创建
void SListPrint(SLNode* ps);//打印链表
SLNode* SListFind(SLNode* ps, SListDateType x);//单链表查找,返回找到的成员地址
void SListInsertAfter(SLNode* pos, SListDateType x);//单链表在pos之后插入x
void SListEraseAfter(SLNode* pos);//单链表删除pos之后的值
void SListDestory(SLNode** ps);//删除单链表



