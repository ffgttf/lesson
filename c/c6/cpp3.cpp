#include "stdafx.h"
#include <math.h>
int power(int n, int x)
{
	int s = 1;
	while (n > 0) {
		n = n - 1;
		s *= x;
		return s;
	}
}
int main()
{
	int x, n;
	scanf_s("%d %d", &x, &n);
	printf("%d\n", power(n, x));
	return 0;
}

