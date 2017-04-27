#include <stdio.h>

main(){
	int row , column; 
	printf("请输入行：");
	scanf("%d" , &row );
	printf("请输入列：");
	scanf("%d" , &column );
	int array[row][column];
	
	for( int i = 0; i < row; i++ )
		for( int c = 0; c < column; c++ )
			scanf("%d" , &array[i][c] );
	
	int min;
	int j;
	int flag = 1;
	printf("Saddle points as follow:\n");
	for( int i = 0; i < row; i++ ){
		min = 0;
		flag = 1;
		for( j = 0; j < column; j++ ){
			if( array[i][j] < array[i][min] ) min = j;  
		}
		for( int r = 0; r < row; r++ ){
			if( i != r )
				if( array[r][min] >= array[i][min] ){
					flag = 0;
					break;
				}
		}
		if( flag ) printf("(%d,%d)\n" , i , min );
	}		
}
