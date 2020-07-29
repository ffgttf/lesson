#include <stdio.h>
int main()
{
	char ch;
	int a, b;

	printf("Enter a 12-hour time: ");
	scanf("%d:%d %c", &a, &b, &ch);
	if (ch == 'P') {
		a = a + 12;
	}
	printf("Equivalent 24-hour time:%d:%d\n", a, b);
	return 0;
}
