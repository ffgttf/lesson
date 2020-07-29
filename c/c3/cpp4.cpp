# include <stdio.h>

int main ()
{
	float a, b, c, d, f;
	int e, i;
	printf("Enter amount of loan: ");
	scanf("%.2f",&a);
	printf("Enter interest rate: ");
	scanf("%.1f",&b);
	printf("Enter monthly payment: ");
	scanf("%.2f",&c);
	printf("Enter times of paying: ");
	scanf("%d",&e);
	printf("\n");
	d = a;
	for (i = 1;i <= e;i++) {
		f = d - c + a * b / 12 * 0.01;
		printf("Balance remaining after NO.%d payment:%.2f\n", i,f);
		d = f;
	}
	return 0;
}