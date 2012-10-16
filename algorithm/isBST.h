class tree {
public:
    int data;
    tree(int);
    tree *left;
    tree *right;
};

class isBSTTest {
public:
    static bool isBST(tree*);
    static void test();
};
