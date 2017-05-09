/* 2017.5.4
 * BinaryTree 递归实现 
 * function: preOrder InOrder PostOrder; 
 */

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#define LEN sizeof(struct Node)

struct Node;
typedef struct Node *PtrToTree;
typedef PtrToTree BiTree;

struct Node{
	char data;
	BiTree LChild;
	BiTree RChild;
};

void CreateBiTree( BiTree *bt ){
	char ch;
	ch = getchar();
	if( ch == '.' ) *bt = NULL;
	else{
		*bt = (BiTree)malloc(LEN);
		(*bt)->data = ch;
		CreateBiTree( &((*bt)->LChild) );
		CreateBiTree( &((*bt)->RChild) );
	}
}

void PreOrder( BiTree root ){
	if( root ){
		printf("%c" , root->data );
		PreOrder( root->LChild );
		PreOrder( root->RChild );
	}
}

void InOrder( BiTree root ){
	if( root ){
		InOrder( root->LChild );
		printf("%c" , root->data );
		InOrder( root->RChild );
	}
} 

void PostOrder( BiTree root ){
	if( root ){
		PostOrder( root->LChild );
		PostOrder( root->RChild );
		printf("%c" , root->data );
	}
}

main(){
	BiTree bt;
	printf("输入二叉树（先序,空结点以.表示 ）：");
	CreateBiTree( &bt );
	printf("\n先序输出为：");
	PreOrder( bt );
	printf("\n中序输出为：");
	InOrder( bt );
	printf("\n后序输出为：");
	PostOrder( bt ); 
}
