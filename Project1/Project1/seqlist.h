#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <stdio.h>
#include <stdlib.h>

typedef int SLDateType;


//创建结构体
//动态顺序表
typedef struct SqeList
{
	SLDateType* a;   //顺序表起始地址
	int sz;			 //顺序表成员个数
	int capacity;	 //顺序表容量
}SL;










void SeqListInit(SL* ps);     //顺序表初始化
void CheckCapacity(SL* ps);   //检查容量
void SeqListPushBack(SL* ps, SLDateType x);//顺序表尾插
void SeqListPrint(SL* ps); //打印顺序表
