#include <stdio.h>

int main()
{
	int pid;
	printf("Hi Jay!\n");
	
	pid = fork();
	if(pid != 0)
		printf("father, son pid: %d\n", pid);
	else
		printf("son\n");
	printf("Bye Jay!\n");
}
