#pragma once
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>

typedef int STDateType;
typedef struct Stack
{
	STDateType* a;
	int top;
	int capacity;
}ST;



void StackInit(ST* ps);//栈初始化
void StackDestory(ST* ps);//栈销毁
void StackPush(ST* ps,STDateType x);//进栈
void StackPop(ST* ps);//出栈
void StackPrint(ST* ps);//打印栈
STDateType StackTop(ST* ps);//栈顶值
bool StackEmpty(ST* ps);//判断栈是否为空
int StackSize(ST* ps);//判断栈的大小