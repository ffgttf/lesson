#include <stdio.h>
int Max3(int A,int B,int C)
 {
 	return A>B?A>C?A:C:B>C?B:C; 
 }
int DivideAndConquer(int List[], int left, int right)
{
	int MaxLeftSum, MaxRightSum;
	int MaxLeftBorderSum, MaxRightBorderSum;
	int LeftBorderSum, RightBordersum;
	int center, i;
	if (left == right) {
		if (List[left]>0)
			return List[left];
		else
			return 0;
	}

	center = (left + right) / 2;
	MaxLeftSum = DivideAndConquer(List, left, center);
	MaxRightSum = DivideAndConquer(List, center + 1, right);

	MaxLeftBorderSum = 0; LeftBorderSum = 0;
	for (i = center; i >= left; i--) {
		LeftBorderSum += List[i];
		if (LeftBorderSum > MaxLeftBorderSum)
			MaxLeftBorderSum = LeftBorderSum;
	}
	MaxRightBorderSum = 0; RightBordersum = 0;
	for (i = center + 1; i <= right; i++) {
		RightBordersum += List[i];
		if (RightBordersum > MaxRightBorderSum) {
			MaxRightBorderSum = RightBordersum;
		}
	}
	return Max3(MaxLeftSum, MaxRightSum, MaxLeftBorderSum + MaxRightBorderSum);
}
int MaxSubseqSum3(int List[], int N)
{
	return DivideAndConquer(List, 0, N - 1);
}
int main()
{
	int a[100], i, n;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d\n", &a[i]);
	}
	printf("%d", MaxSubseqSum3(a, n));
	return 0;
}

