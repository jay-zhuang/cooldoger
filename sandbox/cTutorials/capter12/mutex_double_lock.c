#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_mutex_t a_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t rec_mutex = PTHREAD_RECURSIVE_MUTEX_INITIALIZER_NP;
pthread_cond_t got_request = PTHREAD_COND_INITIALIZER;

void thr1_fun(void){
	int rc;
	rc = pthread_mutex_lock(&rec_mutex);
	printf("[mutex] thr1 lock rec_mutex, rc = '%d' \n", rc);

	printf("thr1 in processing...\n");
	sleep(1);
	printf("thr1 processed\n");

//	rc = pthread_mutex_lock(&rec_mutex);
	printf("[mutex] thr1 double lock rec_mutex, rc = '%d' \n", rc);
	
	printf("Wait the signal\n");
	rc = pthread_cond_wait(&got_request, &rec_mutex);
	printf("	double lock free\n");
	rc = pthread_mutex_unlock(&rec_mutex);
	printf("[mutex] thr1 release rec_mutex, rc = '%d' \n", rc);
}

void thr2_fun(void){
	int rc;
	sleep(1);
	rc = pthread_mutex_unlock(&rec_mutex);
	printf("[mutex] thr2 release rec_mutex, rc = '%d' \n", rc);

	rc = pthread_mutex_lock(&rec_mutex);
	printf("[mutex] thr2 lock rec_mutex, rc = '%d' \n", rc);

	printf("thr2 in processing...\n");
	sleep(3);
	printf("thr2 processed\n");

	rc = pthread_mutex_unlock(&rec_mutex);
	printf("[mutex] thr2 release rec_mutex, rc = '%d' \n", rc);
}

int main(int argc, char* argv[])
{
	int thr_id1, thr_id2, rc;
	pthread_t p_thread1;
	pthread_t p_thread2;

	thr_id1 = pthread_create(&p_thread1, NULL, thr1_fun, NULL);
	thr_id2 = pthread_create(&p_thread2, NULL, thr2_fun, NULL);
	
	sleep(6);
	printf("main thread send a signal\n");
	rc = pthread_cond_signal(&got_request);
	sleep(5);
	printf("main is exit\n");

}
