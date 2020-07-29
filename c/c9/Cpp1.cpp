#include <stdio.h>
#define N 4
int a[N];
void pay_amount (int dollars, int *twenties, int *tens, int *fives, int *ones) 
{
	*twenties = dollars / 20;
	*tens = (dollars - *twenties * 20) / 10;
	*fives = (dollars - *twenties * 20 - *tens * 10) / 5;
	*ones = dollars - *twenties * 20 - *tens * 10 - *fives * 5;
	twenties = &a[0];
	tens = &a[1];
	fives = &a[2];
	ones = &a[3];

}
int main ()
{
	int a, b, c, d, e;
	printf("Enter a dollar amount: ");
	scanf("%d",&a);
	pay_amount(a,&b,&c,&d,&e);
	printf("\n$20 bills: %d\n",b);
	printf("$10 bills: %d\n",c);
	printf("$5 bills: %d\n",d);
	printf("$1 bills: %d\n",e);

	return 0;
}


