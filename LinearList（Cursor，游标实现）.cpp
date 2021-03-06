/* 2017.3.25
 * 静态单链表 Cursor 游标实现
 * aim: exercise
 */ 
#include <stdio.h>
#include <stdlib.h>
#define Null -1
#define header -2
#define MAXSIZE 100

typedef int PtrToNode;
typedef PtrToNode Position;
typedef PtrToNode List;

struct Node{
	int data;
	Position next;
}CursorSpace[ MAXSIZE ];

/*
 * 将链表分为两链，一个是0开头的空闲链表，另一个是以1为header的游标链表，两个链表尾节点都指向0； 
 */

List InitList( ){
	for( int i = 2; i < MAXSIZE; i++ ){
		CursorSpace[i].next = i + 1;
	}
	CursorSpace[ MAXSIZE - 1 ].next = 0;
	CursorSpace[1].data = header;
	CursorSpace[1].next = 0;
	CursorSpace[0].data = Null;
	CursorSpace[0].next = 2; 
	return 1;
}

Position CursorAlloc(){
	Position p;
	p = CursorSpace[ 0 ].next;
	CursorSpace[ 0 ].next = CursorSpace[ p ].next;
	return p;
}

void CursorFree( Position p ){
	CursorSpace[ p ].next = CursorSpace[ 0 ].next;
	CursorSpace[ 0 ].next = p;
}

int ListLength( List L ){
	Position p = L;
	int i = 0;
	while( CursorSpace[ p ].next ){
		p = CursorSpace[ p ].next;
		i++;
	}
	return i;
}

void InsList( List L , int i , int e ){
	Position p = L;
	if( i > 0 && i <= ListLength( L ) + 1 ){	
		while( --i ){
			p = CursorSpace[p].next;
		}
		Position newNode = CursorAlloc();
		CursorSpace[ newNode ].next = CursorSpace[ p ].next;
		CursorSpace[ p ].next = newNode;
		CursorSpace[ newNode ].data = e;
	}
	else{
		printf("wrong i\n");
	}
}

void DelList( List L , int i ){
	Position p = L;
	if( i > 0 && i <= ListLength( L ) ){
		while( --i ){
			p = CursorSpace[ p ].next;
		}
		Position delNode = CursorSpace[ p ].next;
		CursorSpace[ p ].next = CursorSpace[ delNode ].next;
		CursorFree( delNode );
	}
	else{
		printf("wrong i\n");	
	}
}

int GetData( List L , int i ){
	if( i > 0 && i <= ListLength( L ) ){
		Position p = L;
		while( i-- ){
			p = CursorSpace[ p ].next;
		}
		return CursorSpace[ p ].data;
	}
	else{
		printf("wrong i\n");
		return 0;
	}
}

void PrintList( List L ){
	Position p = CursorSpace[ L ].next;
	int i = 0;
	while( p ){
		printf("第%d个节点的值为%d\n", ++i , CursorSpace[p].data );
		p = CursorSpace[ p ].next;
	}
}

main(){
	//主函数为测试； 
	List L = InitList();
	InsList( L , 1 , 1 );
	InsList( L , 1 , 0 ); 
	DelList( L , 1 );
	PrintList( L );
	printf("%d\n" , GetData( L , 1 ) ); 
}
