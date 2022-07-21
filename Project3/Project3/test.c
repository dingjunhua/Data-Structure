#define _CRT_SECURE_NO_WARNINGS
#include "slist.h"


void test1()
{
	SLNode* plist = NULL;
	SListPushBack(&plist, 1);
	SListPushBack(&plist, 2);
	SListPushBack(&plist, 3);
	SListPushFront(&plist, 8);
	SListPushFront(&plist, 6);
	SListPushFront(&plist, 7);
	SListPrint(plist);
	SListPopFront(&plist);
	SListPopBack(&plist);
	SListPrint(plist);		
}

void test2()
{
	SLNode* plist = NULL;
	SListPushBack(&plist, 1);
	SListPushBack(&plist, 2);
	SListPushBack(&plist, 3);
	printf("%p\n", SListFind(plist, 1));
	printf("%p\n", SListFind(plist, 2));
	printf("%p\n", SListFind(plist, 3));
	printf("%p\n", SListFind(plist, 4));
}
void test3()
{
	SLNode* plist = NULL;
	SListPushBack(&plist, 1);
	SListPushBack(&plist, 2);
	SListPushBack(&plist, 3);
	SListInsertAfter(SListFind(plist, 2), 5);
	SListInsertAfter(SListFind(plist, 5), 6);
	SListDestory(&plist);
	SListPrint(plist);

}



int main()
{
	//test1();
	//test2();
	test3();

}