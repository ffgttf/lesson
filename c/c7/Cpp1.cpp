#include <stdio.h>
#include <math.h>
double power(double ave0)
{
	double x,ave;
	printf("Enter a positive number: ");
	scanf("%lf",&x);
	ave=x;
	for(int i=1;i<=100;i++){
		ave0=(ave+x/ave)/2;
		if(fabs(ave0-ave)<0.00001*ave0)	
			break;
		else
			ave=ave0;
	}
	return ave0;
}
int main()
{
	double ave0;
	printf("Square root:%lf\n",power(ave0));
	return 0;
}

