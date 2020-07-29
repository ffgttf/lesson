#include <stdio.h>

int main()
{
	int a[4][4];
	int i, j, sum;
	for(i = 0; i < 4; i++){
		for(j = 0; j < 4; j++){
			scanf("%d", &a[i][j]);
		}
	}
	for(i = 0; i < 4; i++){
		for(j = 0; j < 4; j++){
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
	printf("\nRow sums:");
	for(i = 0, sum = 0; i < 4; i++){
		for(j = 0; j < 4; j++){
			sum += a[i][j];
		}
		printf("%d ", sum);
		sum = 0;
	}
	printf("\nColumn sums:");
	for(j = 0, sum = 0; j < 4; j++){
		for(i = 0; i < 4; i++){
			sum += a[i][j];
		}
		printf("%d ", sum);
		sum = 0;
	}
	printf("\nDiagonal sums:");
	for(i = 0, sum = 0; i < 4; i++){
		sum += a[i][i];
	}
	printf("%d ", sum);
	for(i = 0, sum = 0; i < 4; i++){
		sum += a[i][3-i];
	}
	printf("%d\n", sum);
	return 0;
}




