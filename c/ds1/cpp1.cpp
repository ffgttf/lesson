#include "stdafx.h"

int main()
{
	int a, b, c;
	char ch;
	scanf_s("%d", &a);
	while ((ch = getchar()) != '=') {
		scanf("%d", &b);
		switch (ch) {
		case'+':
			c = a + b;
			break;
		case'-':
			c = a - b;
			break;
		case '*':
			c = a * b;
			break;
		case '/':
			c = a / b;
			break;
		}
		a = c;
	}
	printf("%d\n", a);
    return 0;
}

