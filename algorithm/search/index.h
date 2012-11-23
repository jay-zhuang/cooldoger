#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <sstream>
#include <fstream>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <set>

class node {
public:
    long pos;
    int val;
};

struct posCmp {
    bool operator()(const node& n1, const node& n2);
};

struct valCmp {
    bool operator()(const node& n1, const node& n2);
};

struct nodeHash {
    std::size_t operator()(const node& n1) const;
};

struct nodeEqual {
    bool operator()(const node& n1, const node& n2) const;
};


class searchIndex {
private:
    virtual void lookup(std::vector<std::string> input) = 0;
    virtual void insert(const std::string& word, long idx) = 0;

protected:
    std::vector<node> store;    
    std::string fileName;
    std::ifstream dataFile;
    void printNode(const node& nd, int n);
    void printResult(std::set<node, valCmp> res);
    void printResult(std::vector<long> res);
    void buildSearchIndex();

public:
    searchIndex(std::string fileName);
    virtual void buildIndex();
    void search(std::string line);
    virtual ~searchIndex();
};

class invertedIndex : public searchIndex {
private:
    std::unordered_map<std::string, std::vector<long>* > data;
    virtual void lookup(std::vector<std::string> input);
    virtual void insert(const std::string& word, long idx);
public:
    invertedIndex(std::string fileName);
    virtual ~invertedIndex();
};

class hashIndex : public searchIndex {
private:
    std::unordered_map<std::string, std::unordered_set<node, nodeHash, nodeEqual>* > data;
    virtual void lookup(std::vector<std::string> input);
    virtual void insert(const std::string& word, long idx);

public:
    hashIndex(std::string fileName);
    virtual ~hashIndex();
};


struct idxValCmp {
private:
    std::vector<node> *storePtr;
public:
    idxValCmp(std::vector<node> *d);
    bool operator()(long idx1, long idx2);
};
