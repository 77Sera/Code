/* 2017.5.19
 * 利用堆栈实现单链表的就地逆置 
 * 设计下列函数：建立任意个结点的单链表、输出单链表、逆置单链表、主函数。
 * 利用堆栈的入栈、出栈等函数（顺序栈，链栈皆可） 
 */

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct list *List;
typedef struct stack *Stack;

struct list{
	int data;
	List next;
};

struct stack{
	List data;
	Stack next;
};

//判栈空 

int IsEmpty( Stack S ){
	return S->next == NULL; 
}

//创建一个有header的栈 

Stack CreateStack(){
	Stack S = (Stack)malloc( sizeof(struct stack) );
	S->next = NULL;
	S->data = NULL;
	return S;
}

//入栈 

void Push( Stack S , List P ){
	Stack newNode = (Stack)malloc( sizeof(struct stack) );
	newNode->data = P;
	newNode->next = S->next;
	S->next = newNode;
}

//使栈顶元素（如果有）出栈 

void Pop( Stack S ){
	if( !IsEmpty( S ) ){
		Stack delNode = S->next;
		S->next = delNode->next;
		free( delNode );
	}
}

//如果栈顶有元素，就把它的值返回 

List Top( Stack S ){
	if( !IsEmpty( S ) ) return S->next->data;
}

//创建一个有header的表； 

List CreateList(){
	List L = (List)malloc( sizeof(struct list) );
	L->next = NULL;
	L->data = -1;
	return L;
}

//插入结点

void InsertList( List L , int x ){
	List newNode = (List)malloc( sizeof(struct list) );
	newNode->data = x;
	List p = L;
	while( p->next ) p = p->next;
	newNode->next = p->next;
	p->next = newNode;
} 

//打印链表 

void PrintList( List L ){
	List p = L->next;
	int i = 1;
	while( p ){
		printf("第%d个结点的值为：%d\n" , i++ , p->data );
		p = p->next;
	}
} 

//逆置链表

List InvertList( Stack S , List L ){
	List delNode , newNode; 
	while( L->next ){
		Push( S , L->next );
		delNode = L->next;
		L->next = delNode->next;
	}
	while( !IsEmpty( S ) ){
		newNode = Top( S );
		Pop( S );
		List p = L;
		while( p->next ) p = p->next;
		newNode->next = p->next;
		p->next = newNode;
	}
	return L;
}

void backUp(){
	char ch;
	printf("输入b返回:"); 
	ch = getchar();
	while( ch != 'b' ){
		ch = getchar();
	}
}

main(){
	List L = CreateList();
	Stack S = CreateStack();
	
	int instruction =  -1;

	
	while( instruction != 4 ){
		printf("1.插入结点\n2.打印链表\n3.逆置链表\n4.退出操作\n");
		printf("输入命令(1-4)：");
		scanf("%d" , &instruction );
		switch( instruction ){
			case 1: {
				int data;
				printf("输入要插入的值:");
				scanf("%d" , &data );
				InsertList( L , data );
				backUp();
				system("cls");
				break;
			}
			case 2: {
				PrintList( L );
				backUp();
				system("cls");
				break;
			}
			case 3: {
				L = InvertList( S , L );
				backUp();
				system("cls");
				break;
			}
			default: break;
		}
	}
}
