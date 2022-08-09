#define _CRT_SECURE_NO_WARNINGS
#include "heap.h"



void HeapInit(HP* php)//堆初始化
{
	assert(php);
	php->a = NULL;
	php->capacity = 0;
	php->size = 0;
}
void HeapDestroy(HP* php)//堆销毁
{
	assert(php);
	free(php->a);
	php->a = NULL;
	php->capacity = 0;
	php->size = 0;
}
void Swap(HPDataType* data1, HPDataType* data2)//交换两个元素
{
	HPDataType tmp = *data1;
	*data1 = *data2;
	*data2 = tmp;
}
void AdjustUp(HPDataType* a, int child)//向上排序
{
	while (child>0)
	{
		int parent = (child - 1) / 2;
		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);
			child = parent;
		}
		else
		{
			break;
		}
	}
}
void AdjustDown(HPDataType* a,int size,int parent)//向下排序
{
	int child = parent * 2 + 1;

	while (child < size)
	{
		if (a[child + 1] > a[child] && child + 1 < size)
		{
			child++;
		}
		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}

}
void HeapPush(HP* php, HPDataType x)//堆插入
{
	assert(php);
	if (php->capacity == php->size)
	{
		int newcapacity = php->a == NULL ? 4 : php->capacity * 2;
		HPDataType* tmp = realloc(php->a, sizeof(HPDataType) * newcapacity);
		if (tmp == NULL)
		{
			printf("realloc fail\n");
			exit(-1);
		}
		php->a = tmp;
		php->capacity = newcapacity;
	}
	php->a[php->size] = x;
	php->size++;
	AdjustUp(php->a, php->size-1);
}

void HeapPop(HP* php)//堆删除
{
	Swap(&php->a[0], &php->a[php->size-1]);
	php->size--;
	AdjustDown(php->a,php->size,0);
}
void HeapPrint(HP* php)//堆打印
{
	assert(php);
	for (int i = 0; i < php->size; i++)
	{
		printf("%d ", php->a[i]);
	}
	printf("\n");
}
HPDataType HeapTop(HP* php)//返回堆顶值
{
	assert(php);
	assert(php->size > 0);
	return php->a[0];
}
bool HeapEmpty(HP* php)//判断堆是否为空
{
	assert(php);
	return php->size == 0;
}