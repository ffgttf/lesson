# include <stdio.h>

int main ()
{
	int a, b, i;
	printf("Enter number of days in months: ");
	scanf("%d",&a);
	printf("Enter starting day of the week(1 = Sun,7 = Sat): ");
	scanf("%d",&b);
	for (i = 1;i < b;i++) {
		printf("\t");
	}
	for (i = 1;i <= a;i++) {
		printf("%d\t", i);
		if ((i + b - 1) % 7 == 0)
			printf("\n");
	}
	return 0;
}