#include <iostream>
#include <map>
#include <string>
#include <stdio.h>
#include <string.h>
#include "multiplication.h"

using namespace std;

long multi1(int a, int b) {
    long ret = 0;

    while (b-- > 0) ret += a;
    return ret;
}

long multi2(int a, int b) {
    long ret = 0;

    if (b > a) {
        int t = a;
        a = b;
        b = t;
    }

    while (b-- > 0) ret += a;
    return ret;
}

long multi3(int a, int b) {
    long ret = 0;

    if (b > a) {
        a = a^b;
        b = a^b;
        a = a^b;
    }

    long base = a;
    while (b > 0) {
        if (b % 2) {
            ret += base;
        }
        b >>= 1;
        base <<= 1;
    }
    return ret;
}

long multi4(int a, int b) {
    long ret = 0;
    if (b > a) {
        a = a^b;
        b = a^b;
        a = a^b;
    }

    map<int, int> temp;

    for(int i = 0; i < 32; i++) {
        temp.insert(pair<int, int>(1 << i, i));
    }

    long base = a;
    while (b > 0) {
        int n = temp[(b & (-b))];
        b >>= n;
        base <<= n;
        b--;
        ret += base;
    }
    return ret;
}

int preCalc[8][8];

void initPreCalc() {
    static bool inited = false;
    if (!inited) {
        for (int i = 1; i < 8; i++) {
            for (int j = 1; j < 8; j++) {
                preCalc[i][j] = preCalc[i-1][j] + j;
            }
        }
        inited = true;
    }
}

long multi5(int a, int b) {
    long ret = 0;
    initPreCalc();

    for (int i = 0; a > 0; i++, a >>= 3) {
        for (int j = 0, t = b; t > 0; j++, t >>= 3) {
            ret += (preCalc[a%8][t%8] << ((i + j) * 3));
        }
    }

    return ret;
}

long multi6(int a, int b) {
    long ret = 0;
    initPreCalc();

    if (a < 8 && b < 8) return preCalc[a][b];

    ret += preCalc[a%8][b%8];
    ret += (multi6(a >> 3, b >> 3) << 6);
    ret += ((multi6(a >> 3, b % 8) + multi6(b >> 3, a % 8)) << 3);
    return ret;
}

long multi7(int a, int b) {
    long ret = 0;
    initPreCalc();
    
    if (a < 8 && b < 8) return preCalc[a][b];
    long t = multi7(a >> 3, b >> 3);
    ret += (t << 6);
    ret += preCalc[a%8][b%8];
    t += preCalc[a%8][b%8];

    ret += ((multi7((a >> 3) + (a % 8), (b >> 3) + (b % 8)) - t) << 3);
    return ret;
}

long multi8(int a, int b, int i, int j) {
    cout << "multi8 a = " << a << " b = " << b << " i = " << i << " j = " << j << endl;
    long ret = 0;

    if (a < 8 && b < 8) {
        cout << "a: " << a << " b: " << b << " -> " << preCalc[a][b] << endl;
        return preCalc[a][b];
    }

    if (a == 0 || b == 0) return 0;

    int m = i > j ? i : j;
    m = (m + 1) / 2;

    int a1 = a >> (m * 3);
    int b1 = b >> (m * 3);
    int a2 = a & ~(-1 << (m * 3));
    int b2 = b & ~(-1 << (m * 3));

    long t1 = multi8(a1, b1, i - m, j - m);
    long t2 = multi8(a2, b2, m, m);

    ret += (t1 << m*6);
    ret += t2;

    int n = m;
    if ((a1+a2) >> (m*3) > 0 || (b1+b2) >> (m*3) > 0) n++;
    ret += ((multi8(a1 + a2, b1 + b2, n, n) - t1 - t2) << (m*3));
    cout << "a: " << a << " b: " << b << " ret: " << ret << " m: " << m << endl;
    return ret;
}

long multi8(int a, int b) {
    long ret = 0;
    initPreCalc();

    int i = 0, j = 0;

    while(a >> i) i++;
    while(b >> j) j++;

    i = (i+2)/3;
    j = (j+2)/3;

    return multi8(a, b, i, j);
}

void multiplicationTest::test() {
    cout << multi1(10, 100) << endl;
    cout << multi3(98, 66) << endl;
    cout << multi4(110, 100) << endl;
    cout << multi5(110, 100) << endl;
    cout << multi5(10, 100) << endl;
    cout << multi5(98, 66) << endl;
    cout << multi6(98, 66) << endl;
    cout << multi7(98, 66) << endl;
    cout << multi8(97, 3) << endl;
    cout << multi8(10, 100) << endl;

}
