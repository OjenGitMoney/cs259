#include <stdio.h>

int main(void)
{

int childPid;

childPid=fork(); 
	if (childPid != 0){
		printf("Parent starting wait.\n");
		
	}
	else if (childPid == 0){
		printf("Child is going to sleep.\n");
		sleep(5);
		printf("Child finished sleeping.\n");
	}

	wait();
	printf("Parent finished wait.\n");

}
