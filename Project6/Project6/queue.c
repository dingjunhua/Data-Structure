#define _CRT_SECURE_NO_WARNINGS
#include "queue.h"

QNode* QueueCreat(QDateType x)//����һ���ڵ�
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
void QueueInit(Queue* q)//���г�ʼ��
{
	assert(q);
	q->head = NULL;
	q->tail = NULL;
}
void QueuePush(Queue* q, QDateType x)//��β�����
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
void QueuePop(Queue* q)//��ͷ������
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
QDateType Queuehead(Queue* q)//��ȡ��ͷԪ��
{
	assert(q);
	return q->head->data;
}
QDateType Queuetail(Queue* q)//��ȡ��βԪ��
{
	assert(q);
	return q->tail->data;
}
int QueueSize(Queue* q)//��ȡ�����е���ЧԪ�ظ���
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
bool QueueEmepy(Queue* q)//�������Ƿ�Ϊ��
{
	assert(q);
	return q->head == NULL;
}
void QueueDestroy(Queue* q)//���ٶ���
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