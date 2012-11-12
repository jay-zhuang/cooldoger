#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <set>
#include <map>
#include "treeGraph.h"

using namespace std;

class treeNode {
public:
    int data;
    treeNode *left;
    treeNode *right;
    treeNode() {
        this->data = 0;
        this->left = NULL;
        this->right = NULL;
    }
};

class graphNode {
public:
    int data;
    list<graphNode*> vects;
    graphNode(int v) {
        this->data = v;
    }
};

class graph {
public:
    list<graphNode*> nodes;

    graph() {
    }

    ~graph() {
        for(list<graphNode*>::iterator i = this->nodes.begin(); i != this->nodes.end(); i++) {
            delete *i;
        }
    }
};

int treeHeight(treeNode *t, bool max) {
    if (t == NULL) return 0;
    int t1 = treeHeight(t->left, max);
    int t2 = treeHeight(t->right, max);
    if (max) {
        return t1 > t2 ? t1 + 1 : t2 + 1;
    } else {
        return t1 > t2 ? t2 + 1 : t1 + 1;
    }
}

bool isBalance(treeNode *root) {
    int t1 = treeHeight(root, true);
    int t2 = treeHeight(root, false);
    cout << t1 << ", " << t2 << endl;
    return t1 - t2 <= 1;
}

void levelTree(treeNode *root, vector<list<treeNode*> >& output) {
    int level = 0;
    if (root == NULL) return;

    list<treeNode*> head;

    head.push_back(root);
    output.push_back(head);

    while(true) {
        list<treeNode*> temp;
        
        for (list<treeNode*>::iterator i = output[level].begin(); i != output[level].end(); i++) {
            if ((*i)->left != NULL) temp.push_back((*i)->left);
            if ((*i)->right != NULL) temp.push_back((*i)->right);
        }

        if (temp.empty()) break;
        else output.push_back(temp);
        level++;
    }
}

bool graphVisit(graphNode *t, graphNode *end, set<graphNode*>& visited) {
    if (t == NULL) return false;
    cout << t->data << endl;
    if (t == end) return true;

    pair<set<graphNode*>::iterator, bool> ret;

    ret = visited.insert(t);
    if (ret.second == false) return false;

    for (list<graphNode*>::iterator i = t->vects.begin(); i != t->vects.end(); i++) {
        bool v = graphVisit(*i, end, visited);
        if (v == true) return true;
    }
    return false;
}

bool isLinked(graph* g, graphNode *start, graphNode *end) {
    if (g == NULL || start == NULL || end == NULL) return false;

    set<graphNode*> visited;
    cout << "end: " << end->data << endl; 

    return graphVisit(start, end, visited);
}

graph* buildGraph() {
    graph* d = new graph;

    graphNode* a[10];

    a[0] = new graphNode(11);
    a[1] = new graphNode(22);
    a[2] = new graphNode(33);
    a[3] = new graphNode(44);
    a[4] = new graphNode(55);

    d->nodes.push_back(a[0]);
    d->nodes.push_back(a[1]);
    d->nodes.push_back(a[2]);
    d->nodes.push_back(a[3]);
    d->nodes.push_back(a[4]);

    a[0]->vects.push_back(a[1]);
    a[0]->vects.push_back(a[3]);

    a[1]->vects.push_back(a[2]);
    
    a[4]->vects.push_back(a[1]);
    a[4]->vects.push_back(a[3]);

    return d;
}

treeNode* buildTree(treeNode d[]) {
    d[0].data = 11;
    d[0].left = &d[1];
    d[0].right = &d[2];

    d[1].data = 22;
    d[1].left = &d[3];
    d[1].right = &d[4];

    d[2].data = 33;
    d[2].left = &d[5];

    d[3].data = 44;

    d[4].data = 55;

    d[5].data = 66;
    d[5].right = &d[6];

    d[6].data = 77;

    return d;
}

void treeGraphTest::test() {
    treeNode data[100];
    treeNode *root = buildTree(data);
    cout << isBalance(root) << endl;
    vector<list<treeNode*> > level;
    levelTree(root, level);

    cout << level.size() << endl;

    int levelNum = 0;
    for (vector<list<treeNode*> >::iterator i = level.begin(); i != level.end(); i++) {
        cout << "Level " << levelNum << ": ";
        levelNum++;
        for (list<treeNode*>::iterator j = (*i).begin(); j != (*i).end(); j++) {
            cout << (*j)->data << ", ";
        }
        cout << endl;
    }

    graph *g = buildGraph();

    list<graphNode*>::iterator it = g->nodes.begin();
    graphNode *start = *(it);
    it++;
    it++;
    graphNode *end = *(it);

    cout << isLinked(g, start, end) << endl;
    delete g;
}
