#include <stdio.h>
int main()
{
	int i;
	char str[100];
	while(scanf("%[^\n]",str[i]) && str[i] != '\n')
		i++;
	printf("%d\n",i);
	return 0;
}
