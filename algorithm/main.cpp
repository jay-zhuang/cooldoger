#include <iostream>
#include <vector>
#include "main.h"
#include "retangleOverlap.h"
#include "stlTest.h"
#include "missingNumber.h"
#include "isBST.h"
#include "arrayString.h"
#include "treeGraph.h"
#include "stackQueue.h"
#include "bit.h"
#include "recursion.h"
#include "sortSearch.h"
#include "multiplication.h"

using namespace std;

void ccTest::test() {
    cout << "Test function is not implemented." << endl;
    return;
}

int main(int argc, char** argv) {
    //isBSTTest::test();
    //arrayStringTest t;
    //treeGraphTest t;
    //stackQueueTest t;
    //bitTest t;
    //recursionTest t;
    //sortSearchTest t;
    //multiplicationTest t;
    countingInversionsTest countingTest;
    closestPairTest closestTest;
    ccTest *t = &closestTest;

    t->test();
    return 0;
}
