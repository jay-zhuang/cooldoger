
#include "index.h"

using namespace std;

invertedIndex::invertedIndex(string fileName) : searchIndex(fileName) {
    cout << "building inverted index: " << fileName << endl;
}

invertedIndex::~invertedIndex() {
    cout << "destorying inverted index" << endl;
}

void invertedIndex::buildIndex() {
    cout << "building index ........" << this->fileName << endl;
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

        //cout << pos << "--" << val << "->" << ": " << str << endl;

        n.pos = nextPos;
    }

    this->dataFile.clear();
    //this->dataFile.seekg(113, ios::beg);
}

void invertedIndex::lookup(vector<string> input) {
    for (vector<string>::iterator i = input.begin(); i != input.end(); i++) {
        cout << "lookup " << *i << endl;
        unordered_map<string, set<node, posCmp>* >::iterator list =
            this->data.find(*i);

        if (list == this->data.end()) {
            cout << "not found" << endl;
        } else {
            for (set<node, posCmp>::iterator i = list->second->begin(); i != list->second->end(); i++) {
                cout << "  " << (*i).val << endl;
            }
        }
    }
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
