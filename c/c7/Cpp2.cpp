#include "stdafx.h"
#define N 80
char power(char x, int n)
{
	if (x >= 'A' && x <= 'Z')
		x = ((x - 'A') + n) % 26 + 'A';
	else if (x >='a' && x <= 'z')
		x = ((x - 'a') + n) % 26 + 'a';
	return x;
}
int main(void)
{
	char ch[N];
	int i = 0, n, j;
	printf("Enter message to be encrypted: ");
	while ((ch[i] = getchar()) != '\n')
		i++;
	printf("Enter shift amount (1-25): ");
	scanf_s("%d", &n);
	j = i;
	for (i = 0; i < j; i++) {
		if ('A' <= ch[i] && ch[i] <= 'Z')
			ch[i] = power(ch[i], n);
		else if ('a' <= ch[i] && ch[i] <= 'z')
			ch[i] = power(ch[i], n);
	}
	printf("Encrypted message: ");
	for (i = 0; i < j; i++)
		printf("%c", ch[i]);
	printf("\n");
	return 0;
}
