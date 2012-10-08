#include <iostream>
#include "others.h"

using namespace std;

int addfun(int x, int y) {
    return x + y;
}

int addfun(int x, int y, int z) {
    return x + y + z;
}

class add {
public:
    int operator()(int x, int y) const {
        return x + y;
    }
};

add addobj;

void othersTest::test() {
    typedef int (*tripleFun)(int, int, int);
    int (*fun)(int, int);
    fun = addfun;
    tripleFun f2 = addfun;
    cout << (*f2)(1,2,3) << endl;
    cout << (*fun)(1, 3) << endl;
    cout << addobj(1, 4) << endl;
    return;
}
