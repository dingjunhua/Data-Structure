#define _CRT_SECURE_NO_WARNINGS
#include "seqlist.h"


void SeqListInit(SL* ps)//初始化顺序表
{
	ps->a = NULL;
	ps->sz = 0;
	ps->capacity = 0;
}
void SeqListCheckCapacity(SL* ps)//检查顺序表容量
{
	if (ps->sz == ps->capacity)
	{
		int newcapacity = ps->a == NULL ? 4 : ps->capacity * 2;//判断a是否为空
		SeqListDateType* tmp = (SeqListDateType*)realloc(ps->a, sizeof(SeqListDateType) * newcapacity);//申请新容量的地址
		if (tmp == NULL)
		{
			perror("SeqListCheckCapacity");
		}
		ps->a = tmp;
		ps->capacity = newcapacity;
	}

}
void SeqListPushBack(SL* ps, SeqListDateType x)//顺序表尾插
{
	SeqListCheckCapacity(ps);
	ps->a[ps->sz] = x;
	ps->sz++;
}
void SeqListDestroy(SL* ps)//free空间
{
	free(ps->a);
}
void SeqListPopBack(SL* ps)//顺序表尾删
{
	if (ps->sz >= 0)
	{
		ps->sz--;
	}
}
void SeqListPushHead(SL* ps, SeqListDateType x)//顺序表头插
{
	SeqListCheckCapacity(ps);
	for (int i = ps->sz-1 ; i >= 0;i--)
	{
		ps->a[i + 1] = ps->a[i];
	}
	ps->a[0] = x;
	ps->sz++;
}
void SeqListPopHead(SL* ps)//顺序表头删
{
	if (ps->sz >= 0)
	{
		for (int i = 0; i < ps->sz - 1; i++)
		{
			ps->a[i] = ps->a[i + 1];
		}
		ps->sz--;
	}
}
void SeqListPrint(SL* ps)//打印顺序表
{
	for (int i = 0; i < ps->sz; i++)
	{
		printf("%d ", ps->a[i]);
	}
	printf("\n");
}
int SeqListFind(SL* ps, SeqListDateType x)//查找
{
	for (int i = 0; i < ps->sz; i++)
	{
		if (ps->a[i] == x)
		{
			return i;
		}
	}
	return -1;
}
void SeqListInsert(SL* ps, int pos, SeqListDateType x)//指定位置插入
{
	assert(pos >= 0 && pos <= ps->sz);//检查pos是否合法
	SeqListCheckCapacity(ps);
	for (int i = ps->sz-1; i >= pos; i--)
	{
		ps->a[i+1] = ps->a[i];
	}
	ps->a[pos] = x;
	ps->sz++;
}