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










void SListPushBack(SLNode** ps, SListDateType x);//������β��
void SListPopBack(SLNode** ps);//������βɾ
void SListPushFront(SLNode** ps, SListDateType x);//������ͷ��
void SListPopFront(SLNode** ps);//������βɾ
SLNode* SListCreatNode(SListDateType x);//������ڵ㴴��
void SListPrint(SLNode* ps);//��ӡ����
SLNode* SListFind(SLNode* ps, SListDateType x);//���������,�����ҵ��ĳ�Ա��ַ
void SListInsertAfter(SLNode* pos, SListDateType x);//��������pos֮�����x
void SListEraseAfter(SLNode* pos);//������ɾ��pos֮���ֵ
void SListDestory(SLNode** ps);//ɾ��������



