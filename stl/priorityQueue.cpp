#include <queue>
#include <stack>
#include <vector>
#include <iostream>
#include "priorityQueue.h"

using namespace std;

class node {
public:
    int data;
    node *next;
    node(int v) : data(v) {}
};

struct nodeCmp : public binary_function<node*, node*, bool> {
    int operator() (node *l, node *r) {
        return l->data > r->data;
    }
};

void queueTest::test() {
    priority_queue<node*, vector<node*>, nodeCmp> pq;

    pq.push(new node(12));
    pq.push(new node(14));
    pq.push(new node(11));

    while (!pq.empty()) {
        cout << pq.top()->data << endl;
        pq.pop();
    }

    priority_queue<int, vector<int>, greater<int>> pq2;

    pq2.push(3);
    pq2.push(12);
    pq2.push(7);

    cout << endl;

    while (!pq2.empty()) {
        cout << pq2.top() << endl;
        pq2.pop();
    }

}
