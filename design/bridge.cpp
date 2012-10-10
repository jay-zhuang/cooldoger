#include <iostream>
#include "bridge.h"

using namespace std;

class classA {
public:
    int i;
    int j;
    int k;
    int l;
};

class classB {
public:
    classB(classA& a):d(a) {
    }
    classA &d;
};

class classC {
public:
    classC(classA *a) : d(a) {
    }
    classA *d;
};

void bridgeTest::test() {
//    TV *tv1 = new TV();
//    remoteButton *r1 = new tvRemote(*tv1);
}

void entertainmentDevice::buttonTwoPressed() {
    this->volumeLevel++;
    cout << "Volume Up: " << this->volumeLevel << endl;
}

void entertainmentDevice::buttonEightPressed() {
    this->volumeLevel--;
    cout << "Volume Down: " << this->volumeLevel << endl;
}

void TV::buttonFourPressed() {
    this->channel--;
    cout << "Channel Down: " << this->channel << endl;
}

void TV::buttonSixPressed() {
    this->channel++;
    cout << "Channel Up: " << this->channel << endl;
}

void DVD::buttonFourPressed() {
    this->chapter--;
    cout << "Previous Chapter: " << this->chapter << endl;
}

void DVD::buttonSixPressed() {
    this->chapter++;
    cout << "Next Chapter: " << this->chapter << endl;
}
