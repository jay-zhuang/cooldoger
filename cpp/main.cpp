#include <iostream>
#include <memory>
#include "ccTest.h"
#include "sharedPtr.h"
#include "containerTest.h"
#include "algorithmTest.h"
#include "others.h"

using namespace std;

int main(int argc, char **argv) {
    //ccTest::bridgeTest();
    //cout << "=============================" << endl;
    //sharedPtrTest::test();
    //cout << "=============================" << endl;
    //containerTest::test();
    //cout << "=============================" << endl;
    //findKth::test();
    othersTest::test();
    return 0;
}

