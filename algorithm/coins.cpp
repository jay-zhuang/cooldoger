#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>
#include "coins.h"

using namespace std;

int coinsTest::maxCoins(int a[], int n, int &m) {
    int i;

    if (n == 1) return a[0];
    if (n == 2) return a[0] > a[1] ? a[0] : a[1];

    int t1 = a[0] + coinsTest::maxCoins(a+1, n-1, );
    int t2 = a[n-1] + coinsTest::maxCoins(a, n-1, );

    return t1 > t2 ? t1 : t2;
}

void coinsTest::test() {
    int n = 10;
    int a[100];
    for (int i = 0; i < n; i++) {
        a[i] = i+1;
    }
    srand(unsigned(time(NULL)));
    random_shuffle(&(a[0]), &(a[n]));

    for (int i = 0; i < n; i++) {
        cout << a[i] << ", ";
    }

    cout << endl;

    for (int i = 0; i < n; i++)
    {
        cout << coinsTest::maxCoins(a, i+1) << endl;
    }

    cout << endl;
}

