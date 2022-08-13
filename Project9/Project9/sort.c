#define _CRT_SECURE_NO_WARNINGS
#include "sort.h"

void InsertSort(int* a, int n)//≤Â»Î≈≈–Ú
{
	for(int i = 0; i < n - 1; i++)
	{
		int end = i;
		int tmp = a[end + 1];
		while (end >= 0)
		{
			if (tmp < a[end])
			{
				a[end + 1] = a[end];
				end--;
			}
			else
			{
				break;
			}
		}
		a[end + 1] = tmp;
	}

}
void SortPrint(int* a, int n)//¥Ú”° ˝¡–
{
	for(int i =0;i<n;i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}
void ShellSort(int* a, int n)//œ£∂˚≈≈–Ú
{
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		for (int i = 0; i < n - gap; i++)
		{
			int end = i;
			int tmp = a[end + gap];
			while (end >= 0)
			{
				if (tmp < a[end])
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else
				{
					break;
				}
			}
			a[end + gap] = tmp;
		}
	}
}