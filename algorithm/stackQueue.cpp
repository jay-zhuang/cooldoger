#include <iostream>
#include <stack>
#include <queue>
#include "stackQueue.h"

using namespace std;

class myStack {
private:
    stack<int> s;
    stack<int> minS;
    stack<int> maxS;
public:
    bool empty() {
        return s.empty();
    }

    void pop() {
        int v = s.top();

        if (v == minS.top()) {
            minS.pop();
        }
        if (v == maxS.top()) {
            maxS.pop();
        }
        s.pop();
    }

    int top() {
        return this->s.top();
    }

    void push(int data) {
        s.push(data);
        if (maxS.empty() || data >= maxS.top()) {
            maxS.push(data);
        }

        if (minS.empty() || data <= minS.top()) {
            minS.push(data);
        }
    }

    int min() {
        return minS.top();
    }

    int max() {
        return maxS.top();
    }
};

class myQueue {
private:
    stack<int> s1, s2;

public:
    int empty() {
        return s1.empty() && s2.empty();
    }
 
    int size() {
        return s1.size() + s2.size();
    }

    int top() {
        return s2.top();
    }

    void push(int data) {
        if (s1.empty() && s2.empty()) {
            this->s2.push(data);
        }
        else {
           this->s1.push(data);
        }
    }

    void pop() {
        s2.pop();
        if (s2.empty()) {
            while(!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        
    }
};

void stackSort(stack<int>& s) {
    stack<int> t;
    while(!s.empty()) {
        int v = s.top();
        cout << "temp: " << v << endl;
        s.pop();
        while(!t.empty() && v < t.top()) {
            s.push(t.top());
            t.pop();
        }
        t.push(v);
        while(!s.empty() && s.top() >= t.top()) {
            t.push(s.top());
            s.pop();
        }
    }

    while(!t.empty()) {
        s.push(t.top());
        t.pop();
    }
}

void stackQueueTest::test() {
    myStack ss;
    ss.push(1);
    ss.push(3);
    ss.push(6);
    ss.push(4);

    cout << "min: " << ss.min() << endl;
    cout << "max: " << ss.max() << endl;

    ss.pop();
    ss.pop();
    cout << "min: " << ss.min() << endl;
    cout << "max: " << ss.max() << endl;

    ss.push(1);
    ss.push(10);
    
    cout << "min: " << ss.min() << endl;
    cout << "max: " << ss.max() << endl;

    myQueue qq;
    qq.push(4);
    qq.push(9);
    qq.push(22);
    qq.push(3);
    cout << "My Queue: ";
    while (!qq.empty()) {
        cout << qq.top() << ", ";
        qq.pop();
    }

    cout << endl;

    stack<int> s2;

    s2.push(5);
    s2.push(8);
    s2.push(1);
    s2.push(111);
    s2.push(999);
    s2.pop();
    s2.push(66);
    s2.push(1);

    stackSort(s2);
    while (!s2.empty()) {
        cout << s2.top() << ", ";
        s2.pop();
    }
    cout << endl;

}
