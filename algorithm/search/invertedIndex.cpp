
#include "index.h"

using namespace std;

invertedIndex::invertedIndex(string fileName) : searchIndex(fileName) {

}

invertedIndex::~invertedIndex() {
    for (unordered_map<std::string, std::set<node, posCmp>* >::iterator i = this->data.begin();
        i != this->data.end(); i++) {
        delete i->second;
    }
}

void invertedIndex::buildIndex() {
    if (!this->dataFile) throw "File not found.";

    string line;
    string field;
    string word;

    node n;

    n.pos = 0;
    n.val = 0;

    int i = 0;
    long nextPos = 0;
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
                this->insert(word, n);
            }
        }

        n.pos = nextPos;
    }

    this->dataFile.clear();
}

struct ResIt{
    set<node, posCmp>::iterator it;
    set<node, posCmp>::iterator end;
};

void invertedIndex::lookup(vector<string> input) {
    int len = input.size();
    vector<ResIt> results(len);
    int j = 0;


    for (vector<string>::iterator i = input.begin(); i != input.end(); i++) {
        unordered_map<string, set<node, posCmp>* >::iterator list =
            this->data.find(*i);

        if (list == this->data.end()) {
            return;
        } else {
            results[j].it = list->second->begin();
            results[j].end = list->second->end();
            j++;
        }
    }

    set<node, valCmp> res;
    long max = 0;
    int cnt = 0;

    for (vector<ResIt>::iterator i = results.begin();;i++) {
        if (i == results.end()) i = results.begin();

        while (i->it != i->end && i->it->pos < max) (i->it)++;

        if (i->it == i->end) {
            break;
        } else if (i->it->pos > max) {
            max = i->it->pos;
            cnt = 1;
        } else if (i->it->pos == max) {
            cnt++;
        }

        if (cnt == len) { // found
            res.insert(*(i->it));
        }
        (i->it)++;
    }

    this->printResult(res);
}

void invertedIndex::insert(const string& word, const node& n) {
    unordered_map<string, set<node, posCmp>* >::iterator list =
        this->data.find(word);

    if (list == this->data.end()) {
        set<node, posCmp> *t = new set<node, posCmp>();
        t->insert(n);
        this->data[word] = t;
    } else {
        list->second->insert(n);
    }

}
