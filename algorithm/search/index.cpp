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

void searchIndex::buildSearchIndex() {
    if (!this->dataFile) throw "File not found.";

    string line;
    string field;
    string word;

    node n;

    n.pos = 0;
    n.val = 0;

    int i = 0;
    long nextPos = 0;
    long idx = 0;
    string str;

    while(getline(this->dataFile, line)) {

        stringstream lineS(line);
        i = 0;
        nextPos = this->dataFile.tellg();

        while(getline(lineS, field, '\t')) {
            i++;
            if (i == 2) {
                str = field;
            } else if (i == 3) {
                n.val = atoi(field.c_str());
            }
        }

        stringstream strS(str);

        while(getline(strS, word, ' ')) {
            if (word.size() > 0) {
                this->insert(word, idx);
            }
        }

        this->store.push_back(n);
        idx++;
        n.pos = nextPos;
    }

    this->dataFile.clear();
}

void searchIndex::printNode(const node& nd, int n) {
    int i = 0;
    string line;
    string field;
    string str;
    long id;

    this->dataFile.clear();
    this->dataFile.seekg(nd.pos, ios::beg);
    getline(this->dataFile, line);

    stringstream lineS(line);
    while(getline(lineS, field, '\t')) {
        i++;
        if (i == 1) {
            id = atol(field.c_str());
        } else if (i == 2) {
            str = field;
        }
    }

    cout << n << ")\t" << id << "\t" << nd.val << "\t" << str << endl;
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


void searchIndex::printResult(vector<long> res) {
    int i = 1;
    idxValCmp myIdxValCmp(&(this->store));

    sort(res.begin(), res.end(), myIdxValCmp);

    for (vector<long>::iterator it = res.begin(); it != res.end(); it++, i++) {
        this->printNode(this->store[*it], i);
    }
}

void searchIndex::buildIndex() {
    this->buildSearchIndex();
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

size_t nodeHash::operator()(const node& n1) const {
    return std::hash<long>()(n1.pos);
}

bool nodeEqual::operator()(const node& n1, const node& n2) const {
    return n1.pos == n2.pos;
}

idxValCmp::idxValCmp(std::vector<node> *d) {
    this->storePtr = d;
}

bool idxValCmp::operator()(long idx1, long idx2) {
    return (*this->storePtr)[idx1].val >= (*this->storePtr)[idx2].val;
}