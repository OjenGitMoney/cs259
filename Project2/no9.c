#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

void myAlarmHandler(int signal){
	printf("Timed out!.\n");
	exit(0);
}

int main(void)
{
	char string[256];
	signal(SIGALRM, myAlarmHandler);
	printf("Enter something: \n");
	alarm(10);
	scanf("%s", string);
	alarm(0);
	return 0;
}