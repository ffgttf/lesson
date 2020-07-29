# include <stdio.h>

int main ()
{
	float a, max;
	max = 0;
	do {
		printf("Enter a number: ");
		scanf("%f",&a);
		if (a > max) {
			max = a;
		}
	} while (a > 0);
		printf("The largest number entered was:%.2f\n",max);
	
	return 0;
}