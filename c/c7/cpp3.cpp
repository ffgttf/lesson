#include "stdafx.h"
int main()
{
	char ch[20],a[20];
	int i=0,j=0,m;
	printf("Enter a first and last name: ");
	while ((ch[i] = getchar()) != ' ')
		i++;
	while ((a[j] = getchar())!= '\n')
		j++;
	m = j;
	printf("You entered the name: ");
	for (j = 0; j < m; j++)
		printf("%c", a[j]);
	printf(",%c.\n", ch[0]);
    return 0;
}

