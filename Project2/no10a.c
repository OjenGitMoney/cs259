#include <stdio.h>
#include <unistd.h>
#ifndef MSGSIZE
#define MSGSIZE 16
#endif

int main(void)
{
	int pfd[2], retVal, pid;
	char msg [MSGSIZE], buffer[MSGSIZE];

	retVal = pipe(pfd);
	pid = fork();
	if (pid == 0){
		read (pfd[0], buffer, MSGSIZE);
		printf("This is child process %d. Reading message 1 from pipe.\
			content is: %s\n", getpid(), buffer);
		read (pfd[0], buffer, MSGSIZE);
		printf("This is child process %d. Reading message 2 from pipe.\
			content is: %s\n", getpid(), buffer);
		read (pfd[0], buffer, MSGSIZE);
		printf("This is child process %d. Reading message 3 from pipe.\
			content is: %s\n", getpid(), buffer);
		read (pfd[0], buffer, MSGSIZE);
		printf("This is child process %d. Reading message 4 from pipe.\
			content is: %s\n", getpid(), buffer);
	}
	else{
		printf("This is the parent process %d. Writing message 1 into pipe.\n", getpid());
		write (pfd[1], "msg1", MSGSIZE);
		printf("This is the parent process %d. Writing message 1 into pipe.\n", getpid());
		write (pfd[1], "msg2", MSGSIZE);
		printf("This is the parent process %d. Writing message 1 into pipe.\n", getpid());
		write (pfd[1], "msg3", MSGSIZE);
		printf("This is the parent process %d. Writing message 1 into pipe.\n", getpid());
		write (pfd[1], "msg4", MSGSIZE);
	}

	return 0;
}