#include <iostream>
#include <vector>
#include <pthread.h>
#include "main.h"

using namespace std;

class ccThread {
public:

    void count(int a) {
        for (int i = 0; i < 10; i++)
            cout << a++;
    };

    void run() {
        cout << "running" << endl;
        vector<thread> ths;
        for(int i = 0; i < 5; i++) {
            pthread_thread_create();
        }
    }
};

void threadTest::test() {
    cout << "asdfadf" << endl;
}
