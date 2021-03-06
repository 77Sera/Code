/* 2017.3.8 ； About LinearList;
 * aim: exercise;
 * explain:  此链表为双向链表，有表头，无表尾； 
 */
 
 
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#define LEN sizeof(struct Node)
#define ElementType int
#define Null -1

struct Node;
typedef struct Node* PtrToList;
typedef PtrToList List;
typedef PtrToList Position;

struct Node{
	ElementType x;
	PtrToList next;
	PtrToList prev;
};

/*
 *创建一个新链表的firstNode（即表头），firstNode的x赋值为Null（即-1）；前一项和后一项皆指向NULL； ！！！这是程序执行的第一步！！！ firstNode不可销毁； 
 */ 

List CreateList(){
	PtrToList firstNode = ( List )malloc( LEN );
	firstNode->x = Null;
	firstNode->next = NULL;
	firstNode->prev = NULL;
	return firstNode;
}

/*
 *此为一个检测链表长度的函数，若为空表则返回0，否则返回表中的元素； 
 */

int ListLength( List firstNode ){
	Position p = firstNode;
	int i = 0;
	while( p->next != NULL ){
		i++;
		p = p->next;
	}
	return i;
}

/*
 * i的范围为（1~ListLength） ,返回第i个节点的值；若i错误，则报错并打印Error； 
 */

ElementType GetData( List firstNode , int i ){
	Position p=firstNode;
	if( i >= 1 && i <= ListLength( firstNode ) ){
		while( i-- ){
			p = p->next;
		}
		return p->x;
	}
	else{
		printf("\n\nWRONG i ！\n\n");
		return Null;
	}
}

/*
 *这是一个插入新元素的函数 ，i的范围为（1~ListLength+1）操作为在第i个位置之前插入新的数据元素e(也就是插入元素成为第i个节点)； 无返回值
 */
 
void InsList( List firstNode , int i , ElementType e ){
	Position p = firstNode;
	Position newNode = ( List )malloc( LEN );
	newNode->x = e;
	newNode->next = NULL;
	newNode->prev = NULL;
	if( i < 1 || i > ( ListLength( firstNode ) + 1 ) ){
		printf("\n\nWRONG i ! \n\n");
		free( newNode );
	}
	else{
		while( --i ){
			p = p->next;
		}
		if( p->next == NULL ){
			p->next = newNode;
			newNode->prev = p;
		}
		else{
			p->next->prev = newNode;
			newNode->next = p->next;
			newNode->prev = p;
			p->next = newNode;
		}
	}
}

/*
 *表L存在且非空，此函数操作为删除第i个节点（即释放空间），i的范围为（1~ListLength）,返回值为value（即第i个元素的数据元素） 
 */ 

ElementType DelList( List firstNode , int i ){
	Position p = firstNode;
	ElementType value;
	if( i < 1 || i > ListLength( firstNode ) ){
		printf("\n\nWRONG i !\n\n");
	}
	else{
		while( i-- ){
			p = p->next;
		}
		value = p->x;
		if( p->next == NULL){
			p->prev->next = NULL;
			free( p );
		}
		else{
			p->next->prev = p->prev;
			p->prev->next = p->next;
			free( p );
		}
		return value;
	}
}

/*
 *如果链表中存在e这个数据元素，那么将当前指针指向这个节点并打印true，否则打印false；返回值为当前节点指针； 
 */
 
List Locate( List firstNode , ElementType e){
	Position p = firstNode;
	while( p->next != NULL ){
		if( p->x != e ){
			p = p->next;	
		}
		else{
			return p;
		}
		//p = p->next;
	} 
	printf("element not found\n");
	return p;
}

/*
 *此函数操作为将链表摧毁； 
 */
 
void DestroyList( List firstNode ){
 	Position p = firstNode;
	while( p->next != NULL ){
 		p = p->next;
	}
	while( p->prev != NULL ){
		Position beDestroy = p;
		p = p->prev;
		free( beDestroy );
	}
}

/*
 *此函数操作为将列表中所有节点的元素都变为Null（即-1）； 
 */

void ClearList( List firstNode ){
	Position p = firstNode;
	while( p->next != NULL ){
		p->x = Null;
		p = p->next;
	}
} 

/*
 *此函数操作为判断链表是否为空表 
 */

void EmptyList( List firstNode ){
	Position p = firstNode; 
	if( p->next == NULL ){
		printf("TRUE\n");
	}
	else{
		printf("FALSE\n");
	}
}

/*
 *此函数操作为 打印链表； 
 */ 
 
int PrintList( List firstNode ){
	Position p = firstNode;
	int i=0;
	if( p->next == NULL ){
		printf("The List is Empty!\n");
		return 0;
	}
	else{
		p = p->next;
	}
	printf("\n\n");
	while( p->next != NULL ){
		i++;
		printf("第%d个节点的元素值为%d\n", i , p->x );
		p = p->next;
	}
	i++;
	printf("第%d个节点的元素值为%d\n", i , p->x );
	return 0;
}

void backUp()
{
	char back;
	printf("\n\n\n返回请按b\n\n");
	while( ( back = getchar( ) ) != 'b' )
	{
		continue;
	}
	system("cls");
}

main(){
	List p = CreateList( );
	int instruction = 0;
	int location;
	while( instruction != 9 ){
		printf("1. 链表长度\n2. 查看元素\n3. 插入元素\n4. 删除节点\n5. 跳转指针\n6. 销毁链表\n7. 清空链表\n8. 打印链表\n9. 退出操作\n");
		printf("\n请输入指令（1-9)\n"); 
		scanf("%d", &instruction );
		switch( instruction ){
			case 1: printf("The ListLength is %d.\n", ListLength( p ) );
					backUp();
					break;
			case 2: printf("\n要查看第几个元素？\n");
					scanf("%d", &location );
					printf("第%d个节点的元素值为%d.\n", location , GetData( p , location ) );
					backUp();
					break; 
			case 3: printf("请输入要插入的元素位置以及元素值\n");
					ElementType element;
					scanf("%d%d", &location , &element );
					InsList( p , location , element );
					backUp();
					break;
			case 4: printf("要删除第几个节点?\n");
					scanf("%d", &location );
					DelList( p , location );
					backUp();
					break;
			case 5: printf("要跳转到哪个元素？\n");
					scanf("%d", &element );
					p = Locate( p , element );
					backUp();
					break;
			case 6: DestroyList( p );backUp();break;
			case 7: ClearList( p );backUp();break;
			case 8: PrintList( p );backUp();break;
			case 9: backUp();break;
			default:printf("wrong instruction\n");break; 
		}
	}
}
