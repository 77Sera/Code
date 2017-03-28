/* 2017/3/28
 * 栈 链表实现 Stack in list; 单向，有表头
 * aim: exercise; 
 */
 
#include <stdio.h>
#include <stdlib.h>
#define LEN sizeof(struct Node)
#define Null -1

struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode Stack;

struct Node{
	int data;
	PtrToNode next;
}; 

Stack CreateStack(){
 	Stack S = ( Stack )malloc( LEN );
 	S->next = NULL;
 	S->data = Null;
 	return S;
}

int IsEmpty( Stack S ){
	return S->next == NULL;
}

void Push( int x , Stack S ){
	PtrToNode p;
	p = ( Stack )malloc( LEN );
	p->data = x;
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
		printf("empty stack\n");
	}
}

int Top( Stack S ){
	if( !IsEmpty( S ) ){
		return S->next->data;
	}
	else{
		printf("empty stack\n");
		return 0;
	}
}

void PrintStack( Stack S ){
	PtrToNode p = S->next;
	int i = 0;
	while( p ){
		printf("第%d个节点的值为%d\n", i++ , p->data);
		p = p->next;
	}
}

main(){
	//主函数为测试； 
	Stack S = CreateStack();
	Push( 1 , S );
	Push( 0 , S );
	Pop( S );
	PrintStack( S );
	printf("%d\n", Top( S ) );
}
