
#include "index.h"

using namespace std;

invertedIndex::invertedIndex(string fileName) : searchIndex(fileName) {

}

invertedIndex::~invertedIndex() {
    for (unordered_map<string, vector<long>* >::iterator i = this->data.begin();
        i != this->data.end(); i++) {
        delete i->second;
    }
}

struct ResIt{
    vector<long>::iterator it;
    vector<long>::iterator end;
};

void invertedIndex::lookup(vector<string> input) {
    int len = input.size();
    vector<ResIt> results(len);
    int j = 0;


    for (vector<string>::iterator i = input.begin(); i != input.end(); i++) {
        unordered_map<string, vector<long>* >::iterator list =
            this->data.find(*i);

        if (list == this->data.end()) {
            return;
        } else {
            results[j].it = list->second->begin();
            results[j].end = list->second->end();
            j++;
        }
    }

    vector<long> res;
    long max = 0;
    int cnt = 0;

    for (vector<ResIt>::iterator i = results.begin();;i++) {
        if (i == results.end()) i = results.begin();

        while (i->it != i->end && this->store[*(i->it)].pos < max) (i->it)++;

        if (i->it == i->end) {
            break;
        } else if (this->store[*(i->it)].pos > max) {
            max = this->store[*(i->it)].pos;
            cnt = 1;
        } else if (this->store[*(i->it)].pos == max) {
            cnt++;
        }

        if (cnt == len) { // found
            res.push_back(*(i->it));
        }
        (i->it)++;
    }

    this->printResult(res);
}

void invertedIndex::insert(const string& word, long idx) {
    unordered_map<string, vector<long>*>::iterator list =
        this->data.find(word);

    if (list == this->data.end()) {
        vector<long> *t = new vector<long>();
        t->push_back(idx);
        this->data[word] = t;
    } else {
        list->second->push_back(idx);
    }

}
