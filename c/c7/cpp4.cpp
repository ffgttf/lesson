#include "stdafx.h"
#define N 100
void selection_sort(int a[N], int n)
{
	int j, i, t;
	for (i = 0; i<n; i++)
		for (j = 0; j<n - 1; j++)
			if (a[j]>a[j + 1])
			{
				t = a[j];
				a[j] = a[j + 1];
				a[j + 1] = t;
			}
}
int main()
{
	int a[N], i, m, j;
	scanf_s("%d", &m);
	for (i = 0; i < m; i++)
		scanf_s("%d", &a[i]);
	selection_sort(a, m);
	for (j = 0; j < m; j++)
		printf("%d ",a[j]);
	printf("\n");
    return 0;
}

