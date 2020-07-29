#include "stdafx.h"
#include <ctype.h>
void create_magic_square(int n, char magic_square[99][99])
{
	int j, k, m;
	if (n >= 1 && n <= 99) {
		m = n / 2;
		k = 0;
		for (j = 1; j <= n * n; j++) {
			magic_square[k][m] = j;
			if ((j % n) == 0)
				k = k + 1;
			else {
				k = k - 1;
				m = (m + 1) % 5;
			}
			if (k < 0)
				k = 4;
		}
	}
}
void print_magic_square(int n, char magic_square[99][99])
{
	int k, m;
	for (k = 0; k < n; k++) {
		for (m = 0; m < n; m++)
			printf("%3d", magic_square[k][m]);
		printf("\n");
	}
}
int main()
{
	int n;
	char magic_square[99][99];
	printf("This program creats a magic square of specified size.\n");
	printf("The size must be an odd number between 1 and 99.\n");
	printf("Enter size of magic suqare:");
	scanf_s("%d", &n,99);
	create_magic_square(n, magic_square);
	print_magic_square(n,magic_square);
			printf("\n");
	return 0;
}