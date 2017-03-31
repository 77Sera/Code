/*	2017/3/30
 *	十进制转R进制  in Stack； 
 *	aim： exercise 
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

//创建一个栈，指向NULL 

Stack CreateStack(){
	Stack S = ( Stack )malloc( LEN );
	S->next = NULL;
	S->data = Null;
	return S;
} 

//让x进栈 

void Push( int x , Stack S ){
	PtrToNode p;
	p = ( Stack )malloc( LEN );
	p->data = x;
	p->next = S->next;
	S->next = p;
}

//让栈顶出栈 

void Pop( Stack S ){
	if( S->next == NULL ){
		printf("empty stack\n");
	}
	else{
		PtrToNode delNode = S->next;
		S->next = delNode->next;
		free( delNode );
	}
}

int Top( Stack S ){
	if( S->next == NULL ){
		printf("empty stack\n");
	}
	else{
		return S->next->data;
	}
}

//number是个十进制数；R是要转换的进制，转换后的数进栈； 

void transform( Stack S , int number , int R ){
	while( number ){
		Push( number % R , S );
		number /= R;
	}
}

main(){
	Stack S = CreateStack();
	int number , R;
	printf("请输入要转换的十进制数：");
	scanf("%d", &number );
	printf("请输入要转换到的进制R：");
	scanf("%d", &R );
	transform( S , number , R );
	//打印转换后的数
	printf("转换后的数为：");
	while( S->next != NULL ){
		if( R == 16 ){
			char word = '0';
			switch( Top ( S ) ){
				case 10: word = 'A'; break;
				case 11: word = 'B'; break;
				case 12: word = 'C'; break;
				case 13: word = 'D'; break;
				case 14: word = 'E'; break;
				case 15: word = 'F'; break;
				default: break;
			}
			if( word != '0' ){
				printf("%c ", word );
			}	
			else{
				printf("%d ", Top( S ) );
			}
		}
		else{
			printf("%d ", Top( S ) );
		}
		Pop( S );
	} 
}
