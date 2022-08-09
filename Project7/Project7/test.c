#define _CRT_SECURE_NO_WARNINGS
#include "heap.h"

//void HeapTest1()
//{
//	HP hp = { 0 };
//	int a[] = { 27,15,19,18,28,34,65,49,25,37 };
//	HeapInit(&hp);
//	for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++)
//	{
//		HeapPush(&hp, a[i]);
//	}
//	HeapPrint(&hp);
//	HeapPop(&hp);
//	HeapPrint(&hp);
//
//
//}
void HeapSort(int* a , int n)
{
	//建堆
	//1.向上调 O(N*logN)
	//for (int i = 1; i < n; i++)
	//{
	//	AdjustUp(a, i);
	//}
	//2.向下调 O(N)
	for (int i = (n - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(a, n, i);
	}
	//排序
	//升序：建大堆
	//降序：建小堆
	int end = n - 1;
	while (end>0)
	{
		Swap(&a[0], &a[end]);
		AdjustDown(a, end, 0);
		end--;
	}
}

void HeapTest2()
{
	int a[] = { 27,15,19,18,28,34,65,49,25,37 };
	HeapSort(a, sizeof(a) / sizeof(a[0]));
	for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++)
	{
		printf("%d ", a[i]);
	}
}

int main()
{
	//HeapTest1();
	HeapTest2();
}