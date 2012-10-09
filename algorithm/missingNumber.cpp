#include <iostream>
#include <vector>

#include "missingNumber.h"

using namespace std;

void missingNumberTest::test() {
    cout << "adsf" << endl;
    return;
}

ostream& operator<<(ostream& out, const missingNumber& m) {
    for (vector<int>::const_iterator i = m.a.begin(); i != m.a.end(); i++) {
        out << *i << ", ";
    }
    out << endl;

}
