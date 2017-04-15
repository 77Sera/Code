/* 2017.4.14
 * Quene in list , header ;
 * aim: exercise;
 */

#include <stdio.h>
#include <stdlib.h>
#define LEN sizeof(struct Node)

struct Node;
struct PointerToQuene;
typedef struct Node *PtrToNode;
typedef struct PointerToQuene *Quene;

struct Node{
	int data;
	PtrToNode next;
};

struct PointerToQuene{
	PtrToNode front;
	PtrToNode rear;
};

Quene InitQuene(){
	Quene Q = ( Quene )malloc( sizeof( struct PointerToQuene ) );
	Q->front = Q->rear = ( PtrToNode )malloc( LEN );
	Q->front->next = NULL;
	return Q;
}

int IsEmpty( Quene Q ){
	return Q->front->next == NULL;
}

void EnterQuene( Quene Q , int x ){
	PtrToNode newNode = ( PtrToNode )malloc( LEN );
	newNode->data = x;
	Q->rear->next = newNode;
	Q->rear = newNode;
	Q->rear->next = NULL;
}

void DeleteQuene( Quene Q ){
	if( IsEmpty( Q ) ) printf("Empty quene.\n");
	else{
		PtrToNode delNode = Q->front->next;
		Q->front->next = delNode->next;
		free( delNode );
	}
}

void PrintQuene( Quene Q ){
	Quene p = Q;
	int i = 1;
	while( p->front->next ){
		p->front = p->front->next;
		printf("队列第%d个元素的值为%d\n" , i++ , p->front->data );
	}
	if( i == 1 ) printf("empty quene\n");
} 

main(){
	Quene Q = InitQuene();
	EnterQuene( Q , 1 );
	EnterQuene( Q , 2 );
	EnterQuene( Q , 3 );
	DeleteQuene( Q );
	DeleteQuene( Q );
	PrintQuene( Q );
}
