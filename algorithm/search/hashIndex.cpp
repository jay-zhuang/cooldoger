#include "index.h"
#include <pthread.h>

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

struct thData {
    pthread_spinlock_t itSpin;
    pthread_spinlock_t resSpin;
    unordered_set<long>::iterator *itPtr;
    unordered_set<long>::iterator end;
    vector<ResVal> *resultsPtr;
    vector<long> *resPtr;
};

void *merge(void *ptr) {
    thData *d = (thData *)ptr;
    long val = 0;
    while (true) {
        pthread_spin_lock(&(d->itSpin));
        if (*(d->itPtr) == d->end) {
            pthread_spin_unlock(&(d->itSpin));
            return NULL;
        }
        val = *(*(d->itPtr));
        (*(d->itPtr))++;
        pthread_spin_unlock(&(d->itSpin));

        bool found = true;
        for (vector<ResVal>::iterator it = d->resultsPtr->begin() + 1;
            it != d->resultsPtr->end(); it++) {
            if (it->list->find(val) == it->list->end()) {
                found = false;
                break;
            }
        }

        if (found) {
            pthread_spin_lock(&(d->resSpin));
            d->resPtr->push_back(val);
            pthread_spin_unlock(&(d->resSpin));
        }
    }
    return NULL;
}

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

    if (len == 1) {
        vector<long> res(results[0].list->begin(), results[0].list->end());
        this->printResult(res);
        return;
    }

    vector<long> resl;

    int thNum = this->getCPUCoreNum();
    vector<pthread_t> ths(thNum);
    thData tData;

    pthread_spin_init(&(tData.itSpin), 0);
    pthread_spin_init(&(tData.resSpin), 0);
    unordered_set<long>::iterator it = results[0].list->begin();
    tData.itPtr = &it;
    tData.end = results[0].list->end();
    tData.resultsPtr = &results;
    tData.resPtr = &resl;

    for (int i = 0; i < thNum; i++) {
        pthread_create(&(ths[i]), NULL, merge, &tData);
    }

    for (int i = 0; i < thNum; i++) {
        pthread_join(ths[i], NULL);
    }

    pthread_spin_destroy(&(tData.itSpin));
    pthread_spin_destroy(&(tData.resSpin));
    // bool found = false;

    // for (unordered_set<long>::iterator it = results[0].list->begin();
    //     it != results[0].list->end(); it++) {
    //     found = true;
    //     for (vector<ResVal>::iterator resIt = results.begin() + 1; resIt != results.end(); resIt++) {
    //         if (resIt->list->find(*it) == resIt->list->end()) {
    //             found = false;
    //             break;
    //         }
    //     }

    //     if (found) {
    //         res.push_back(*it);
    //     }
    // }

    this->printResult(resl);
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

