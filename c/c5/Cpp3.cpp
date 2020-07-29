#include <stdio.h>

int main(void)
{
	char ch[100],sh;
	int i,j,k,m;

	printf("Enter a sentence:");

	for(i = 0; i < 200; i++){
		scanf("%c",&ch[i]);
		if(ch[i] == '\n'){
			k = i;
			break;
		}
	}
	sh= ch[k-1];
	m= k - 1;

	printf("Reversal of sentence:");

	for(i = (k - 1); i >= 0; i--){

		if(ch[i] == ' '){
			for(j = i + 1; j < m; j++){
				printf("%c",ch[j]);
			}
			printf(" ");
			m = i;
		} 
		else if(i==0){
			for(j = 0; j < m; j++){
				printf("%c",ch[j]);

			}
		} 
	}
	printf("%c\n",sh);
	return 0; 
} 
