#include "stdafx.h"
#include <stdbool.h>
#include <ctype.h>
#define N 100
bool equal_array(int u, char *p)
{
	int m, judge = 0;
	for (m = 0; m < u / 2; m++) {
		if (*(p + m)!= *(p+(u-m -1))){
    		judge = 1;
			break;
		}
	}
	if (judge == 0)
		return true;
	else
		return false;
}

int main()
{
	int i = 0, k;
	char b[N], x;
	for(;;){
		printf("Enter a message: ");
		while((x = getchar()) != '\n'){
			if (isalpha(x)) {
				x = tolower(x);
				b[i++] = x;
			}
		}
		if (equal_array(i,b))
			printf("Palidrome\n");
		else
			printf("Not a Palidrome\n");
	}
	return 0;
}
