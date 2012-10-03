#include <iostream>
#include <vector>
#include "retangleOverlap.h"

using namespace std;

void retangleOverlap::test() {
    struct retangle x;
    x.a.first = 10;
    x.a.second = 11;
    x.b.first = 13;
    x.b.second = 16;

    cout << x.a.first << endl;
}

bool retangleOverlap::isOverlap(struct retangle& x, struct retangle& y) {
    if (x.a.first > y.a.first) {
        if (x.a.first >= y.b.first) return false;
    }
    else {
        if (x.a.first <= y.b.first) return false;
    }

    if (x.a.second > y.a.second) {
        if (x.a.second >= y.b.second) return false;
    }
    
}
