#include<stdio.h>
int MaxSubseqsum1(int List[],int N)
{
	int i, j, k;
	int ThisSum, MaxSum = 0;
	for(i=0;i<N;i++){
		for(j=i;j<N;j++){
			ThisSum=0;
			for(k=i;k<=j;k++){
				ThisSum+=List[k];
			}
			if(ThisSum>MaxSum)
				MaxSum=ThisSum;
		}
	}
	return MaxSum;
}
int main()
{
	int a[100],b,N,n;
	scanf("%d",&N);
	for(n=0;n<N;n++){
		scanf("%d",&a[n]);
	}
	b=MaxSubseqsum1(a,n);
	printf("%d\n",b);
	return 0;
}
