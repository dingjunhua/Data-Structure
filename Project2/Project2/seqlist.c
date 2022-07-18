#define _CRT_SECURE_NO_WARNINGS
#include "seqlist.h"


void SeqListInit(SL* ps)//��ʼ��˳���
{
	ps->a = NULL;
	ps->sz = 0;
	ps->capacity = 0;
}
void SeqListCheckCapacity(SL* ps)//���˳�������
{
	if (ps->sz == ps->capacity)
	{
		int newcapacity = ps->a == NULL ? 4 : ps->capacity * 2;//�ж�a�Ƿ�Ϊ��
		SeqListDateType* tmp = (SeqListDateType*)realloc(ps->a, sizeof(SeqListDateType) * newcapacity);//�����������ĵ�ַ
		if (tmp == NULL)
		{
			perror("SeqListCheckCapacity");
		}
		ps->a = tmp;
		ps->capacity = newcapacity;
	}

}
void SeqListPushBack(SL* ps, SeqListDateType x)//˳���β��
{
	SeqListCheckCapacity(ps);
	ps->a[ps->sz] = x;
	ps->sz++;
}
void SeqListDestroy(SL* ps)//free�ռ�
{
	free(ps->a);
}
void SeqListPopBack(SL* ps)//˳���βɾ
{
	if (ps->sz >= 0)
	{
		ps->sz--;
	}
}
void SeqListPushHead(SL* ps, SeqListDateType x)//˳���ͷ��
{
	SeqListCheckCapacity(ps);
	for (int i = ps->sz-1 ; i >= 0;i--)
	{
		ps->a[i + 1] = ps->a[i];
	}
	ps->a[0] = x;
	ps->sz++;
}
void SeqListPopHead(SL* ps)//˳���ͷɾ
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
void SeqListPrint(SL* ps)//��ӡ˳���
{
	for (int i = 0; i < ps->sz; i++)
	{
		printf("%d ", ps->a[i]);
	}
	printf("\n");
}
int SeqListFind(SL* ps, SeqListDateType x)//����
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
void SeqListInsert(SL* ps, int pos, SeqListDateType x)//ָ��λ�ò���
{
	assert(pos >= 0 && pos <= ps->sz);//���pos�Ƿ�Ϸ�
	SeqListCheckCapacity(ps);
	for (int i = ps->sz-1; i >= pos; i--)
	{
		ps->a[i+1] = ps->a[i];
	}
	ps->a[pos] = x;
	ps->sz++;
}