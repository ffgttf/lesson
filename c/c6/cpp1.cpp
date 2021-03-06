#include "stdafx.h"
#include <stdbool.h>
void read_word(int counts[26])
{
	int i = 0;
	char x, a[100];
	while (scanf_s("%c", &x,100) && x != '\n') {
		a[i] = x; i++;
	}
	int k;
	for (k = 0; k < i; k++)
		counts[(int)a[k] - 97]++;
}

bool equal_array(int counts1[26], int counts2[26])
{
	int m, judge = 0;
	for (m = 0; m < 26; m++) {
		if (counts1[m] != counts2[m]) {
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
	while (1) {
		int word1[26] = { 0 }, word2[26] = { 0 };
		printf("Enter first word: ");
		read_word(word1);
		printf("Enter second word: ");
		read_word(word2);
		if (equal_array(word1, word2))
			printf("The words are anagrams.\n");
		else
			printf("The words are not anagrams.\n");
	}
	return 0;
}
