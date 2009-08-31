#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_mutex_t request_mutex = PTHREAD_RECURSIVE_MUTEX_INITIALIZER_NP;

pthread_cond_t  got_request   = PTHREAD_COND_INITIALIZER;

void thr1_fun(void) {
	int rc;
	printf("start thr1_fun\n");
	rc = pthread_mutex_lock(&request_mutex);
	if(rc) {
		perror("thr1_fun, pthread_mutex_lock");
		pthread_exit(NULL);
	} 
	rc = pthread_cond_wait(&got_request, &request_mutex);
	if(rc == 0){
		printf("thr1_fun got to run.\n");
	}
	pthread_mutex_unlock(&request_mutex);
}

void thr2_fun(void) {
	int rc;
	printf("start thr2_fun\n");
	rc = pthread_mutex_lock(&request_mutex);
	if(rc) {
		perror("thr1_fun, pthread_mutex_lock");
		pthread_exit(NULL);
	}
	rc = pthread_cond_wait(&got_request, &request_mutex);
	if(rc == 0) {
		printf("thr2_fun got to run.\n");
	}
	pthread_mutex_unlock(&request_mutex);
}

int main(int argc, char* argv[])
{
	int thr_id1, thr_id2, rc;
	pthread_t p_thread1, p_thread2;
	thr_id1 = pthread_create(&p_thread1, NULL, thr1_fun, NULL);
	thr_id2 = pthread_create(&p_thread2, NULL, thr2_fun, NULL);
	sleep(1);
	
	rc = pthread_cond_signal(&got_request);
	rc = pthread_cond_signal(&got_request);
	sleep(3);
	printf("main exit.\n");
}
