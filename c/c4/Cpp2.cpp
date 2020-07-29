#include <stdio.h>
int main()
{
	int i1, i2, j1, j2, op1, op2;
	char ch;

	printf("Enter two fractionsseperated by a sign: ");
	scanf("%d/%d%c%d/%d", &i1, &i2, &ch, &j1, &j2);
    if (ch == '+') {
		op1 = i1 * j2 + j1 * i2;
		op2 = i2 * j2;
		int a, b, g;
		a = op1, b = op2;
		for(;;) {
			if (a == 0)
				break;
			g = b % a;
			b = a;
			a = g;
		}
		printf("The sum is %d/%d\n", op1/b, op2/b); 
	}
	else if (ch == '-') {
		op1 = i1 * j2 - j1 * i2;
		op2 = i2 * j2;
		int a, b, g;
		a = op1, b = op2;
		for(;;) {
			if (a == 0)
				break;
			g = b % a;
			b = a;
			a = g;
		}
		printf("The sum is %d/%d\n", op1/b, op2/b); 
	}
	else if (ch == '*') {
		op1 = i1 * j1;
		op2 = i2 * j2;
		int a, b, g;
		a = op1, b = op2;
		for(;;) {
			if (a == 0)
				break;
			g = b % a;
			b = a;
			a = g;
		}
		printf("The sum is %d/%d\n", op1/b, op2/b); 
	}
	else if (ch == '/') {
		op1 = i1 * j2;
		op2 = i2 * j1;
		int a, b, g;
		a = op1, b = op2;
		for(;;) {
			if (a == 0)
				break;
			g = b % a;
			b = a;
			a = g;
		}
		printf("The sum is %d/%d\n", op1/b, op2/b); 
	}
	return 0;
}



