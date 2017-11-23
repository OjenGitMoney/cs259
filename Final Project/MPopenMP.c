#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <time.h>
#ifndef SIZE
#define SIZE 1000
#endif



int main(){
int size = SIZE;

int mat1[SIZE][SIZE];
int mat2[SIZE][SIZE];
int result [SIZE][SIZE];

	for(int i = 0; i < size; ++i)
	{for(int j = 0; j < size ; ++j){
   			mat1[i][j] = rand() % 1000 +1;
   			mat2[i][j] = rand() % 1000 +1;}}

	 // for(int i = 0; i < size; ++i)
	 // {for(int j = 0; j < size ; ++j){printf("%d\t",mat1[i][j]);}
	 // 	printf("\n");}
	 // printf("\n\n");
	 // for(int i = 0; i < size; ++i)
	 // {for(int j = 0; j < size ; ++j){printf("%d\t", mat2[i][j]);}
	 // 	printf("\n");}

	//Doing the Multipication
	int sum = 0;
	int row, col, k;

	double startTime = omp_get_wtime();
	#pragma omp parallel shared(mat1, mat2, result) private(row, col, k)
	{
		#pragma OMP FOR SCHEDULE(STATIC)
		for (int row = 0 ; row < size;  row++){
			for (int col = 0 ; col < size ; col++){
				
				for (int k = 0 ; k < size ; k++){
	                sum = sum + mat1[row][k] * mat2[k][col];
				}
				result[row][col] = sum;
				sum = 0;
			}
		}
	}
	double endTime = omp_get_wtime();

	// printf("\n\n--------\n\n");
 //    for(int i = 0; i < size; ++i)
 //    {for(int j = 0; j < size ; ++j){printf("%d\t", result[i][j]);}
 //        printf("\n");}

    printf("runtime : \n");
    printf("%6.5f", (double)(endTime - startTime));
    printf("\ntest");
    printf("\n");

}

