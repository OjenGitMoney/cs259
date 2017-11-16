#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#ifndef SIZE
#define SIZE 3
#endif



int main(){
int size = SIZE;

int mat1[SIZE][SIZE] = { {4,3,1},{3,7,2},{4,9,1} };
int mat2[SIZE][SIZE] = { {4,10,9},{7,10,2},{6,4,7} };

int result [SIZE][SIZE];

	for(int i = 0; i < size; ++i)
	{for(int j = 0; j < size ; ++j){
   			mat1[i][j] = rand() % 10 +1;
   			mat2[i][j] = rand() % 10 +1;}}

	 for(int i = 0; i < size; ++i)
	 {for(int j = 0; j < size ; ++j){printf("%d\t",mat1[i][j]);}
	 	printf("\n");}
	 printf("\n\n");
	 for(int i = 0; i < size; ++i)
	 {for(int j = 0; j < size ; ++j){printf("%d\t", mat2[i][j]);}
	 	printf("\n");}

	//Doing the Multipication

		for (int row=1; row<= size;  ++row){
			for (int col=1; col<= size; ++col){
			int sum = 0;
                for (int k=1; k<=size; ++k){
                    //printf(sum);
                    sum = sum + mat1[row][k] * mat2[k][col];
			    }
                result[row][col] = sum;

		}
	}
	printf("\n\n--------\n\n");
    for(int i = 0; i < size; ++i)
    {for(int j = 0; j < size ; ++j){printf("%d\t", result[i][j]);}
        printf("\n");}

}

