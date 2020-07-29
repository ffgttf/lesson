#include<stdio.h>
#include<time.h>
clock_t start1, stop1, start2, stop2;
#define MAXK 1e7
float duration_1, duration_2;
int MaxSubseqSum2(int List[], int N)
{
	int i, j;
	int ThisSum, MaxSum=0;
	for(i=0;i<N;i++){
		ThisSum=0;
		for(j=i;j<N;j++){
			ThisSum+=List[j];
			if(ThisSum>MaxSum){
				MaxSum=ThisSum;
			}
		}
	}
	return MaxSum;
}
int MaxSubseqSum4(int List[], int N)
{
	int i;
	int ThisSum, MaxSum;
	
	ThisSum=MaxSum = 0;
	for(i=0;i<N;i++){
		ThisSum+=List[i];
		if(ThisSum>MaxSum){
			MaxSum=ThisSum;
		}
		else if(ThisSum<0){
			ThisSum=0;
		}
	}
	return MaxSum;
}
int main()
{
	int a[100],b,N,n,i,j;
	scanf("%d",&N);
	for(n=0;n<N;n++){
		scanf("%d",&a[n]);
	}
	start1 = clock();
	for(i=0;i<MAXK;i++){
		MaxSubseqSum2(a,n);
	}
	stop1 = clock();
	duration_1 = ((double)(stop1-start1))/CLK_TCK;
    start2 = clock();
	for(j=0;j<MAXK;j++){
		MaxSubseqSum4(a,n);
	}
	stop2 = clock();
	duration_2 = ((double)(stop2-start2))/CLK_TCK;
	printf("%f,%f\n",duration_1,duration_2);
	return 0;
}
