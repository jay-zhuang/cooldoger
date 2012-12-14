
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
