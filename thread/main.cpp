#include <iostream>
#include "main.h"

using namespace std;

void ccTest::test() {
    cout << "Test not implemented!" << endl;
}

int main(int argc, char** argv) {
    producerConsumerTest pcTest;

    ccTest *t = &pcTest;
    t->test();
    return 0;
}
