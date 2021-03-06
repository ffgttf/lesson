#include "stdafx.h"
#include "stdlib.h"
typedef struct LNode* PtrToLNode;
struct LNode {
	int coef;
	int expon;
	PtrToLNode next;
};
typedef PtrToLNode Position;
typedef PtrToLNode List;
void attach(int coef, int expon, PtrToLNode *rear) {
	PtrToLNode temp;
	temp = (LNode*)malloc(sizeof(LNode));
	temp->coef = coef;
	temp->expon = expon;
	temp->next = NULL;
	(*rear)->next = temp;
	*rear = temp;
}
PtrToLNode ReadPoly() {
	PtrToLNode p, rear, temp;
	int n, c, e;
	p = (LNode *)malloc(sizeof(LNode));
	p->next = NULL;
	rear = p;
	scanf("%d", &n);
	while (n--) {
		scanf("%d%d", &c, &e);
		attach(c, e, &rear);
	}
	temp = p;
	p = p->next;
	free(temp);
	return p;
}
void PrintPoly(PtrToLNode p) {
	if (!p) {
		printf("0 0\n");
		return;
	}
	printf("%d %d", p->coef, p->expon);
	p = p->next;
	while (p) {
		printf(" %d %d", p->coef, p->expon);
		p = p->next;
	}
	printf("\n");
}
int main()
{
	PtrToLNode p1;
	p1 = ReadPoly();
	PrintPoly(p1);
    return 0;
}

