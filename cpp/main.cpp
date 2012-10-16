#include <iostream>
#include <memory>
#include "ccTest.h"
#include "sharedPtr.h"
#include "containerTest.h"
#include "algorithmTest.h"
#include "others.h"

using namespace std;

class foo {
public:
    int value;
};

class bar {
public:
    foo* f_p;
};

class bar2 {
public:
    foo& f;
};

void test() {
    cout << sizeof(bar) << endl;
    cout << sizeof(bar2) << endl;
}

int main(int argc, char **argv) {
    //ccTest::bridgeTest();
    //cout << "=============================" << endl;
    //sharedPtrTest::test();
    //cout << "=============================" << endl;
    //containerTest::test();
    //cout << "=============================" << endl;
    //findKth::test();
    //othersTest::test();
    test();
    return 0;
}

