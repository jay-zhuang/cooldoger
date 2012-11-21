#include <iostream>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#include "main.h"

using namespace std;

#define MAX 100

class listNode {
public:
    int data;
    listNode *next;
};

class producerConsumer {
public:
    virtual void add(int a) = 0;
    virtual int remove() = 0;
    virtual ~producerConsumer() {}
};

class pcList : public producerConsumer {
private:
    listNode *head;
    listNode *end;
public:
    virtual void add(int a);
    virtual int remove();
    virtual ~pcList() {

    }
};

class pcArray : public producerConsumer {
private:
    int data[MAX];
    int count;
    pthread_mutex_t m;

public:
    virtual void add(int a) {
        pthread_mutex_lock(&m);
        while (true) {
            if (this->count < MAX) {
                this->data[this->count++] = a;
                break;
            } else {
                pthread_mutex_unlock(&m);
                usleep(1000);
                pthread_mutex_lock(&m);
            }
        }
        pthread_mutex_unlock(&m);
    }

    virtual int remove() {
        int ret = 0;
        pthread_mutex_lock(&m);
        while(true) {
            if (this->count > 0) {
                ret = this->data[--(this->count)];
                break;
            } else {
                pthread_mutex_unlock(&m);
                usleep(1000);
                pthread_mutex_lock(&m);
            }
        }

        pthread_mutex_unlock(&m);
        return ret;
    }

    pcArray() {
        pthread_mutex_init(&(this->m), NULL);
        this->count = 0;
    }

    virtual ~pcArray() {
        pthread_mutex_destroy(&(this->m));
    }

};

class pcArraySem : public producerConsumer {
private:
    int data[MAX];
    int count;
    sem_t semC;
    sem_t semL;
    pthread_mutex_t m;

public:
    virtual void add(int a) {
        sem_wait(&semL);
        pthread_mutex_lock(&m);
        this->data[this->count++] = a;
        pthread_mutex_unlock(&m);
        sem_post(&semC);
    }

    virtual int remove() {
        int ret = 0;
        sem_wait(&semC);
        pthread_mutex_lock(&m);
        ret = this->data[--(this->count)];
        pthread_mutex_unlock(&m);
        sem_post(&semL);
        return ret;
    }

    pcArraySem() {
        pthread_mutex_init(&(this->m), NULL);
        sem_init(&semC, 0, 0);
        sem_init(&semL, 0, MAX);
        this->count = 0;
    }

    virtual ~pcArraySem() {
        sem_destroy(&semC);
        sem_destroy(&semL);
        pthread_mutex_destroy(&(this->m));
    }
};

class pcArrayCond : public producerConsumer {
private:
    int data[MAX];
    int count;
};

void *producer(void *a) {
    producerConsumer *d = (producerConsumer *)a;
    static int i = 0;
    while(true) {
        cout << "adding :";
        cout << i << endl;
        d->add(i++);
        usleep(100000);
    }
}

void *consumer(void *a) {
    producerConsumer *d = (producerConsumer *)a;
    while(true) {
        cout << "removing :";
        cout << d->remove() << endl;
        usleep(300000);
    }
}

void producerConsumerTest::test() {
    pthread_t c, p;
    pcArray a;
    pcArraySem b;

    pthread_create(&c, NULL, consumer, (void *)(&b));
    pthread_create(&p, NULL, producer, (void *)(&b));

    void *status;
    int rc = pthread_join(c, &status);
    rc = pthread_join(p, &status);
}
