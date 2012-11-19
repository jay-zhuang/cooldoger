#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include "main.h"

using namespace std;

int countingInversion1(int a[], int len) {
    int ret = 0;
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            if (a[i] > a[j]) ret++;
        }
    }
    return ret;
}

int countingInversion2(int a[], int len) {
    if (len == 0 || len == 1) return 0;

    int *t1 = (int *)malloc(sizeof(int) * len);
    memcpy(t1, a, len * sizeof(int));

    int mid = len/2;
    int ret = 0;
    ret += countingInversion2(t1, mid);
    ret += countingInversion2(t1 + mid, len - mid);

    int i = 0, j = 0, k = 0;
    while (i < len && j < mid && k < len - mid) {
        if (t1[j] > t1[mid + k]) {
            a[i++] = t1[mid + k++];
            ret += (mid - j);
        } else {
            a[i++] = t1[j++];
        }
    }

    while (j < mid) a[i++] = t1[j++];
    while (k < len - mid) a[i++] = t1[mid + k++];

    free(t1);
    return ret;
}

int countingInversion3(int a[], int b[], int len, bool flag) {
    int ret = 0;
    if (len == 1) {
        if (!flag) b[0] = a[0];
        return 0;
    }

    int mid = len/2;
    ret += countingInversion3(a, b, mid, !flag);
    ret += countingInversion3(a + mid, b + mid, len - mid, !flag);

    int *t, *s;

    if (flag) {
        t = a;
        s = b;
    } else {
        t = b;
        s = a;
    }

    int i = 0, j = 0, k = 0;
    while (i < len && j < mid && k < len - mid) {
        if (s[j] > s[mid + k]) {
            t[i++] = s[mid + k++];
            ret += (mid - j);
        } else {
            t[i++] = s[j++];
        }
    }

    while (j < mid) t[i++] = s[j++];
    while (k < len - mid) t[i++] = s[mid + k++];

    return ret;
}

int countingInversion3(int a[], int len) {
    int *t1 = (int *)malloc(sizeof(int) * len);
    int *t2 = (int *)malloc(sizeof(int) * len);
    memcpy(t1, a, len * sizeof(int));

    return countingInversion3(t1, t2, len, true);
}

void countingInversionsTest::test() {
    srand((unsigned int)time(NULL));
    int a[10];
    for (int i = 0; i < 10; i++) a[i] = rand()%100;

    for (int i = 0; i < 10; i++) cout << a[i] << ", ";
    cout << endl;
    cout << countingInversion1(a, 9) << endl;
    //cout << countingInversion2(a, 9) << endl;
    cout << countingInversion3(a, 9) << endl;
}

