#include <stdio.h>
#define N 5
int main()
{
	int row, col, k, a[N][N], sum[N] = {0};
	for (row = 0; row < N; row++) {
		printf("Enter row %d: ",row + 1);
		for (col = 0; col < N; col++) {
			scanf("%d",&a[row][col]);
			sum[row] += a[row][col];
		}
	}
	printf("Row totals: ");
	for (row = 0; row < N; row++) {
		printf("%d ",sum[row]);	
	}
	printf("\nColumn totals: ");
	for (k = 0; k < N; k++)
		sum[k] = 0;
    for (row = 0; row < N; row++) {
		for (col = 0; col < N; col++) {
			sum[col] += a[row][col];
		}
	}
	for (col = 0; col < N; col++)
	printf("%d ",sum[col]);
	printf("\n");
	return 0;
}
