#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <set>
#include "vectorTest.h"

using namespace std;

class cc {
public:
    cc() {
        for (int i = 9; i >= 0; i--) {
            this->a[i] = i + 11;
        }
    }
    int a[10];
};

void vectorPerf() {
    vector<cc> a(1000);
    vector<int> b;
    list<cc> cc1;
    list<cc> cc2;
    cc c1;
    cc1.push_back(c1);
    cout << sizeof(cc1) << endl;
    cout << cc1.front().a[1] << endl;
    cout << cc2.size() << endl;
    cc2 = cc1;
    cout << cc2.size() << endl;
    list<int> dd1;
    map<int, string> ee;
    set<int, string> ff;
    int size = 0;
    a.reserve(3000);
    a.resize(2000);
    cout << a.max_size() << endl;
    cout << b.max_size() << endl;
    cout << cc1.max_size() << endl;
    cout << dd1.max_size() << endl;
    cout << ee.max_size() << endl;
    cout << ff.max_size() << endl;
    for (int i = 0; i < 1000000; i++) {
        if (a.capacity() != size) {
            size = a.capacity();
            cout << size << endl;
        }
        cc b;
        a.push_back(b);
    }
    a.shrink_to_fit();
    cout << a.capacity() << endl;
}

void arrayPerf() {
    cc a[1000000];
    for (int i = 0; i < 1000000; i++) {
        cc b;
        a[i] = b;
    }
}

void vectorTest::test() {
   vectorPerf(); 
   //arrayPerf();
}
