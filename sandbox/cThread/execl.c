#include <stdio.h>
#include <unistd.h>

int main()
{
	printf("calling execl... \n\n");
	execl("/bin/cat", "cat", "./execl.c", NULL);
	printf("Useless call to printf");
}

