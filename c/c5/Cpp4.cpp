#include <stdio.h>
#include <ctype.h>
int main()
{
	char c;
	int j, x, char_count[26], sum_1, sum_2, sum_3, sum_4;
	for( x= 0; x < 26; x++) {
		char_count[x] = 0;
	}
	printf("Enter first word: ");
	while((c = getchar()) != '\n') {
	   if(isalpha(c)) 
	   {
		   c = tolower(c); 
		   ++char_count[c-'a'];
	   }
	}
	for (j=0;j<c;j++) {
		sum_1 += char_count[j];
	}
	for( x= 0; x < 26; x++) {
		char_count[x] = 0;
	}
	printf("Enter second word: ");
	while((c = getchar()) != '\n') {
	   if(isalpha(c)) 
	   {
		   c = tolower(c); 
		   ++char_count[c-'a'];
	   }
   }
	for (j=0;j<c;j++) {
		sum_2 += char_count[j];
	}
	if (sum_1 - sum_2 == 0)
		printf("The words are anagrams.\n");
	else
		printf("The words are not anagrams.\n");
	
	
	
	
	
	for( x= 0; x < 26; x++) {
		char_count[x] = 0;
	}
	printf("\nEnter first word: ");
	while((c = getchar()) != '\n') {
	   if(isalpha(c)) 
	   {
		   c = tolower(c); 
		   ++char_count[c-'a'];
	   }
	}
	for (j=0;j<c;j++) {
		sum_3 += char_count[j];
	}
	for( x= 0; x < 26; x++) {
		char_count[x] = 0;
	}
	printf("Enter second word: ");
	while((c = getchar()) != '\n') {
	   if(isalpha(c)) 
	   {
		   c = tolower(c); 
		   ++char_count[c-'a'];
	   }
   }
	for (j=0;j<c;j++) {
		sum_4 += char_count[j];
	}
	if (sum_3 - sum_4 == 0)
		printf("The words are anagrams.\n");
	else
		printf("The words are not anagrams.\n");
	return 0;
}




