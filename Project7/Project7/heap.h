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


void HeapInit(HP* php);//�ѳ�ʼ��
void HeapDestroy(HP* php);//������
void HeapPush(HP* php, HPDataType x);//�Ѳ���
void HeapPop(HP* php);//��ɾ��
void HeapPrint(HP* php);//�Ѵ�ӡ
HPDataType HeapTop(HP* php);//���ضѶ�ֵ
bool HeapEmpty(HP* php);//�ж϶��Ƿ�Ϊ��
void AdjustUp(HPDataType* a, int size);//��������
void AdjustDown(HPDataType* a, int size, int parent);//��������
void Swap(HPDataType* data1, HPDataType* data2);//��������Ԫ��


