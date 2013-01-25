#include <vector>
#include <list>
#include <set>
#include <map>
#include <string>
#include <iostream>
#include <unordered_set>
#include <algorithm>

#include "main.h"

using namespace std;

class basicStl {
public:
    void initTest() {
        int a[] = {3, 2, 5, 6, 7, 9, 8, 1, 4, 0};
        int n = sizeof(a)/sizeof(a[0]);
        vector<int> v1(a, a + n);
        for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++) {
            cout << *it << ", ";
        }
        cout << endl;

        list<int> l1(a, a + n);
        for (list<int>::iterator it = l1.begin(); it != l1.end(); it++) {
            cout << *it << ", ";
        }
        cout << endl;

        set<int> s1(a, a + n);
        for (set<int>::iterator it = s1.begin(); it != s1.end(); it++) {
            cout << *it << ", ";
        }
        cout << endl;

        unordered_set<int> us1(a, a + n);
        for (unordered_set<int>::iterator it = us1.begin(); it != us1.end(); it++) {
            cout << *it << ", ";
        }
        cout << endl;

        pair<string, int> p1("aa", 3);
        cout << p1.first << " -> " << p1.second << endl;

        pair<string, int> p2[] = {make_pair("bbbbbbbbbbb", 2), make_pair("cccccccccc", 5)};

        int m = sizeof(p2)/sizeof(p2[0]);

        cout << "sizeof pair array: " << sizeof(p2) << " ; sizeof pair: " << sizeof(p2[0]) <<
        " ; sizeof element first: "<< sizeof(p2[0].first) << " ; sizeof element second: " <<
        sizeof(p2[0].second) << endl;

        map<string, int> m1(p2, p2 + m);
        for (map<string, int>::iterator it = m1.begin(); it != m1.end(); it++) {
            cout << it->first << " => " << it->second << endl;            
        }
        cout << endl;
    }

};

void basicTest::test() {
    basicStl t;
    t.initTest();
}