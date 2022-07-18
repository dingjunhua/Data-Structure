#define _CRT_SECURE_NO_WARNINGS
#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


typedef int SeqListDateType;

typedef struct s
{
	SeqListDateType* a;
	int sz;
	int capacity;
}SL;





void SeqListInit(SL* ps);//初始化顺序表
void SeqListCheckCapacity(SL* ps);//检查顺序表容量
void SeqListPushBack(SL* ps, SeqListDateType x);//顺序表尾插
void SeqListPopBack(SL* ps);//顺序表尾删；
void SeqListPushHead(SL* ps, SeqListDateType x);//顺序表头插
void SeqListPopHead(SL* ps);//顺序表头删
void SeqListPrint(SL* ps);//打印顺序表
void SeqListDestroy(SL* ps);//free空间
int SeqListFind(SL* ps, SeqListDateType x);//查找
void SeqListInsert(SL* ps, int pos, SeqListDateType x);//指定位置插入