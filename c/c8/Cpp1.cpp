#include <stdio.h>

char ch[100];
int top=0;

void powera(char ch[100],char a)
{
	ch[top++]=a;
}
void powerb(char ch[100])
{
	top--;
}
char powerc(char ch[100])
{
	return ch[top-1];
}
int powerd(char ch[100])
{
	return top==0;
}
void powere()
{
	printf("Parenteses/braces are nested properly\n");
}
void powerf()
{
	printf("Parenteses/braces are not nested properly\n");
}
int stack_overflow()
{
	return top > 100;
}
int main()
{
	char a;
	printf("Enter paranteses and/or brace: ");
	for(;;) {
		scanf("%c",&a);
		if(a=='{'||a=='(') {
			powera(ch,a);
			if(stack_overflow()) {
				printf("Stack overflow\n");
				break;
			}
		}
		else if(a==')') {
			if(powerc(ch)!='(') {
				powerf();
				break;
			}
			powerb(ch);
		}
		else if(a=='}') {
			if(powerc(ch)!='{') {
				powerf();
				break;
			}
			powerb(ch);
		}
		else {
			if(powerd(ch))
				powere();
			else
				powerf();
			break;
		}
	}
	return 0;
}
