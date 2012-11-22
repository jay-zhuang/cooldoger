#include "index.h"

using namespace std;

searchIndex::searchIndex(string fileName) {
    this->fileName = fileName;
    this->dataFile.open(this->fileName);
}

void searchIndex::search(string line) {
    vector<string> input;
    stringstream ss(line);
    string word;
    while(getline(ss, word, ' ')) {
        if (word.size() > 0) input.push_back(word);
    }

    return this->lookup(input);
}

searchIndex::~searchIndex() {
    this->dataFile.close();
    cout << "closing file" << endl;
}

bool posCmp::operator()(const node& n1, const node& n2) {
    return n1.pos < n2.pos;
}

bool valCmp::operator()(const node& n1, const node& n2) {
    return n1.val < n2.val;
}