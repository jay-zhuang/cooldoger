#include <iostream>
#include "main.h"

using namespace std;

void ccTest::test() {
    cout << "Test not implemented!" << endl;
}

int main(int argc, char** argv) {
    producerConsumerTest pcTest;
    threadTest tTest;

    ccTest *t = &pcTest;
    //t = &tTest;
    t->test();
    return 0;
}
