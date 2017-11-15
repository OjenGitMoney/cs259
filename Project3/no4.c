#include <stdio.h>
#include <omp.h>

int main(){
	
	omp_set_num_threads(6);
	//#pragma omp parallel
	int i;
	#pragma omp parallel 
	for (int i = 0; i < 5; ++i)
	{
		
		printf("\n Hello from thread = %d", omp_get_thread_num() );
		printf("\n ba ham\n");
	}
	printf("\n\n GoodBye – Team Destroyed – Exiting Program \n\n");
}