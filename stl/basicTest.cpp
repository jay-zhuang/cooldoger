#include <vector>
#include <list>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <string>
#include <iostream>
#include <unordered_set>
#include <algorithm>

#include "main.h"

using namespace std;


class IStlInitTest {
public:
    virtual void empty() = 0;
    virtual void iteratorCopy() = 0;
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
    static const int num = 14;
    const int a[num] = {3, 4, 2, 5, 6, 7, 9, 8, 1, 4, 0};
    const pair<string, int> p[num] = {
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
    static dataTest data;
public:
    string name() { return this->myname; };
    virtual ~stlType() {};
};

void valuePrint(int val) {
    cout << val << ", ";
}

void pairPrint(const pair<string, int> &val) {
    cout << "  " << val.first << " -> " << val.second << endl;
} 

template<typename Iter, typename printFun>
static void print(Iter s, Iter e, printFun fun) {
    while (s != e) {
        fun(*s);
        s++;
    }
    cout << endl;
}

template<typename Iter>
static void print(Iter s, Iter e) {
    print(s, e, valuePrint);
}

// ============ vector
class vectorType : public stlType {
private:
    vector<int> *ve1;
    vector<int> *ve2;
    vector<int> *ve3;
    vector<int> *ve4;

public:
    vectorType() {
        this->myname = "vector";
    }

    virtual void empty() {
        cout << "empty" << endl;
        this->ve1 = new vector<int>();
        vector<int> v1;
    }

    virtual void iteratorCopy() {
        cout << "iteratorCopy" << endl;
        this->ve2 = new vector<int>(data.a, data.a + data.num);
        print(this->ve2->begin(), this->ve2->end());
    }

    virtual void copy() {
        cout << "copy" << endl;
        this->ve3 = new vector<int>(*(this->ve2));
        print(this->ve3->begin(), this->ve3->end());
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

    virtual ~vectorType() {
        if (this->ve1 != NULL) delete this->ve1;
        if (this->ve2 != NULL) delete this->ve2;
        if (this->ve3 != NULL) delete this->ve3;
        if (this->ve4 != NULL) delete this->ve4;
    }
};

// ============ list
class listType : public stlType {
private:
    list<int> *li1;
    list<int> *li2;
    list<int> *li3;
    list<int> *li4;

public:
    listType() {
        this->myname = "list";
    }

    virtual void empty() {
        cout << "empty" << endl;
        this->li1 = new list<int>();
        list<int> l1;
    }

    virtual void iteratorCopy() {
        cout << "iteratorCopy" << endl;
        this->li2 = new list<int>(data.a, data.a + data.num);
        print(this->li2->begin(), this->li2->end());
    }

    virtual void copy() {
        cout << "copy" << endl;
        this->li3 = new list<int>(*(this->li2));
        print(this->li3->begin(), this->li3->end());
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

    virtual ~listType() {
        if (this->li1 != NULL) delete this->li1;
        if (this->li2 != NULL) delete this->li2;
        if (this->li3 != NULL) delete this->li3;
        if (this->li4 != NULL) delete this->li4;
    }
};

// ============ set
class setType : public stlType {
private:
    set<int> *se1;
    set<int> *se2;
    set<int> *se3;
    set<int> *se4;

public:
    setType() {
        this->myname = "set";
    }

    virtual void empty() {
        cout << "empty" << endl;
        this->se1 = new set<int>;
        set<int> s1;
    }

    virtual void iteratorCopy() {
        cout << "iteratorCopy" << endl;
        this->se2 = new set<int>(data.a, data.a + data.num);
        print(this->se2->begin(), this->se2->end());
    }

    virtual void copy() {
        cout << "copy" << endl;
        this->se3 = new set<int>(*(this->se2));
        print(this->se3->begin(), this->se3->end());
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

    virtual ~setType() {
        if (this->se1 != NULL) delete this->se1;
        if (this->se2 != NULL) delete this->se2;
        if (this->se3 != NULL) delete this->se3;
        if (this->se4 != NULL) delete this->se4;
    }
};

// ============ multiset
class multisetType : public stlType {
private:
    multiset<int> *ms1;
    multiset<int> *ms2;
    multiset<int> *ms3;
    multiset<int> *ms4;

public:
    multisetType() {
        this->myname = "multiset";
    }

    virtual void empty() {
        cout << "empty" << endl;
        this->ms1 = new multiset<int>;
        multiset<int> m1;
    }

    virtual void iteratorCopy() {
        cout << "iteratorCopy" << endl;
        this->ms2 = new multiset<int>(data.a, data.a + data.num);
        print(this->ms2->begin(), this->ms2->end());
    }

    virtual void copy() {
        cout << "copy" << endl;
        this->ms3 = new multiset<int>(*(this->ms2));
        print(this->ms3->begin(), this->ms3->end());
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

    virtual ~multisetType() {
        if (this->ms1 != NULL) delete this->ms1;
        if (this->ms2 != NULL) delete this->ms2;
        if (this->ms3 != NULL) delete this->ms3;
        if (this->ms4 != NULL) delete this->ms4;
    }
};

// ============ map
class mapType : public stlType {
private:
    map<string, int> *ma1;
    map<string, int> *ma2;
    map<string, int> *ma3;
    map<string, int> *ma4;

public:
    mapType() {
        this->myname = "map";
    }

    virtual void empty() {
        cout << "empty" << endl;
        this->ma1 = new map<string, int>;
        map<string, int> m1;
    }

    virtual void iteratorCopy() {
        cout << "iteratorCopy" << endl;
        // ordered, the duplicated one will not be inserted
        this->ma2 = new map<string, int>(data.p, data.p + data.num);
        print(this->ma2->begin(), this->ma2->end(), pairPrint);
    }

    virtual void copy() {
        cout << "copy" << endl;
        this->ma3 = new map<string, int>(*(this->ma2));
        print(this->ma3->begin(), this->ma3->end(), pairPrint);
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

    virtual ~mapType() {
        if (this->ma1 != NULL) delete this->ma1;
        if (this->ma2 != NULL) delete this->ma2;
        if (this->ma3 != NULL) delete this->ma3;
        if (this->ma4 != NULL) delete this->ma4;
    }
};

// ============ multimap
class multimapType : public stlType {
private:
    multimap<string, int> *mm1;
    multimap<string, int> *mm2;
    multimap<string, int> *mm3;
    multimap<string, int> *mm4;

public:
    multimapType() {
        this->myname = "multimap";
    }

    virtual void empty() {
        cout << "empty" << endl;
        this->mm1 = new multimap<string, int>;
        multimap<string, int> m1;
    }

    virtual void iteratorCopy() {
        cout << "iteratorCopy" << endl;
        // Ordered
        this->mm2 = new multimap<string, int>(data.p, data.p + data.num);
        print(this->mm2->begin(), this->mm2->end(), pairPrint);
    }

    virtual void copy() {
        cout << "copy" << endl;
        this->mm3 = new multimap<string, int>(*(this->mm2));
        print(this->mm3->begin(), this->mm3->end(), pairPrint);
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

    virtual ~multimapType() {
        if (this->mm1 != NULL) delete this->mm1;
        if (this->mm2 != NULL) delete this->mm2;
        if (this->mm3 != NULL) delete this->mm3;
        if (this->mm4 != NULL) delete this->mm4;
    }
};

// ============ deque
class dequeType : public stlType {
private:
    deque<int> *de1;
    deque<int> *de2;
    deque<int> *de3;
    deque<int> *de4;

public:
    dequeType() {
        this->myname = "deque";
    }

    virtual void empty() {
        cout << "empty" << endl;
        this->de1 = new deque<int>;
        deque<int> d1;
    }

    virtual void iteratorCopy() {
        cout << "iteratorCopy" << endl;
        this->de2 = new deque<int>(data.a, data.a + data.num);
        print(this->de2->begin(), this->de2->end());
    }

    virtual void copy() {
        cout << "copy" << endl;
        this->de3 = new deque<int>(*(this->de2));
        print(this->de3->begin(), this->de3->end());
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

    virtual ~dequeType() {
        if (this->de1 != NULL) delete this->de1;
        if (this->de2 != NULL) delete this->de2;
        if (this->de3 != NULL) delete this->de3;
        if (this->de4 != NULL) delete this->de4;
    }
};

// ============ bitset
class bitsetType : public stlType {
private:
    bitset<10> *bi1;
    bitset<10> *bi2;
    bitset<10> *bi3;
    bitset<10> *bi4;

public:
    bitsetType() {
        this->myname = "bitset";
    }

    virtual void empty() {
        cout << "empty" << endl;
        this->bi1 = new bitset<10>;
        this->bi2 = new bitset<10>("1101001");
        bitset<10> b1;
        cout << *(this->bi2) << endl;
    }

    virtual void iteratorCopy() {
        cout << "iteratorCopy" << endl;
        cout << "No" << endl;
    }

    virtual void copy() {
        cout << "copy" << endl;
        this->bi3 = new bitset<10>(*(this->bi2));
        cout << *(this->bi3) << endl;
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

    virtual ~bitsetType() {
        if (this->bi1 != NULL) delete this->bi1;
        if (this->bi2 != NULL) delete this->bi2;
        if (this->bi3 != NULL) delete this->bi3;
        if (this->bi4 != NULL) delete this->bi4;
    }
};

// ============ queue
class queueType : public stlType {
private:
    queue<int> *qu1;
    queue<int> *qu2;
    queue<int> *qu3;
    queue<int> *qu4;

public:
    queueType() {
        this->myname = "queue";
    }

    virtual void empty() {
        cout << "empty" << endl;
        this->qu1 = new queue<int>;
        queue<int> q1;
    }

    virtual void iteratorCopy() {
        cout << "iteratorCopy" << endl;
        cout << "No" << endl;
    }

    virtual void copy() {
        cout << "copy" << endl;
        deque<int> v1(data.a, data.a + data.num);
        this->qu2 = new queue<int>(v1);
        print(v1.begin(), v1.end());
        
        while (this->qu2->empty() != true) {
            valuePrint(this->qu2->front());
            this->qu2->pop();
        }
        cout << endl;
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

    virtual ~queueType() {
        if (this->qu1 != NULL) delete this->qu1;
        if (this->qu2 != NULL) delete this->qu2;
        if (this->qu3 != NULL) delete this->qu3;
        if (this->qu4 != NULL) delete this->qu4;
    }
};

// ============ priority_queue
class priority_queueType : public stlType {
private:
    priority_queue<int> *pq1;
    priority_queue<int> *pq2;
    priority_queue<int> *pq3;
    priority_queue<int> *pq4;

public:
    priority_queueType() {
        this->myname = "priority_queue";
    }

    virtual void empty() {
        cout << "empty" << endl;
        this->pq1 = new priority_queue<int>;
    }

    virtual void iteratorCopy() {
        cout << "iteratorCopy" << endl;
        cout << "No" << endl;
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

    virtual ~priority_queueType() {
        if (this->pq1 != NULL) delete this->pq1;
        if (this->pq2 != NULL) delete this->pq2;
        if (this->pq3 != NULL) delete this->pq3;
        if (this->pq4 != NULL) delete this->pq4;
    }
};

// ============ stack
class stackType : public stlType {
private:
    stack<int> *st1;
    stack<int> *st2;
    stack<int> *st3;
    stack<int> *st4;

public:
    stackType() {
        this->myname = "stack";
    }

    virtual void empty() {
        cout << "empty" << endl;
        this->st1 = new stack<int>;
        stack<int> s1;
    }

    virtual void iteratorCopy() {
        cout << "iteratorCopy" << endl;
        cout << "No" << endl;
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

    virtual ~stackType() {
        if (this->st1 != NULL) delete this->st1;
        if (this->st2 != NULL) delete this->st2;
        if (this->st3 != NULL) delete this->st3;
        if (this->st4 != NULL) delete this->st4;
    }
};

// ============ pair
class pairType : public stlType {
private:
    pair<string, int> *pa1;
    pair<string, int> *pa2;
    pair<string, int> *pa3;
    pair<string, int> *pa4;

public:
    pairType() {
        this->myname = "pair";
    }

    virtual void empty() {
        cout << "empty" << endl;
        this->pa1 = new pair<string, int>;
        pair<string, int> p1;
    }

    virtual void iteratorCopy() {
        cout << "iteratorCopy" << endl;
        cout << "No" << endl;
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

    virtual ~pairType() {
        if (this->pa1 != NULL) delete this->pa1;
        if (this->pa2 != NULL) delete this->pa2;
        if (this->pa3 != NULL) delete this->pa3;
        if (this->pa4 != NULL) delete this->pa4;
    }
};


class stlTestBase {
private:
    virtual void runTest() = 0;

protected:

    string myTestName;
    stlType *tp;

public:
    string testName() { return this->myTestName; }

    stlTestBase(stlType *type) {
        this->tp = type;
    }

    void test() {
        cout <<
        "================= " <<
        this->testName() << " : " <<
        this->tp->name() <<
        " =================" << endl;
        this->runTest();
    };
};

class initTest : public stlTestBase {
private:
    virtual void runTest() {
        this->tp->empty();
        this->tp->iteratorCopy();
        this->tp->copy();
        this->tp->reserve();
        this->tp->duplicate();
        this->tp->others();
    }
public:
    initTest(stlType *type) : stlTestBase(type) {
        this->myTestName = "constructor";
    }
};

void buildTypes(vector<stlType*>& types) {
    types.push_back(new vectorType());
    types.push_back(new listType());
    types.push_back(new setType());
    types.push_back(new multisetType());
    types.push_back(new mapType());
    types.push_back(new multimapType());
    types.push_back(new dequeType());
    types.push_back(new bitsetType());
    types.push_back(new queueType());
    types.push_back(new priority_queueType());
    types.push_back(new stackType());
    types.push_back(new pairType());
}

void buildTests(vector<stlTestBase*>& tests, const vector<stlType*>& types) {
    for(vector<stlType*>::const_iterator it = types.cbegin();
        it != types.cend(); it++) {
        tests.push_back(new initTest(*it));
    }
}

dataTest stlType::data;

void basicTest::test() {
    vector<stlType*> types;
    vector<stlTestBase*> tests;
    buildTypes(types);
    buildTests(tests, types);
    for (vector<stlTestBase*>::iterator it = tests.begin();
        it != tests.end(); it++) {
        (*it)->test();
    }

    for (vector<stlTestBase*>::iterator it = tests.begin();
        it != tests.end(); it++) {
        delete (*it);
    }

    for (vector<stlType*>::iterator it = types.begin();
        it != types.end(); it++) {
        delete (*it);
    }
}