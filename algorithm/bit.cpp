#include <iostream>
#include <string>
#include <bitset>
#include <algorithm>
#include "bit.h"

using namespace std;

void printBit(int);

int bitCombine(unsigned int n, unsigned int m, int i, int j) {
    if (i >= j) return n;

    unsigned int x = 0xffffffff;
    x = x >> i;
    x = x << 32 - j + i;
    
    x = x >> 32 - j;
    printBit(x);

    m = m << 32 - j + i; 
    m = m >> 32 - j; 
    printBit(m);
    printBit(~x);
    

    return n & ~x | m;
}

void printBit(int a) {
    bitset<32> x(a);
    cout << x << endl;
}

string decToStr(double a) {
    string intP;
    string decP;

    int v = (int)a;
    a = a - v;
    if (v == 0) {
        intP = '0';
    } else {
        while (v != 0) {
            int d = v % 2;
            intP.push_back(d+'0');
            v >>= 1;
        }
    }
    reverse(intP.begin(), intP.end());

    double f = 0.5;
    while (a != 0) {
        int d;
        if (a >= f) {
            a -=f;
            d = 1;
        }
        else {
            d = 0;
        }
        decP.push_back(d+'0');
        if (decP.size() > 32) break;
        f /= 2;
    }
    
    return intP + "." + decP;
}

void bitTest::test() {
    int n = 223;
    int m = 5;
    printBit(n);
    printBit(m);

    int x = bitCombine(n, m, 10, 13);
    printBit(x);

    printBit(123);
    cout << decToStr(123.751);
}
