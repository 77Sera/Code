/* 2017.4.13
 * Hanoi Tower in Stack
 * aim: exercise
 */

#include <stdio.h>
#include <stdlib.h>
#define LEN sizeof(struct Node)
#define Null -1

struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode Stack;

struct Node{
	int n;
	char a;
	char b;
	char c;
	PtrToNode next;
};

Stack CreateStack(){
	Stack S = ( Stack )malloc( LEN );
	S->a = S->b = S->c = '0';
	S->n = Null;
	S->next = NULL;
	return S;
}

int IsEmpty( Stack S ){
	return S->next == NULL;
}

void Push( Stack S , int n , char a ,char b , char c ){
	PtrToNode p = ( Stack )malloc( LEN );
	p->n = n;
	p->a = a;
	p->b = b;
	p->c = c;
	p->next = S->next;
	S->next = p; 
}

void Pop( Stack S ){
	if( !IsEmpty( S ) ){
		PtrToNode delNode = S->next;
		S->next = delNode->next;
		free( delNode );
	}
	else{
		printf("empty Stack\n");
	}
}

void Hanoi( Stack S , int n ){
	Push( S , n , 'a' , 'b' , 'c' );
	
	while( !IsEmpty( S ) ){
		
		char a = S->next->a;
		char b = S->next->b;
		char c = S->next->c;
		n = S->next->n;
		
		Pop( S );
		
		if( n == 1 ) printf("%c -> %c\n" , a , c );
		else{
			Push( S , n-1 , b , a , c );
			Push( S , 1 , a , b , c );
			Push( S , n-1 , a , c , b );
		}
		
	}
}

main(){
	Stack S = CreateStack();
	printf("Hanoi Tower\n\n");
	printf("请输入n:");
	int n;
	scanf("%d" , &n );
	printf("\n结果为：\n");
	Hanoi( S , n );
}
