#include <stdio.h>

int main()
{
	int a[4][4];
	int i, j, sum=0;
	for(i = 0; i < 4 ; i++)
	{
		for(j = 0; j < 4 ; j++)
		{
			scanf("%d", a[i][j]);
		}
	}
	for(i = 0; i < 4 ; i++)
	{
		for(j = 0; j < 4 ; j++)
		{
			printf("%d", a[i][j]);
		}
	}
	printf("\n");

	for(i = 0, sum = 0; i < 4;i++)
	{
		for(j = 0;j < 4; j++)
		{
			sum += a[i][j];
		}
			printf("\nRow sums: %d", sum);
			sum = 0;
	}
	
	for(j = 0, sum = 0; j < 4;j++)
	{
		for(i = 0;i < 4; i++)
		{
			sum += a[i][j];
		}
			printf("\nColumn sums: %d", sum);
			sum = 0;
	}
	for(i = 0, sum = 0; i < 4;i++)
	{
		sum += a[i][i];
		printf("\nDisgonal sums: %d", sum);
	}
	for(j = 0, sum = 0; j < 4;j++)
	{
		sum += a[i][3-i];
		printf("%d", sum);
	}
	return 0;
}







	

