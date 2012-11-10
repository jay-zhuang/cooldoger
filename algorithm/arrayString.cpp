#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "arrayString.h"

using namespace std;

vector<char> findUnique(string a) {
    vector<char> ret;
    vector<int> hash(256, 0);

    for (string::iterator i = a.begin(); i != a.end(); i++) {
        if (hash[*i] == 0) {
            hash[*i] = 1;
        }
        else if (hash[*i] == 1) {
            hash[*i] = 2;
        }
    }

    for (int i = 0; i < hash.size(); i++) {
        if (hash[i] == 1) ret.push_back(static_cast<char>(i));
    }

    return ret;
}

vector<char> findUnique2(string a) {
    vector<char> ret;

    sort(a.begin(), a.end());
    for (int i = 0; i < a.size();) {
        int j = 1;
        while (a[i] == a[i+j]) j++;
        if (j == 1) ret.push_back(a[i]);
        i += j;
    }

    return ret;
}

vector<char> findUnique3(string a) {
    vector<char> ret;

    for (string::iterator i = a.begin(); i != a.end(); i++) {
        bool found = false;
        for (string::iterator j = a.begin(); j != a.end(); j++) {
            if (i != j && *i == *j) { found = true; break; }
        }
        if (!found) ret.push_back(*i);
    }

    return ret;
}

struct node {
    char c;
    int v;
};

struct nodeCmp : public binary_function<node*, node*, bool> {
    bool operator()(node* a, node* b) {
        return a->v < b->v;
    }
};

nodeCmp nCmp;

vector<char> findUnique4(string a) {
    vector<char> ret;
    vector<node *> hash(257, NULL);

    int t = 1;
    for (string::iterator i = a.begin(); i != a.end(); i++) {
        if (hash[*i] == NULL) {
            node *n = new node();
            n->c = *i;
            n->v = t++;
            hash[*i] = n;
        }
        else if (hash[*i]->v > 0) hash[*i]->v = -(hash[*i]->v);
    }

    sort(hash.begin(), hash.end(), nCmp);

    for (vector<node *>::iterator i = hash.begin(); i != hash.end(); i++) {
        if (*i != NULL && (*i)->v > 0) ret.push_back((*i)->c);
    }

    return ret;
}

void arrayStringTest::test() {
    vector<char> a;
    a = findUnique3("hello");

    for (vector<char>::iterator i = a.begin(); i != a.end(); i++) {
        cout << *i << ", ";
    }
    cout << endl;
}
