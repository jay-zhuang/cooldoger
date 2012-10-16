#include <iostream>
#include "isBST.h"

using namespace std;

static int prevalue = 0;

bool isBSTTest::isBST(tree *t) {
    if (t == NULL) return true;
    if (isBSTTest::isBST(t->left) == false) return false;
    if (prevalue > t->data) return false;
    prevalue = t->data;
    if (isBSTTest::isBST(t->right) == false) return false;
    return true;
}

void isBSTTest::test() {
    tree *t = new tree(8);
    t->left = new tree(4);
    t->right = new tree(10);
    t->right->left = new tree(9);
    cout << isBSTTest::isBST(t) << endl;
}

tree::tree(int v) {
    this->data = v;
    this->right = NULL;
    this->left = NULL;
}
