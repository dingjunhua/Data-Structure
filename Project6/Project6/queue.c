#define _CRT_SECURE_NO_WARNINGS
#include "queue.h"

QNode* QueueCreat(QDateType x)//创建一个节点
{
	QNode* newnode = (QNode*)malloc(sizeof(QNode));
	if (newnode == NULL)
	{
		printf("malloc fail\n");
		exit(-1);
	}
	newnode->data = x;
	newnode->next = NULL;
	return newnode;
}
void QueueInit(Queue* q)//队列初始化
{
	assert(q);
	q->head = NULL;
	q->tail = NULL;
}
void QueuePush(Queue* q, QDateType x)//队尾入队列
{
	assert(q);
	QNode* newnode = QueueCreat(x);
	if (q->head == NULL)
	{
		q->head = newnode;
		q->tail = newnode;
	}
	else
	{
		q->tail->next = newnode;
		q->tail = newnode;
	}
	
}
void QueuePop(Queue* q)//队头出队列
{
	assert(q);
	assert(!QueueEmepy(q));
	QNode* tmp = q->head->next;
	free(q->head);
	q->head = tmp;
	if (q->head == NULL)
	{
		q->tail = NULL;
	}
}
QDateType Queuehead(Queue* q)//获取队头元素
{
	assert(q);
	return q->head->data;
}
QDateType Queuetail(Queue* q)//获取队尾元素
{
	assert(q);
	return q->tail->data;
}
int QueueSize(Queue* q)//获取队列中的有效元素个数
{
	assert(q);
	if (q->tail == NULL)
	{
		return 0;
	}
	else
	{
		int size = 1;
		QNode* cur = q->head;
		while (cur->next)
		{
			size++;
			cur = cur->next;
		}
		return size;
	}
	
}
bool QueueEmepy(Queue* q)//检测队列是否为空
{
	assert(q);
	return q->head == NULL;
}
void QueueDestroy(Queue* q)//销毁队列
{
	assert(q);
	QNode* cur = q->head;
	while (cur)
	{
		QNode* tmp = cur->next;
		free(cur);
		cur = tmp;
	}
	q->head = NULL;
	q->tail = NULL;
}