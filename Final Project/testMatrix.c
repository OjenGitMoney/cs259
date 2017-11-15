#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main(){
int size = 5;
int mat1 [size][size];
int mat2 [size][size];

	for(int i = 0; i < size; ++i)
	{
   		for(int j = 0; j < size ; ++j) 
   		{
   			mat1[i][j] = rand();
   			mat2[i][j] = rand();
  		}
	}

	for(int i = 0; i < size; ++i)
	{
  		for(int j = 0; j < size ; ++j) 
   		{
      	printf("%d\t",mat1[i][j]);
   		}
		printf("\n");
	}

	printf("\n\n");

	for(int i = 0; i < size; ++i)
	{
   		for(int j = 0; j < size ; ++j) 
   		{
      		printf("%d\t",mat2[i][j]);
   		}
		printf("\n");
	}

}

// void multiplier(int[][] matrix){
	
// }