#include <stdio.h>
int a[5];
void reduce (int numerator, int denominator, int *reduced_numerator, int *reduced_denominator)
{
	int i, j, t;
	i = numerator;
	j = denominator;
	while(1) {
		if(i == 0)
			break;
		t = j % i;
		j = i;
		i = t;
	}
	*reduced_numerator = numerator / j;
	*reduced_denominator = denominator / j;
}
int main ()
{
	int m, n, p, q;
	printf("Enter a fraction: ");
	scanf("%d/%d",&m,&n);
	reduce(m, n, &p, &q);
	printf("In lowest terms: %d/%d\n",p,q);
	return 0;
}

