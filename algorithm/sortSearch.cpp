#include <iostream>
#include <vector>
#include <string>
#include "sortSearch.h"

using namespace std;

int findRotated(char a[], int start, int end, int v) {
    int nS, nE;
    int mid = (start + end) / 2;
    if (v == a[mid]) return mid;

    if (start >= end) return -1;
    if (start == mid) {
        nS = end;
        nE = end;
    } else if (v >= a[start] && v < a[mid]) {
        nS = start;
        nE = mid;
    } else if (v > a[mid] && v <= a[end]) {
        nS = mid;
        nE = end;
    } else if (a[start] > a[mid]) {
        nS = start;
        nE = mid;
    } else if (a[mid] > a[end]) {
        nS = mid;
        nE = end;
    } else if (a[start] == a[mid] && a[mid] == a[end]) {
        nS = start + 1;
        nE = end - 1;
    } else {
        return -1;
    }

    return findRotated(a, nS, nE, v);
}

int findRotated(char a[], int n, int v) {
    return findRotated(a, 0, n - 1, v); 
}

void sortSearchTest::test() {
    char a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    //char a[10] = {2, 2, 2, 2, 2, 2, 2, 1, 2};
    cout << findRotated(a, 9, 9) << endl;
    cout << "ssssss" << endl;
}
