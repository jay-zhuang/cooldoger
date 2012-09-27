#include <vector>
#include <iostream>
#include "algorithmTest.h"

using namespace std;

void findKth::test() {
    int t1[] = {2, 8, 10, 40};
    int t2[] = {1, 3, 4, 50, 90, 100, 101, 103, 105};

    vector<int> a = vector<int>(t1, t1 + 4);
    vector<int> b = vector<int>(t2, t2 + 9);

    cout << findKth::find(a, b, 9) << endl;
}

int findKth::find(vector<int> a, vector<int> b, int k) {
    if (k > a.size() + b.size()) return -1;    

    vector<int>::iterator i = a.begin();
    vector<int>::iterator j = b.begin();

    while (--k) {
        if (*i < *j) i++;
        else j++;
        if (i == a.end()) return *(j+k-1);
        if (j == b.end()) return *(i+k-1);
    }

    return *i < *j ? *i : *j;
}
