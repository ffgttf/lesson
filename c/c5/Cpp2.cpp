#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 10
int main()
{
	char a[N][N], ch = 'A';
	int i, j, m;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++)
            a[i][j] = '.';
	}
    srand((unsigned)time(NULL));
	i = rand() % N;
    j = rand() % N;
	a[i][j] = ch++;
    while (ch != ('Z'+1) && (a[i-1][j] == '.' || a[i+1][j] == '.' || a[i][j-1] == '.' || a[i][j+1] == '.')) {
		m = rand() % 4;
        switch (m) {
        case 0: if(i>0 && a[i-1][j] == '.') 
                    a[--i][j] = ch++; 
			break;
		case 1: if(i<N-1 && a[i+1][j] == '.') 
                    a[++i][j] = ch++; 
                break;
        case 2: if(j>0 && a[i][j-1] == '.') 
                    a[i][--j] = ch++; 
                break;
        case 3: if(j<N-1 && a[i][j+1] == '.') 
                    a[i][++j]=ch++; 
                break;
        }
	}
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++)
			printf("%c", a[i][j]);
		printf("\n");
	}
	return 0;
}


