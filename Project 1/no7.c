#include <stdio.h>

int main(void)
{
int _a;
int	_b; 
int	_c;
int	_d;
int	_e;
int	_f;
int childPidB;
int childPidD;
int childPidC;

	printf("\n\nBefore the fork. Process A has id : 	%d \n", getpid());
	
	childPidB=fork(); 
	if (childPidB != 0){
		printf("I\'m A. My pid is:	 %d \n", getpid());
		printf("B is child. B\'s pid is:	 %d \n", childPidB);
		
		childPidC=fork();
		if (childPidC != 0){
			printf("I\'m A. My pid is:	 %d \n", getpid());
			printf("C is child. C\'s pid is:	 %d \n", childPidC);
		}
		else if (childPidC == 0){
			printf("I am C \(child\), my id is : 	%d \n", childPidC);
			printf("I am C, my parent\'s(A) PID : 	%d \n", getppid());
		}
		
		
	}
	else if (childPidB == 0){
		printf("I am B \(child\), my id is : 	%d \n", childPidB);
		printf("I am B, my parent\'s(A) PID : 	%d \n", getppid());
		childPidD=fork();
		if (childPidD != 0){
			printf("B becoming a parent, now my PID:	 %d \n", getpid());
			printf("B\'s child PID:	 %d \n", childPidD);
		}
		else if (childPidD == 0){
		printf("I am D \(child\), my id is : 	%d \n", childPidD);
		printf("I am D, my parent (B) PID : 	%d \n", getppid());
		}
	}
	 
}