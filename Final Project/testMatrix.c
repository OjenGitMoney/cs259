#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#ifndef SIZE
#define SIZE 3
#endif



int main(){
int size = SIZE;
int mat1 [size][size];
int mat2 [size][size];
int result [size][size];

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

    for(int i = 0; i < size; ++i)
    {for(int j = 0; j < size ; ++j){printf("\n%d\t", result[i][j]);}
        printf("\n");}

}

