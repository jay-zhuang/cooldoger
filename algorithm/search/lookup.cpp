#include "index.h"
#include <string.h>

using namespace std;

searchIndex *algorithmBuilder(int argc, char** argv) {
    searchIndex *ret = NULL;
    string fileName = "docs.corpus";

    if (argc == 3) fileName = argv[2];

    if (argc == 1) {
        ret = new invertedIndex(fileName);
    } else {
        if (strcmp(argv[1], "inverted") == 0) {
            ret = new invertedIndex(fileName);
        } else if (strcmp(argv[1], "hash") == 0) {
            cout << "hashing" << endl;
            ret = new invertedIndex(fileName);
        }
    }

    return ret;
}

int main(int argc, char** argv) {
    string line;
    string fileName;

    searchIndex *i;
    i = algorithmBuilder(argc, argv);

    if (i == NULL) return 1;

    i->buildIndex();

    while (getline(cin, line)) {
        i->search(line);
    }

    delete i;
    return 0;
}