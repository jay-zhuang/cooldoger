#include "index.h"

using namespace std;

hashIndex::hashIndex(string fileName) : searchIndex(fileName) {}

hashIndex::~hashIndex() {
    cout << "hash index destructor" << endl;
}

void hashIndex::insert(const string& word, const node& n) {
    cout << "insert" << endl;
}

void hashIndex::lookup(vector<string> input) {
    cout << "lookup" << endl;
}
