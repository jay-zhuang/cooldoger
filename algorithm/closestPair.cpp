#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include "main.h"

using namespace std;

class point {
public:
    int x, y;

    point(int x, int y) {
        this->x = x;
        this->y = y;
    }

    int dist(const point& p) {
        return (this->x - p.x) * (this->x - p.x) + (this->y - p.y) * (this->y - p.y);
    }
};

ostream& operator<<(ostream& output, const point& p) {
    output << "(" << p.x << ", " << p.y << ")";
    return output;
}

pair<point*, point*> closestPair1(vector<point*>& a) {
    pair<point*, point*> ret;
    int len = a.size();
    if (len < 2) return ret;
    ret.first = a[0];
    ret.second = a[1];
    int min = a[0]->dist(*(a[1]));

    for (int i = 0; i < len - 1; i++) {
        for (int j = i + 1; j < len; j++) {
            int d = a[i]->dist(*(a[j]));
            if (d < min) {
                ret.first = a[i];
                ret.second = a[j];
                min = d;
            }
        }
    }

    return ret;
}


void closestPairTest::test() {
    pair<point*, point*> ret;
    vector<point*> a;
    a.push_back(new point(1,2));
    a.push_back(new point(3,4));

    ret = closestPair1(a);
    cout << *(ret.first) << " -> " << *(ret.second) << endl;
}
