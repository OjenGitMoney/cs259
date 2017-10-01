#include <stdio.h>

int main(void)
{
int _a;
int	_b; 
int	_c;
int	_d;
int	_e;
int	_f;
int childPid;
int childPid2;

	printf("\n\nBefore the fork. Process A has id : 	%d \n", getpid());
	
	childPid=fork();
	if (childPid != 0){
		printf("I\'m A. My pid is:	 %d \n", getpid());
		printf("B is child. B\'s pid is:	 %d \n", childPid);
		
	}
	else if (childPid == 0){
		printf("I am B \(child\), my id is : 	%d \n", childPid);
		printf("I am B, my parent\'s PID : 	%d \n", getppid());
		childPid2=fork();
		if (childPid2 != 0){
			printf("B becoming a parent, now my PID:	 %d \n", getpid());
			printf("B\'s child PID:	 %d \n", childPid2);
		}
		else if (childPid2 == 0){
		printf("I am D \(child\), my id is : 	%d \n", childPid2);
		printf("I am D, my parent (B) PID : 	%d \n", getppid());
		}
	}
	 
}