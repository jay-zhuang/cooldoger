#include <stdio.h>
#include <unistd.h>
int main()
{
	int pid, status;

	if(fork())
	{
		printf("father\n");
		pid = wait(&status);
		printf("pid1: %d, status: %d\n", pid, status);
		pid = wait(&status);
		printf("pid2: %d, status: %d\n", pid, status);
		sleep(2);
		printf("fathter2\n");
	}
	else{
		printf("son: go to sleep\n");
		sleep(1);
		printf("son: exit\n");
		exit(0);
	}
	printf("bye\n");
}
