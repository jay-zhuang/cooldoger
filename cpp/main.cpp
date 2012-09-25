#include <iostream>
#include <memory>
#include "ccTest.h"
#include "sharedPtr.h"
#include "containerTest.h"

using namespace std;

int main(int argc, char **argv) {
    cout << "hello jay" << endl;
    ccTest::bridgeTest();
    cout << "=============================" << endl;
    sharedPtrTest::test();
    cout << "=============================" << endl;
    containerTest::test();
    return 0;
}

