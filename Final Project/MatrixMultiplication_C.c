#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <time.h>
#include <sys/time.h>
#ifndef SIZE
#define SIZE 400
#endif

int main(){

int size = SIZE;
int mat1[SIZE][SIZE];
int mat2[SIZE][SIZE];
int result [SIZE][SIZE];

srand ( time(NULL) );

	for(int i = 0; i < size; ++i)
		{
			for(int j = 0; j < size ; ++j)
				{
   					mat1[i][j] = rand() % 1000 +1;
   					mat2[i][j] = rand() % 1000 +1;
   				}
   		}


	//Doing the Multipication
	int sum = 0;
	clock_t startTime = clock();
	
	for (int row = 0 ; row < size;  row++){
		for (int col = 0 ; col < size ; col++){
			
			for (int k = 0 ; k < size ; k++){
				
                sum = sum + mat1[row][k] * mat2[k][col];
			}
			result[row][col] = sum;
			sum = 0;
		}
	}
	clock_t runtime = clock() - startTime;
	int miliSeconds = runtime * 1000 / CLOCKS_PER_SEC;

    printf("runtime : \n");
    printf("%6.5f", (double)(runtime));
    printf("\n");
    printf("%d", miliSeconds);
    printf("\n");

}

