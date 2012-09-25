#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <functional>
#include "containerTest.h"

using namespace std;

void containerTest::test() {
    string str("hello jay");

    sort(str.begin(), str.end());

    cout << str << endl;

    string str2("Hello Jay");

    list<char> myList;
    set<char> mySet;
    map<char, int> myMap;

    for(string::iterator i = str2.begin(); i != str2.end(); i++) {
        myList.push_back(*i);
        mySet.insert(*i);
        myMap.insert(pair<char, int>(*i, (*i)));
    }

    // sort(myList.begin(), myList.end());
    myList.sort();

    for(list<char>::iterator i = myList.begin(); i != myList.end(); i++) {
        cout << *i << ", ";
    }
    cout << endl;
    
    for(set<char>::iterator i = mySet.begin(); i != mySet.end(); i++) {
        cout << *i << ", ";
    }
    cout << endl;

    for(map<char, int>::iterator i = myMap.begin(); i != myMap.end(); i++) {
        cout << (*i).first << " => " << (*i).second << endl;
    }
}
