#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <stdio.h>
#include <stdlib.h>

typedef int SLDateType;


//�����ṹ��
//��̬˳���
typedef struct SqeList
{
	SLDateType* a;   //˳�����ʼ��ַ
	int sz;			 //˳����Ա����
	int capacity;	 //˳�������
}SL;










void SeqListInit(SL* ps);     //˳����ʼ��
void CheckCapacity(SL* ps);   //�������
void SeqListPushBack(SL* ps, SLDateType x);//˳���β��
void SeqListPrint(SL* ps); //��ӡ˳���
