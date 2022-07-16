#define _CRT_SECURE_NO_WARNINGS
#include "seqlist.h"


void SeqListInit(SL* ps)
{
	ps->a = NULL;
	ps->sz = 0;
	ps->capacity = 0;
}
void CheckCapacity(SL* ps)
{
	if (ps->sz == ps->capacity)//成员个数和容量大小相等时顺序表满
	{
		SLDateType* tmp = realloc(ps->a, ps->a == NULL ? sizeof(SLDateType) * 4 : sizeof(SLDateType) * ps->capacity * 2);//调整空间大小
		if (tmp == NULL)
		{
			perror("申请空间失败！");
		}
		ps->a = tmp;
	}
	
}
void SeqListPushBack(SL* ps, SLDateType x)
{
	CheckCapacity(ps);
	ps->a[ps->sz] = x;
	ps->sz++;
}
void SeqListPrint(SL* ps) 
{
	for (int i = 0; i < ps->sz; i++)
	{
		printf("%d ", ps->a[i]);
	}
}