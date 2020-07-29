#include <stdio.h>
#include <stdbool.h>
#define N 1000
Queue CreateQueue(int MaxSize)
{
	Queue Q = (Queue)malloc(sizeof(struct QNode));
	Q->Data = (ElementType * )malloc(Maxsize * sizeof(ElementType));
	Q->Front = Q->Rear = 0;
	Q->MaxSize = MaxSize;
	return Q;
 } 
 bool IsFull(Queue Q)
 {
 	return((Q->Rear + 1)% Q->MaxSize == Q-> Front);
 }
 
 bool AddQ(Queue Q,ElementType X)
 {
 	if(IsFull(Q)) {
	 printf("Тњ");
	return false;	
	}
	else {
		Q->Rear = (Q-> Rear+1)%Q ->MaxSize;
		Q->Data[Q->Rear] = X;
		return true;
	}
}

bool IsEmpty(Queue Q)
{
	return(Q->Front ==Q->Rear);
}

ElementType DeleteQ(Queue Q)
{
	If(IsEmpty(Q)) {
		printf("Пе");
		return ERROR;
	}
	else {
		Q->Front = (Q->Front+1) % Q->MaxSize;
		return Q->Data[Q->Front];
	}
}


int main()
{
	int i,a,b[N];
	scanf("%d", &a);
	for(i=1;i<a;i++){
		scanf("%d",b[i]);
	}
	for(i=1;i<a;i++){
		if(b[i]%2!=0){
			
		}
	}	
}










 
