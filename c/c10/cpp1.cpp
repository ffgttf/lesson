#include "stdafx.h"
#include<string.h>
#define N 20
char l[N], s[N];
void power(char p[N])
{
	if (strcmp(p, l) > 0)
		strcpy(l, p);
	else if (strcmp(p, s) < 0)
		strcpy(s, p);
}
void word(char b[N])
{
	printf("Enter word: ");
	gets_s(b,N);
}
int judge(char a[N])
{
	if (strlen(a) == 4)
		return 0;
	else
		return 1;
}
int main()
{
	char b[N];
	word(b);
	strcpy(s,b);
	strcpy(l,b);
	while (judge(b)) {
		power(b);
		word(b);
	}
	power(b);
	printf("Smallest word:%s\n", s);
	printf("Largest word:%s\n", l);
	return 0;
}


