#include <stdio.h>
#include <pthread.h>

void* do_loop(void* data)
{
	int i;
	int j;
	int me = *((int*)data);

	for (i=0; i<10; i++) {
		for (j=0; j<50000000; j++)
			;
		printf("'%d' - Got '%d'\n", me, i);
	}
//	pthread_exit(NULL);
}

int main(int argc, char* argv[])
{
	int	thr_id;
	pthread_t p_thread;
	pthread_t p_thread2;
	int	a = 1;
	int 	b = 2;
	int 	c = 3;

//	pthread_exit(NULL);
	thr_id = pthread_create(&p_thread, NULL, do_loop, (void*)&a);
	thr_id = pthread_create(&p_thread2, NULL, do_loop, (void*)&b);
//	do_loop((void*)&a);
//	do_loop((void*)&b);
	do_loop((void*)&c);

	return 0;
}
