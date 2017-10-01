#include <stdio.h>

int main(void)
{
int childPid;

	printf("Immediately before the fork. Only one process at this point.\n");
	
	childPid=fork();
	printf("Immediately after the fork. This statement should print twice.\n");
	
	if (childPid != 0){
		printf("I\'m the parent. My pid is %d. My child\'s pid is %d.\n",getpid(), childPid);
		}
	else if (childPid == 0){
		printf("I\'m the child. My pid is %d. My parent\'s pid is %d.\n",childPid, getppid());
		}
}