#define _CRT_SECURE_NO_WARNINGS
#include "seqlist.h"



void test1(SL* ps)
{
	SeqListInit(ps);
	SeqListPushBack(ps, 1);
	SeqListPushBack(ps, 3);
	SeqListPushBack(ps, 2);
	SeqListPopBack(ps);
	SeqListPopBack(ps);
	SeqListPopBack(ps);
	SeqListPopBack(ps);
	SeqListPrint(ps);
	SeqListDestroy(ps);
}
void test2(SL* ps)
{
	SeqListInit(ps);
	SeqListPushBack(ps, 1);
	SeqListPushBack(ps, 3);
	SeqListPushBack(ps, 2);
	SeqListPushHead(ps, 5); // 5 1 3 2
	SeqListInsert(ps, 0, 8);
	SeqListPrint(ps);
	SeqListDestroy(ps);
}


int main()
{
	SL seqlist = { 0 };
	//test1(&seqlist);
	test2(&seqlist);


}