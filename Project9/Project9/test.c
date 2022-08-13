#define _CRT_SECURE_NO_WARNINGS
#include "sort.h"

int main()
{
	int a[] = { 9,8,7,6,5,4,3,2,1 };
	/*InsertSort(a, sizeof(a) / sizeof(a[0]));
	SortPrint(a, sizeof(a) / sizeof(a[0]));*/
	ShellSort(a, sizeof(a) / sizeof(a[0]));
	SortPrint(a, sizeof(a) / sizeof(a[0]));


	return 0;
}