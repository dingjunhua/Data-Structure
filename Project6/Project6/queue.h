#pragma once
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>


typedef int QDateType;

typedef struct QueueNode //用链表作为队列成员
{
	struct QueueNode* next;
	QDateType data;
}QNode;


typedef struct Queue
{
	QNode* head;//队列的头
	QNode* tail;//队列的尾
}Queue;

void QueueInit(Queue* q);//队列初始化
void QueuePush(Queue* q, QDateType x);//队尾入队列
void QueuePop(Queue* q);//队头出队列
QDateType Queuehead(Queue* q);//获取队头元素
QDateType Queuetail(Queue* q);//获取队尾元素
int QueueSize(Queue* q);//获取队列中的有效元素个数
bool QueueEmepy(Queue* q);//检测队列是否为空
void QueueDestroy(Queue* q);//销毁队列
QNode* QueueCreat(QDateType x);//创建一个节点

