#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_mutex_t rec_mutex = PTHREAD_RECURSIVE_MUTEX_INITIALIZER_NP;

void thr1_fun(void) {
	int rc;
	printf("start thr1_fun\n");
	rc = pthread_mutex_lock(&rec_mutex);
	if(rc) {
		perror("thr1_fun, pthread_mutex_lock");
		pthread_exit(NULL);
	} 
	printf("thr1_fun executing\n");
	rc = pthread_mutex_lock(&rec_mutex);
	if(rc) {
		perror("thr1_fun, pthread_mutex_lock 2");
		pthread_exit(NULL);
	}
	printf("thr1_fun double lock and executing\n");
	pthread_mutex_unlock(&rec_mutex);
	sleep(1);
	printf("thr1_fun finished\n");
	pthread_mutex_unlock(&rec_mutex);
}

void thr2_fun(void) {
	int rc;
	printf("start thr2_fun\n");
	rc = pthread_mutex_lock(&rec_mutex);
	if(rc) {
		perror("thr1_fun, pthread_mutex_lock");
		pthread_exit(NULL);
	}
	printf("thr2_fun executing\n");
	sleep(1);
	printf("thr2_fun finished\n");
	pthread_mutex_unlock(&rec_mutex);
}

int main(int argc, char* argv[])
{
	int thr_id1, thr_id2, rc;
	pthread_t p_thread1, p_thread2;
	thr_id1 = pthread_create(&p_thread1, NULL, thr1_fun, NULL);
	thr_id2 = pthread_create(&p_thread2, NULL, thr2_fun, NULL);
	sleep(4);
	printf("main end. \n");
}
