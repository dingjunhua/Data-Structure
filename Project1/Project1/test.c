#define _CRT_SECURE_NO_WARNINGS
#include "seqlist.h"


int main()
{
	SL Seqlist = { 0 };
	SeqListInit(&Seqlist);
	SeqListPushBack(&Seqlist, 1);
	SeqListPushBack(&Seqlist, 2);
	SeqListPushBack(&Seqlist, 3);
	SeqListPushBack(&Seqlist, 4);
	SeqListPushBack(&Seqlist, 5);

	SeqListPrint(&Seqlist);

}