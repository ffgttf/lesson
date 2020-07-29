#include <stdio.h>

int main()
{
	float a, b, c, d, e, f;
	printf("Enter amount of loan: ");
	scanf("%f", &a);
	printf("Enter interest rate: ");
	scanf("%f", &b);
	printf("Enter monthly payment: ");
	scanf("%f", &c);
	printf("\n");

	d = a - c + a * b / 12 * 0.01;
	e = d - c + d * b / 12 * 0.01;
	f = e - c + e * b / 12 * 0.01;

	printf("Balance remaining after first payment:%.2f\n", d);
	printf("Balance remaining after second payment:%.2f\n", e);
	printf("Balance remaining after third payment:%.2f\n", f);

	return 0;

    

}

