#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <sstream>
#include <fstream>
#include <unordered_map>
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

class searchIndex {
private:
    virtual void lookup(std::vector<std::string> input) = 0;
protected:
    std::string fileName;
    std::ifstream dataFile;
    void printResult(std::set<node, valCmp> res);

public:
    searchIndex(std::string fileName);
    virtual void buildIndex() = 0;
    void search(std::string line);
    virtual ~searchIndex();
};

class invertedIndex : public searchIndex {
private:
    std::unordered_map<std::string, std::set<node, posCmp>* > data;
    virtual void lookup(std::vector<std::string> input);
    void insert(const std::string& word, const node& n);
public:
    invertedIndex(std::string fileName);
    virtual void buildIndex();   
    virtual ~invertedIndex();
};

