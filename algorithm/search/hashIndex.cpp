#include "index.h"

using namespace std;

hashIndex::hashIndex(string fileName) : searchIndex(fileName) {}

hashIndex::~hashIndex() {
    for (unordered_map<string, unordered_set<node, nodeHash, nodeEqual>* >::iterator i = this->data.begin();
        i != this->data.end(); i++) {
        delete i->second;
    }
}

struct ResVal {
    unordered_set<node, nodeHash, nodeEqual> *list;
    long size;
};

struct ResSizeCmp {
    bool operator()(const ResVal& n1, const ResVal& n2) {
        return n1.size < n2.size;
    }
} resSizeCmp;

void hashIndex::lookup(vector<string> input) {
    int len = input.size();
    vector<ResVal> results(len);
    int j = 0;

    for (vector<string>::iterator i = input.begin(); i != input.end(); i++) {
        unordered_map<string, unordered_set<node, nodeHash, nodeEqual>* >::iterator list =
            this->data.find(*i);

        if (list == this->data.end()) {
            return;
        } else {
            results[j].list = list->second;
            results[j].size = list->second->size();
            j++;
        }
    }

    sort(results.begin(), results.end(), resSizeCmp);

    unordered_set<node, nodeHash, nodeEqual> res1 = *(results[0].list);
    unordered_set<node, nodeHash, nodeEqual> res2(res1.size());
    unordered_set<node, nodeHash, nodeEqual> *src, *tgt, *tmp;
    src = &res1;
    tgt = &res2;

    for (vector<ResVal>::iterator i = results.begin() + 1; i != results.end(); i++) {
        for (unordered_set<node, nodeHash, nodeEqual>::iterator j = src.begin(); j != src.end(); j++) {
            
        }
    }


}

void hashIndex::insert(const string& word, const node& n) {
    unordered_map<string, unordered_set<node, nodeHash, nodeEqual>* >::iterator list =
        this->data.find(word);

    if (list == this->data.end()) {
        unordered_set<node, nodeHash, nodeEqual> *t = new unordered_set<node, nodeHash, nodeEqual>();
        t->insert(n);
        this->data[word] = t;
    } else {
        list->second->insert(n);
    }
}

