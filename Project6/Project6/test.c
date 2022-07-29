#define _CRT_SECURE_NO_WARNINGS
#include "queue.h"


void test1()
{
	Queue q = { 0 };
	QueueInit(&q);
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	/*QueuePop(&q);
	QueuePop(&q);*/
	printf("%d\n", QueueSize(&q));
}





int main()
{
	test1();
}