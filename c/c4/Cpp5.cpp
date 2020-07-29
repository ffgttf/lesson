#include <stdio.h>
int main()
{
	char c;
	int letters = 0,
		space = 0;
	float a;

	printf("Enter a sentence : ");
	while((c = getchar()) != '\n') {
		if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z')
			letters++;
		else if (c == ' ')
			space++;
	}
	a = float(letters + 1) / float(space + 1);

	printf("Average word length: %.1f\n",a);
	return 0;
}
	



