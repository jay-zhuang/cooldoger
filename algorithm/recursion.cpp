#include <iostream>
#include <vector>
#include <string>
#include <bitset>
#include "recursion.h"

using namespace std;

void printPar(int l, int r, char* str, int n) {
    if (l > r) return;
    if (l == 0 && r == 0) cout << str << endl;
    if (l > 0) {
        str[n] = '(';
        printPar(l - 1, r, str, n+1);
    }
    if (r > 0) {
        str[n] = ')';
        printPar(l, r - 1, str, n+1);
    }
}

void printPar(int n) {
    char str[n*2+1];
    str[2*n] = '\0';
    printPar(n, n, str, 0);
}

bool checkChess(vector<int>& b, int row) {
    for (int i = 0; i < row; i++) {
        int j = b[row] > b[i] ? b[row] - b[i] : b[i] - b[row];
        if (j == 0 || j == row - i) return false;
    }
    return true;
}

char board[8][9] = {
    "*-------",
    "-*------",
    "--*-----",
    "---*----",
    "----*---",
    "-----*--",
    "------*-",
    "-------*",
};

void printBoard(vector<int>& b) {
    static int num = 0;
    cout << num++ << endl;
    for (int i = 0; i < 8; i++) {
        cout << board[b[i]] << endl;
    }
    cout << endl;
}

void placeChess(vector<int>& b, int row) {
    if (row == 8) {
        printBoard(b);
        return;
    }

    for (int i = 0; i < 8; i++) {
        b[row] = i;
        if (checkChess(b, row)){
            placeChess(b, row + 1);
        }
    }
}

void printQueens() {
    vector<int> board(8);
    placeChess(board, 0);
}

void placeChess(vector<int>& b, bitset<8>& a, bitset<16>& c, bitset<16>& d, int row) {
    if (row == 8) {
        printBoard(b);
        return;
    }

    for (int i = 0; i < 8; i++) {
        if (a[i] == 0 && c[row-i+8] == 0 && d[row+i] == 0) {
            a[i] = 1;
            c[row-i+8] = 1;
            d[row+i] = 1;
            b[row] = i;
            placeChess(b, a, c, d, row + 1);
            a[i] = 0;
            d[row+i] = 0;
            c[row-i+8] = 0;
        }
    }
}

void printQueens2() {
    bitset<8> a(0);
    bitset<16> c(0);
    vector<int> b(8);
    bitset<16> d(0);
    placeChess(b, a, c, d, 0);
}

void recursionTest::test() {
    //printPar(3);
    printQueens2();
}

