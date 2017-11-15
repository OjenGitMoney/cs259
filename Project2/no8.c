#include <stdio.h>
#include <unistd.h>

int main(void)
{
	printf("Sleep #1\n");
	sleep(1);
	printf("Sleep #2\n");
	sleep(1);
	printf("Sleep #3\n");
	sleep(1);
	printf("Sleep #4\n");
	sleep(1);
	printf("Sleep #5\n");
	sleep(1);
	printf("The Program will Exit now!\n");
	return 0;
}