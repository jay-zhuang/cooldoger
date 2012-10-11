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

int *myfun1(int *i) {
    (*i)++;
    return i;
}

int *myfun2(int *i, int *j) {
    (*i)++;
    (*j)++;
    return i;
}

long myfun3(int *i) {
    (*i)++;
    return *i;
}

int myfun4(int i) {
    i++;
    return i;
}

class ofun1 {
public:
    int operator()(int i) {
        (i)++;
        return i;
    }
};

class copytest {
public:
    copytest(int v): value(v) { cout << "copytest constructor: " << v << endl; }
    int value;
    copytest operator=(int v) {
        this->value = v;
        return *this;
    }
};

class oper1 {
public:
    int value;
};

class operOver {
public:
    int value;
    operator int() const {
        return this->value + 10;
    }
    operator oper1() const {
        oper1 *o1 = new oper1();
        o1->value = 12;
        return *o1;
    }
};

void function_test() {
    int (*a)(int *);
    int (*f4)(int);
    a = (int (*)(int *))myfun3;
    void *vv = (void *)myfun3;
    typedef int(*myFun)(int *);
    myFun c;
    c = a;
    int i = 10;
    long j = 10;
    a(&i);
    ofun1 of1;
    int k = of1(j);
    f4 = myfun4;
    k = f4(j);
    cout << i << endl;

    copytest t1(1);
    t1.value = 110;
    copytest t2(t1);
    t2 = 13;
    t2 = 14;
    cout << t2.value << endl;
    copytest t3(1);
    t3 = t1;
    cout << t3.value << endl;

    operOver o1;
    o1.value = 1;
    cout << o1 << endl;
    oper1 o2 = (oper1)(o1);
    cout << o2.value << endl;
}

void f2() throw(copytest) {
    copytest t(1);
    oper1 t2;
    throw t2;
    throw t;
}

void f1() {
    oper1 t;
    throw t;
}

void exception_test() {
    try {
        f2();
    } catch (copytest& t) {
        cout << "catch the copytest exception. " << endl; 
    }
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
    //test();
    exception_test();
    return 0;
}

