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

int main(int argc, char** argv) {
    try {
        throwException();
    }
    catch (string *s) {
        cout << "dddd" << endl;
    }
    catch (const char* s) {
        cout << "string" << endl;
    }
    catch (exception& e) {
        cout << "exception" << endl;
    }
    catch (...) {
        cout << "other exception" << endl;
    }
    return 0;
}
