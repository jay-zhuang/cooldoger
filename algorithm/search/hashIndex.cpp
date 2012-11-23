#include "index.h"

using namespace std;

hashIndex::hashIndex(string fileName) : searchIndex(fileName) {}

hashIndex::~hashIndex() {
    for (unordered_map<string, unordered_set<long>* >::iterator i = this->data.begin();
        i != this->data.end(); i++) {
        delete i->second;
    }
}

struct ResVal {
    unordered_set<long> *list;
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
        unordered_map<string, unordered_set<long>* >::iterator list =
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

    vector<long> res;
    bool found = false;

    for (unordered_set<long>::iterator it = results[0].list->begin();
        it != results[0].list->end(); it++) {
        found = true;
        for (vector<ResVal>::iterator resIt = results.begin() + 1; resIt != results.end(); resIt++) {
            if (resIt->list->find(*it) == resIt->list->end()) {
                found = false;
                break;
            }
        }

        if (found) {
            res.push_back(*it);
        }
    }

    this->printResult(res);
}

void hashIndex::insert(const string& word, long idx) {
    unordered_map<string, unordered_set<long>* >::iterator list =
        this->data.find(word);

    if (list == this->data.end()) {
        unordered_set<long> *t = new unordered_set<long>();
        t->insert(idx);
        this->data[word] = t;
    } else {
        list->second->insert(idx);
    }
}

