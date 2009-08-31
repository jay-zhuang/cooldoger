#include <stdio.h>
#include <pthread.h>

pthread_mutex_t a_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t b_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t c_mutex = PTHREAD_MUTEX_INITIALIZER;

int a = 9;
int b = 9;

void thr1_fun(void){
	int rc;
	printf("thr1\n");
	sleep(1);
	rc = pthread_mutex_lock(&a_mutex);
	printf("[mutex] thr1 lock a_mutex, rc = '%d' \n", rc);
	sleep(1);
	rc = pthread_mutex_lock(&b_mutex);
	printf("[mutex] thr1 lock b_mutex, rc = '%d' \n", rc);
	a = 1;
	printf("thr1 set a finish!\n");
//	rc = pthread_mutex_lock(&a_mutex);
	sleep(1);
	b = 1;
	printf("thr1 set b finish!\n");
	rc = pthread_mutex_unlock(&a_mutex);
	printf("[mutex] thr1 release a_mutex, rc = '%d' \n", rc);
	rc = pthread_mutex_unlock(&b_mutex);
	printf("[mutex] thr1 release b_mutex, rc = '%d' \n", rc);
}

void thr2_fun(void){
	int rc;
	printf("thr2\n");
	sleep(1);
	rc = pthread_mutex_lock(&b_mutex);
	printf("[mutex] thr2 lock b_mutex, rc = '%d' \n", rc);
	sleep(1);
	rc = pthread_mutex_lock(&a_mutex);
	printf("[mutex] thr2 lock a_mutex, rc = '%d' \n", rc);
	a = 2;
	printf("thr2 set a finish!\n");
	sleep(2);
	b = 2;
	printf("thr2 set b finish!\n");
	rc = pthread_mutex_unlock(&b_mutex);
	printf("[mutex] thr2 release b_mutex, rc = '%d' \n", rc);
	rc = pthread_mutex_unlock(&a_mutex);
	printf("[mutex] thr2 release a_mutex, rc = '%d' \n", rc);
}

int main(int argc, char* argv[])
{
	int thr_id1, thr_id2, rc;
	pthread_t p_thread1;
	pthread_t p_thread2;

	thr_id1 = pthread_create(&p_thread1, NULL, thr1_fun, NULL);
	thr_id2 = pthread_create(&p_thread2, NULL, thr2_fun, NULL);
	
	rc = pthread_mutex_lock(&c_mutex);
	rc = pthread_mutex_unlock(&c_mutex);
//	sleep(5);
	printf("Begin to destory the mutex\n");
	rc = pthread_mutex_destroy(&a_mutex);
	printf("[mutex] destory mutex a, rc = '%d' \n", rc);
	rc = pthread_mutex_destroy(&b_mutex);
	printf("[mutex] destory mutex b, rc = '%d' \n", rc);
	rc = pthread_mutex_destroy(&c_mutex);
	printf("[mutex] destory mutex c, rc = '%d' \n", rc);
	printf("Destory the mutex over\n");

	sleep(10);
	printf("a = %d\nb = %d\n", a, b);
	printf("main is over!\n");
}
