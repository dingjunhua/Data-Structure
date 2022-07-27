#define _CRT_SECURE_NO_WARNINGS
#include "Stack.h"

void StackInit(ST* ps)//栈初始化
{
	ps->a = NULL;
	ps->top = 0;
	ps->capacity = 0;
}

void StackDestory(ST* ps)//栈销毁
{
	assert(ps);
	ps->capacity = 0;
	ps->a = NULL;
	ps->top = 0;
	free(ps->a);
}
void StackPush(ST* ps, STDateType x)//进栈
{
	if (ps->top == ps->capacity)
	{
		int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		STDateType* tmp = realloc(ps->a, sizeof(ST) * newcapacity);
		if (tmp == NULL)
		{
			printf("增容失败！\n");
			exit(-1);
		}
		ps->a = tmp;
		ps->capacity = newcapacity;
	}
	ps->a[ps->top] = x;
	ps->top++;
	
}
void StackPop(ST* ps)//出栈
{
	assert(ps);
	assert(ps->top > 0);
	ps->top--;
}
void StackPrint(ST* ps)//打印栈
{
	while (!StackEmpty(ps))
	{
		printf("%d ", ps->a[(ps->top)-1]);
		StackPop(ps);
	}
	printf("\n");
}
STDateType StackTop(ST* ps)//栈顶值
{
	assert(ps);
	assert(!StackEmpty(ps));
	return ps->a[(ps->top)-1];
}
bool StackEmpty(ST* ps)//判断栈是否为空
{
	return ps->top == 0;
}
int StackSize(ST* ps)//判断栈的大小
{
	assert(ps);
	return ps->top;
}