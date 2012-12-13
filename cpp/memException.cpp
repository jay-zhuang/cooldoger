#include <iostream>
#include <typeinfo>
#include <string>
#include <new>

using namespace std;

void noMoreMemory() {
    cerr << "no enough memory" << endl;
    throw bad_alloc();
    abort();
}

void throwException() {
    //throw new string("cccc");
    throw "hihihi";
}

