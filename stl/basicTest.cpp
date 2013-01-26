#include <vector>
#include <list>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <string>
#include <iostream>
#include <unordered_set>
#include <algorithm>

#include "main.h"

using namespace std;


class IStlInitTest {
public:
    virtual void empty() = 0;
    virtual void copy() = 0;
    virtual void reserve() = 0;
    virtual void duplicate() = 0;
    virtual void others() = 0;
};

class IStlInsertTest {
public:
    virtual void head() = 0;
    virtual void tail() = 0;
    virtual void mid() = 0;
};

class IStlType : public IStlInitTest {

};

class dataTest {
public:
    const int ar[14] = {3, 4, 2, 5, 6, 7, 9, 8, 1, 4, 0};
    const pair<string, int> pa[14] = {
        make_pair("book", 99),
        make_pair("like", 22),
        make_pair("book", 33),
        make_pair("jay", 66),
        make_pair("car", 77),
        make_pair("phone", 88),
        make_pair("glass", 55),
        make_pair("apple", 11),
        make_pair("tree", 44),
        make_pair("dog", 00),
    };
};

class stlType : public IStlType {
protected:
    string myname;
public:
    string name() { return this->myname; };
    virtual ~stlType() {};
};

class vectorType : public stlType {
public:
    vectorType() {
        this->myname = "vector";
    }

    virtual void empty() {
        cout << "empty" << endl;
    }

    virtual void copy() {
        cout << "copy" << endl;
    }

    virtual void reserve() {
        cout << "reserve" << endl;
    }

    virtual void duplicate() {
        cout << "duplicate" << endl;
    }

    virtual void others() {
        cout << "others" << endl;
    }
};


class stlTestBase {
private:
    virtual void runTest() = 0;
protected:
    static dataTest data;
    stlType *tp;

public:
    stlTestBase(stlType *type) {
        this->tp = type;
    }

    void test() {
        this->runTest();
    };
};

class initTest : public stlTestBase {
private:
    virtual void runTest() {
        this->tp->empty();
        this->tp->copy();
        this->tp->reserve();
        this->tp->duplicate();
        this->tp->others();
    }
public:
    initTest(stlType *type) : stlTestBase(type) {}
};

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
        for (unordered_set<int>::iterator it = us1.begin();
            it != us1.end(); it++) {
            cout << *it << ", ";
        }
        cout << endl;

        pair<string, int> p1("aa", 3);
        cout << p1.first << " -> " << p1.second << endl;

        pair<string, int> p2[] = {
                                    make_pair("bbbbbbbbbbb", 2),
                                    make_pair("cccccccccc", 5),
                                    make_pair("asdfasdf", 7),
                                    make_pair("eeeaaaa", 4),
                                    make_pair("cccccccccc", 6)
                                };

        int m = sizeof(p2)/sizeof(p2[0]);

        cout << "sizeof pair array: " << sizeof(p2) << " ; sizeof pair: " << sizeof(p2[0]) <<
        " ; sizeof element first: "<< sizeof(p2[0].first) << " ; sizeof element second: " <<
        sizeof(p2[0].second) << endl;

        map<string, int> m1(p2, p2 + m);
        for (map<string, int>::iterator it = m1.begin(); it != m1.end(); it++) {
            cout << it->first << " => " << it->second << endl;            
        }
        cout << endl;

        multimap<string, int> m2(p2, p2 + m);
        for (multimap<string, int>::iterator it = m2.begin(); it != m2.end(); it++) {
            cout << it->first << " -> " << it->second << endl;
        }
        cout << endl;
    }

};

void buildTypes(vector<stlType*>& types) {
    types.push_back(new vectorType());
}

void buildTests(vector<stlTestBase*>& tests, const vector<stlType*>& types) {
    for(vector<stlType*>::const_iterator it = types.cbegin();
        it != types.cend(); it++) {
        tests.push_back(new initTest(*it));
    }
}

void basicTest::test() {

    vector<stlType*> types;
    vector<stlTestBase*> tests;
    buildTypes(types);
    buildTests(tests, types);
    for (vector<stlTestBase*>::iterator it = tests.begin();
        it != tests.end(); it++) {
        (*it)->test();
    }
}