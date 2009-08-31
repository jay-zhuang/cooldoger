#include <stdio.h>
#include <pthread.h>

pthread_mutex_t a_mutex = PTHREAD_MUTEX_INITIALIZER;
int a = 9;
int b = 9;

void thr1_fun(void){
	int rc;
	printf("thr1\n");
	rc = pthread_mutex_lock(&a_mutex);
	a = 1;
	printf("thr1 set a finish!\n");
//	rc = pthread_mutex_lock(&a_mutex);
	sleep(1);
	b = 1;
	printf("thr1 set b finish!\n");
//	rc = pthread_mutex_unlock(&a_mutex);
}

void thr2_fun(void){
	int rc;
	printf("thr2\n");
	rc = pthread_mutex_lock(&a_mutex);
	a = 2;
	printf("thr2 set a finish!\n");
	sleep(2);
	b = 2;
	printf("thr2 set b finish!\n");
	rc = pthread_mutex_unlock(&a_mutex);
}

int main(int argc, char* argv[])
{
	int thr_id1, thr_id2;
	pthread_t p_thread1;
	pthread_t p_thread2;

	thr_id1 = pthread_create(&p_thread1, NULL, thr1_fun, NULL);
	thr_id2 = pthread_create(&p_thread2, NULL, thr2_fun, NULL);

	printf("a = %d\nb = %d\n", a, b);
	printf("main is over!\n");
	sleep(14);
}
