#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

typedef int HPDataType;

typedef struct heap
{
	HPDataType* a;
	int size;
	int capacity;
}HP;


void HeapInit(HP* php);//堆初始化
void HeapDestroy(HP* php);//堆销毁
void HeapPush(HP* php, HPDataType x);//堆插入
void HeapPop(HP* php);//堆删除
void HeapPrint(HP* php);//堆打印
HPDataType HeapTop(HP* php);//返回堆顶值
bool HeapEmpty(HP* php);//判断堆是否为空
void AdjustUp(HPDataType* a, int size);//向上排序
void AdjustDown(HPDataType* a, int size, int parent);//向下排序
void Swap(HPDataType* data1, HPDataType* data2);//交换两个元素


