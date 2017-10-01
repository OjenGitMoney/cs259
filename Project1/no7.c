#include <stdio.h>

int main(void)
{
int childPidB;
int childPidD;
int childPidC;
int childPidE;
int childPidF;

	printf("\n\nBefore the fork. Process A has id : 	%d \n", getpid());
	
	childPidB=fork(); 
	if (childPidB != 0){
		printf("I\'m A. My pid is:	 %d \n", getpid());
		printf("A says: B is my child. B\'s pid is:	 %d \n", childPidB);
		
		childPidC=fork();
		if (childPidC != 0){
			printf("I\'m A. My pid is:	 %d \n", getpid());
			printf("A says: C is my child. C\'s pid is:	 %d \n", childPidC);
		}
		else if (childPidC == 0){
			printf("I am C, Child of A, my id is : 	%d \n", childPidC);
			printf("I am C, my parent\'s PID (A) : 	%d \n", getppid());
		
			childPidE=fork();
			if (childPidE != 0){
				printf("I\'m C. My pid is:	 %d \n", getpid());
				printf("C says: E is my child. E\'s pid is:	 %d \n", childPidE);
				
				childPidF=fork();
				if (childPidF != 0){
					printf("I\'m C. My pid is:	 %d \n", getpid());
					printf("C says: F is my child. F\'s pid is:	 %d \n", childPidF);
				}
				else if (childPidF == 0){
					printf("I am F \(child\), my id is : 	%d \n", childPidF);
					printf("I am F, my parent\'s PID (C): 	%d \n", getppid());
				}
					
			}
			else if (childPidE == 0){
				printf("I am E \(child\), my id is : 	%d \n", childPidE);
				printf("I am E, my parent\'s PID (C) : 	%d \n", getppid());
			}
		}
				
	}
	else if (childPidB == 0){
		printf("I am B \(child\), my id is : 	%d \n", childPidB);
		printf("I am B, my parent\'s PID (A): 	%d \n", getppid());
		childPidD=fork();
		if (childPidD != 0){
			printf("B becoming a parent, now my PID:	 %d \n", getpid());
			printf("B says: D is my child. D\'s :	 %d \n", childPidD);
		}
		else if (childPidD == 0){
		printf("I am D \(child\), my id is : 	%d \n", childPidD);
		printf("I am D, my parent\'s PID (B): 	%d \n", getppid());
		}
	}
	 
}