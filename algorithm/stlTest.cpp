#include <iostream>
#include <bitset>
#include <algorithm>
#include <map>
#include "stlTest.h"

using namespace std;

void stlTest::test() {
    bitset<20> b;
    b.set();
    b.reset(10);
    b.reset(2);
    cout << b.to_string() << endl;
    cout << b.any() << endl;;
    for (int i = 0; i < b.size(); i ++) {
        cout << b[i] << ", ";
    }
    cout << endl;

    map<int, bitset<20>*> m;

    for (int i = 0; i < 10; i++) {
        m.insert(pair<int, bitset<20>*>(i, new bitset<20>(i+1)));
    }

    for (int i = 0; i < 20; i++) {
        m.insert(pair<int, bitset<20>*>(20-i, new bitset<20>(2000-i)));
    }

    m[0] = new bitset<20>(111);
    for (map<int, bitset<20>*>::iterator i = m.begin(); i != m.end(); i++) {
        cout << (*i).first << "->" << (*i).second->to_string() << endl;
    }

    cout << "===============" << endl;
    multimap<int, bitset<20>*> mm;

    for (int i = 0; i < 10; i++) {
        mm.insert(pair<int, bitset<20>*>(i, new bitset<20>(i+2)));
    }

    for (int i = 0; i < 20; i++) {
        mm.insert(pair<int, bitset<20>*>(20-i, new bitset<20>(200-i)));
    }

    for (multimap<int, bitset<20>*>::iterator i = mm.begin(); i != mm.end(); i++) {
        cout << (*i).first << "=>" << (*i).second->to_string() << endl;
    }

}
