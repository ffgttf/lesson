#include "stdafx.h"
#include "stdlib.h"
#define N 100
typedef char ElementType;
typedef struct TNode *Position;
typedef Position BinTree;
struct TNode {
	ElementType Data;
	BinTree Left;
	BinTree Right;
};
int GetHeight(BinTree BT)
{
	int HL, HR, MaxH;
	if (BT) {
		HL = GetHeight(BT->Left);
		HR = GetHeight(BT->Right);
		MaxH = HL > HR ? HL : HR;
		return(MaxH + 1);
	}
	else
		return 0;
}
BinTree hy(ElementType xx[], ElementType zx[], int len)
{
	BinTree BT;
	int i = 0;
	if (!len)	
		return NULL;
	else
	{
		TNode* node = new TNode;
		BT = (BinTree)malloc(sizeof(struct TNode));
		BT->Data = xx[0];
		while (zx[i] != xx[0])	
			i++;
		BT->Left = hy(xx + 1, zx, i);
		BT->Right = hy(xx + i + 1, zx + i + 1, len - i - 1);
	}
	return BT;
}
int main()
{
	int n;
	ElementType xx[N], zx[N];
	BinTree BT;
	scanf("%d", &n);
	scanf("%s", xx);
	scanf("%s", zx);
	BT = hy(xx, zx, n);
	printf("%d\n", GetHeight(BT));
}
