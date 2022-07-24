#define _CRT_SECURE_NO_WARNINGS
#include "list.h"


void test1()
{
	LTNode* plist = ListNodeInit();
	ListNodePushBack(plist, 1);
	ListNodePushBack(plist, 2);
	ListNodePushBack(plist, 3);
	ListNodePushFront(plist, 4);
	ListNodePushFront(plist, 5);
	/*ListNodePopFront(plist);
	ListNodePopFront(plist);*/
	ListNodePrint(plist);
	/*ListNodeInsert(ListNodeFind(plist, 3), 6);*/
	ListNodeErase(ListNodeFind(plist, 1));
	ListNodePrint(plist);

}	








int main()
{
	test1();
	return 0;
}