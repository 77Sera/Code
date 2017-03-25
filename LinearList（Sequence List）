/* 2017.3.25
 * 线性表 顺序表实现 LinearList in Sequence List 
 * aim:exercise
 */
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h> 
#define LEN sizeof(struct SeqList)
#define MAXSIZE 100
#define Null -1

struct SeqList;
typedef struct SeqList* PtrToList;
typedef PtrToList Position;
typedef PtrToList List;

struct SeqList{
	int elem[MAXSIZE];
	int last;
};

List InitList(){
	List L;
	L = ( List ) malloc ( LEN );
	for( int i = 0; i < MAXSIZE; i++ ){
		L->elem[i] = Null;
	}
	L->last = 0;
}

void InsList( List L , int i , int e ){
	if( L->last < MAXSIZE){
		if( i > 0 && i < ( L->last + 1 ) ){
			for( int j = L->last; j >= i ; j-- ){
				L->elem[j] = L->elem[j-1];
			}
			L->elem[--i] = e;
			L->last++;
		}
		else if( i == ( L->last + 1 ) ){
			L->elem[--i] = e;
			L->last++;
		}
		else{
			printf("wrong i.\n");
		}
	}
	else{
		printf("theres no space.\n");
	}
}

int ListLength( List L ){
	return L->last;
}

int GetData( List L , int i ){
	if( i > 0 && i <= L->last ){
		return L->elem[--i];
	}
	else{
		printf("wrong i.\n");
		return Null;
	}
}

void DelList( List L , int i ){
	if( i > 0 && i <= L->last ){
		for( int j = --i; i < L->last; i++ ){
			L->elem[j] = L->elem[j+1];
		}
		L->elem[L->last-1] = Null;
		L->last--;
	}
	else{
		printf("wrong i.\n");
	}
}

void PrintList( List L ){
	printf("The List is as follow:\n\n");
	for( int i = 0; i < L->last; i++ ){
		printf("第%d个节点的值为%d\n" , i+1 , L->elem[i] );
	}
}

main(){
	List L = InitList();
	int instruction = 0;
	printf("1.查看节点\n2.插入节点\n3.删除节点\n4.查看全部\n5.退出\n")； 
	while( instruction !=  ){
		
	}
}
