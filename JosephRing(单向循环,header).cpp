/*
 * 2017.3.15 22：02； 约瑟夫环
 * explain:链表实现；单向循环链表；有header 
 */


#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>
#define LEN sizeof(struct Node)
#define Null -1

struct Node;
typedef struct Node* PtrToList;
typedef PtrToList List;
typedef PtrToList Position;
static int JosephOrder = 1;

struct Node{
	int password;
	int order;
	PtrToList next;
};

/*
 * 创建一个节点，这是表头，password值为Null（即-1） 指针指向自己； 
 */ 

List CreateList(){
	PtrToList firstNode = ( List )malloc( LEN );
	firstNode->password = Null;
	firstNode->order = Null;
	firstNode->next = firstNode;
	return firstNode;
}

/* 
  int ListLength( List firstNode ){
	Position p = firstNode;
	int i = 0;
	while( p->next != NULL ){
		i++;
		p = p->next;
	}
	return i;
}
*/ 

/*
 * 此函数操作为 在链表结尾插入一个新节点 并将该节点的password值赋一个随机值； 
 */

void InsList( List firstNode ){
	Position p = firstNode;
	Position newNode = ( List )malloc( LEN );
	while( p->next != firstNode ){
		p = p->next;
	}
	p->next = newNode;
	newNode->next = firstNode;
	//srand( time( NULL ) );
	//newNode->password = rand() % 10 + 1;
	newNode->order = JosephOrder++;
}

/*
 *此函数操作为 删除当前节点并释放； 
 */ 

void DelList( List currentP ){
	Position p = currentP;
	while( p->next != currentP ){
		p = p->next;
	}
	p->next = currentP->next;
	free( currentP );
}

void PrintList( List firstNode ){
	Position p = firstNode->next;
	printf("密码依次是：");
	while( p->next != firstNode ){
		printf("%d ", p->password );
		p = p->next;
	}
	printf("%d", p->password );
	printf("\n"); 
}

/*
 * 此函数解决约瑟夫问题，firstNode是表头指针，m是循环次数的初值，n是人数； 
 * 因为不知道要按模板来写，所以一开始写的各个函数只能在这一个函数里面一起实现了； 
 */

void JosephRing( List firstNode , int m , int n ){
	int number = n; //人数 
	int upperLimit; //每次循环的上限； 
	Position delNode; //此变量用作指向被删除的节点 
		
	while( number-- ){
		InsList( firstNode );    //插入一个新元素；password未赋值； 
	}
	
	Position p = firstNode->next;
	
	printf("请输入每个人的密码(以空格隔开):"); 
	
	while( p->next != firstNode ){   
		scanf("%d", &p->password );     //为链表中的每个元素赋密码值； 
		p = p->next;
	}
	scanf("%d", &p->password );
	
	p = firstNode->next; 	//重新指向第一个人； 
	
	number = n;

	PrintList(firstNode);	//打印密码； 

	printf("出序顺序依次为:");  

	while( number ){
		if( number == n ){		//第一次循环执行m次； 
			upperLimit = m - 1;
		}
		while( upperLimit-- ){
			p = p->next;
			if( p->password == Null ) p = p->next;
		}
		delNode = p;	//delNode保存这个准备出列的人 
		printf("%d ",p->order); 	//把出列的人的序号爆出来 
		upperLimit = p->password - 1; //把出列的人密码作为下次循环的upperLimit; 
		p = p->next;	//指向出列的人的下一个人； 
		if( p->password == Null ) p = p->next;	//跳过header； 
		DelList( delNode );		//把出列的人删除； 
		number--;	//玩家-1； 
	} 
	printf("\n",m);
}

main(){
	List p = CreateList();
	int m , n;
/*
 *  srand( time( NULL ) );
 *  m = rand() % 20 + 1;
 */
 	printf("请输入初始上限:");
 	scanf("%d", &m );
	printf("请输入游戏人数:");
	scanf("%d", &n );
	JosephRing( p , m , n );
}
