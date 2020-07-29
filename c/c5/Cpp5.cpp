#include<stdio.h>
int main()
{
	int a[99][99], i, j, k, m, n;
	printf("This program creats a magic square of specified size.\n");
	printf("The size must be an odd number between 1 and 99.\n");
	printf("Enter size of magic suqare:");
	scanf("%d",&i);
	if(i>=1 && i<=99) {
		for (k = 0; k < i; k++) {
			for (m = 0; m < i; m++){
				a[k][m] = 0;
			}
		}
		for (j = 1; j < i*i; j++) {
			for (k = 0; k >= 0; k--) {
				for (m = i / 2;m < i; m++) {
					if (m = i)
						m = 0;
					if (k = -1)
						k = i - 1;
					if (a[k][m] !=0) {
						if (k == i - 1 && m != 0) {
							k = 1;
							m = m - 1;
						}
						else if (k != i - 1 && m == 0) {
							k = k + 2;
							m = i - 1;
						}
						else if (k != i - 1 && m != 0) {
							k = k + 2;
							m = m - 1;
						}
						else if (k == i - 1 && m == 0) {
							k = 1;
							m = i - 1;
						}
						a[k][m] = j;
					}
					else if (a[k][m] == 0) {
						a[k][m] = j;
					}
				}
			}
		}
	}
    for(k = 0; k < i; k++)
        for(m = 0; m < i; m++)
			printf("%3d", a[k][m]);
		printf("\n");
		return 0;
}

