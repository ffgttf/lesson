#include <stdio.h>
int main()
{
	char ch1[10], ch2[10];
    int i = 1;
	printf("Enter a first and last name: ");
	while(scanf("%c",&ch1[i]) && ch1[i] != ' ')
		i++;
	int j = 1;
	while(scanf("%c",&ch2[j]) && ch2[j] != '\n')
        j++;
	int k = 1;
	for(; k < j;k++)
		printf("%c",ch2[k]);
	printf(",%c\n",ch1[1]);
	return 0;
}
