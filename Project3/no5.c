#include <stdio.h>
#include <omp.h>

int main(){
	
	omp_set_num_threads(2);
	int i;
	int sum=0;

	#pragma omp parallel for
	for (int i = 0; i < 100; ++i)
	{
		sum = sum + i;
		printf("\n Thread Number:  %d Iteration: %d Local sum: %d \n", omp_get_thread_num(),i, sum );
		

		//#pragma omp distribute parallel for [clause[ [,] clause] ... ] newline
		//for-loops

	}
	printf("\n\n GoodBye – Team Destroyed – Exiting Program \n\n");
}