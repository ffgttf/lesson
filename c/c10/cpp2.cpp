#include "stdafx.h"
#include<string.h>
#define N 100
void selection_sort(char a[N],int n)
{
	char t;
	int i, j;
	for (i = 0; i < n; i++)
		for (j = n - 1; j > i; j--)
			if(a[j-1]>a[j]){
				t = a[j-1];
				a[j-1] = a[j];
				a[j] = t;
			}
}
int main()
{
	char a[N];
	int i, j, m;
	gets_s(a, N);
	m = strlen(a);
	selection_sort(a, m);
	printf("%s", a);
	printf("\n");
    return 0;
}

