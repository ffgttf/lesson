#include <stdio.h>

int main ()
{
	int a, b, i, j;
	printf("Enter a fraction: ");
	scanf("%d/%d", &a, &b);	
    if (a > b)
		for (i = b; a % i == 0;i--)
		    printf("In lowest tems:%d/%d\n",a / i, b / i);
	else if (a < b)
        for (j = a; b % j == 0;j--)
			printf("In lowest tems:%d/%d\n",a / j, b / j);
	else
		printf("In lowest tems:1\n");

	return 0 ;
}