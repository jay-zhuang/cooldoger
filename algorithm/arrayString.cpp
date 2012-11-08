#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <algorithm>
#include <stack>
#include <list>
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

void reverseString(char *s) {
    if (s == NULL) return;
    int len = strlen(s);
    if (len <= 1) return;

    int i = 0, j = len - 1;
    while(i < j) {
        char t = s[i];
        s[i] = s[j];
        s[j] = t;
        i++; j--;
    }
    return;
}

void reverseString2(string& s) {
    reverse(s.begin(), s.end());
    return;
}

class myList {
public:
    int data;
    myList *next;
    myList() {
        this->data = 0;
        this->next = NULL;
    }
};

void printMyList(myList *head) {
    while (head != NULL) {
        cout << head->data << ", ";
        head = head->next;
    }
    cout << endl;
}

void reverseMyList(myList **head) {
    myList *p = NULL, *c = *head, *n = NULL;
    while(c != NULL) {
        n = c->next;
        c->next = p;
        p = c;
        c = n;
    }

    *head = p;
}

void reverseMyList(myList *head) {
    stack<myList *> s;
    myList *c = head, *t = head;

    // push the first half data into the stack
    while(t != NULL) {
        s.push(c);
        c = c->next;
        t = t->next;
        if (t == NULL) {
            s.pop();
        } else {
            t = t->next;
        }
    }
    int d;
    
    while(c != NULL) {
        myList *e = s.top();
        d = e->data;
        e->data = c->data;
        c->data = d;
        c = c->next;
        s.pop();
    }
    return;
}

template<class T>
void reverseList(list<T>& a, typename list<T>::iterator begin, typename list<T>::iterator end) {
    list<T> t;
    list<T> t2;
    t.splice(t.end(), a, begin, a.end());
    t2.splice(t2.end(), t, end, t.end());

    t.reverse();
    a.splice(a.end(), t);
    a.splice(a.end(), t2);
    return;
}

void arrayStringTest::test() {
    vector<char> a;
    a = findUnique3("hello");

    for (vector<char>::iterator i = a.begin(); i != a.end(); i++) {
        cout << *i << ", ";
    }

    char b[10] = "hello";
    cout << b << endl; 
    const char *c = "hello";
    reverseString(b);
    string d = "This is Jay";
    reverseString2(d);
    cout << d << endl;

    myList data[10];

    data[2].data = 11;
    data[2].next = &data[4];

    data[4].data = 22;
    data[4].next = NULL;

    data[3].data = 33;
    data[3].next = &data[6];

    data[6].data = 44;
    data[6].next = &data[9];

    data[9].data = 55;
    data[9].next = NULL;

    myList *head = &data[2];
    
    printMyList(head);
    printMyList(head);

    list<int> aa;
    aa.push_back(11);
    aa.push_back(22);
    aa.push_back(33);
    aa.push_back(44);
    aa.push_back(55);
    aa.push_back(66);
    aa.push_back(77);
    aa.push_back(88);
    list<int>::iterator start = aa.begin();
    list<int>::iterator end = aa.begin();
    start++;
    end++;

    reverseList(aa, start, end); 

    for (list<int>::iterator i = aa.begin(); i != aa.end(); i++) {
        cout << *i << ", ";
    }
    cout << endl;
}
