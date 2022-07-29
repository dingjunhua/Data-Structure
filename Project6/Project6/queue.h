#pragma once
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>


typedef int QDateType;

typedef struct QueueNode //��������Ϊ���г�Ա
{
	struct QueueNode* next;
	QDateType data;
}QNode;


typedef struct Queue
{
	QNode* head;//���е�ͷ
	QNode* tail;//���е�β
}Queue;

void QueueInit(Queue* q);//���г�ʼ��
void QueuePush(Queue* q, QDateType x);//��β�����
void QueuePop(Queue* q);//��ͷ������
QDateType Queuehead(Queue* q);//��ȡ��ͷԪ��
QDateType Queuetail(Queue* q);//��ȡ��βԪ��
int QueueSize(Queue* q);//��ȡ�����е���ЧԪ�ظ���
bool QueueEmepy(Queue* q);//�������Ƿ�Ϊ��
void QueueDestroy(Queue* q);//���ٶ���
QNode* QueueCreat(QDateType x);//����һ���ڵ�

