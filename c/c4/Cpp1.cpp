#include <stdio.h>
int main()
{
	char ch;

		printf("Enter phone number: ");
		while((ch = getchar()) != '\n') {
		switch (ch) {
		case 'A': case 'B': case 'C':
			printf("2");
			break;
	    case 'D': case 'E': case 'F':
			printf("3");
			break;
		case 'G': case 'H': case 'I':
			printf("4");
			break;
		case 'J': case 'K': case 'L':
			printf("5");
			break;
		case 'M': case 'N': case 'O':
			printf("6");
			break;
		case 'P': case 'Q': case 'R': case 'S':
			printf("7");
			break;
		case 'T': case 'U': case 'V':
			printf("8");
			break;
		case 'X': case 'Y': case 'Z': case 'w':
			printf("9");
			break;
		default:
			printf("ch");
			break;
		}
	}
	putchar('\n');



	return 0;
}
