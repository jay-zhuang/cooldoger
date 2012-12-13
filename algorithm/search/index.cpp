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

    cout << "query:" << line << endl;
    this->lookup(input);
    cout << "==============================================================" << endl;
    return;
}

void searchIndex::printResult(set<node, valCmp> res) {
    int i = 0, j = 1;
    string line;
    string field;
    string str;
    long id;


    for (set<node, valCmp>::iterator it = res.begin(); it != res.end(); it++, j++) {
        this->dataFile.clear();
        this->dataFile.seekg(it->pos, ios::beg);
        getline(this->dataFile, line);

        stringstream lineS(line);
        i = 0;

        while(getline(lineS, field, '\t')) {
            i++;
            if (i == 1) {
                id = atol(field.c_str());
            } else if (i == 2) {
                str = field;
            }
        }

        cout << j << ")\t" << id << "\t" << it->val << "\t" << str << endl;
    }
}

searchIndex::~searchIndex() {
    this->dataFile.close();
}

bool posCmp::operator()(const node& n1, const node& n2) {
    return n1.pos < n2.pos;
}

bool valCmp::operator()(const node& n1, const node& n2) {
    return n1.val >= n2.val;
}