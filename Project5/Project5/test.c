#define _CRT_SECURE_NO_WARNINGS
#include "Stack.h"


void test1()
{
	ST st = { 0 };
	StackInit(&st);
	StackPush(&st, 1);
	StackPush(&st, 2);
	StackPush(&st, 3);
	StackPush(&st, 4);
	StackPush(&st, 5);
	StackPrint(&st);
	/*StackPrint(&st);*/
}











int main()
{
	test1();
}