#include <stdio.h>
int ch[100];
int top=0;

void powera(int ch[100],int x)
{
	ch[top++] = x;
}
void powerb(int ch[100])
{
	top--;
}
char powerc(int ch[100])
{
	return ch[top-1];
}
int stack_overflow()
{
	return top > 100;
}
int main()
{
	char b, space;
	int i = 1, s1, s2;
	while (i = 1) {
        printf("Enter an RPN expression: ");
		for (;;) {
		    scanf("%c%c", &b, &space);
			if('0' <= b && b <= '9'){
				powera(ch, b-48);
				if(stack_overflow()){
					printf("Expression is too complex\n");
					i = 0;
					break;
				}
			}
			else if(b == '+'||b == '-'){
				s1 = powerc(ch);
				powerb(ch);
				if(top == 0){
					printf("Not enough operands in expression\n");
					break;
				}
				s2 = powerc(ch); powerb(ch);
				if(b == '+')
                    powera(ch, s1+s2);
                else if (b == '-')
                    powera(ch, s2-s1);
			}
			else if(b == '*'|| b == '/'){
				s1 = powerc(ch);
				powerb(ch);
				if(top == 0){
					printf("Not enough operands in expression\n");
					break;
				}
				s2 = powerc(ch); powerb(ch);
				if(b == '*')
                    powera(ch, s1*s2);
                else if (b == '/')
                    powera(ch, s2/s1);
			}
			else if(b == '='){
				printf("Value of expression: %d\n", powerc(ch));
				break;
			}
			else{
				i = 0;
				break;
			}
		}
	}
	return 0;
}

