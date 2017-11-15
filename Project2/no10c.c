#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#ifndef MSGSIZE
#define MSGSIZE 1
#endif

int pfd[2], retVal, count=0;

void alarmHandler(int signal){
	printf("Write blocked after %d characters\n", count);
	char buffer[MSGSIZE];
	while(count){
		read (pfd[0], buffer, MSGSIZE);
		count--;
	}
	exit(0);
}

int main(void)
{
	
	retVal = pipe(pfd);
	signal(SIGALRM, alarmHandler);
	while(1){
		alarm(2);
		write (pfd[1], "a", MSGSIZE);
		count++;
		alarm(0);
		if(count % 1024 == 0){
			printf("There are %d characters in pipe\n", count);
		}
	}
	
	return 0;
}