#include <iostream>
#include <vector>
#include "search.h"

using namespace std;

class index {
private:
    string fileName = "docs.corpus"
public:
    index();
    buildIndex();
    void lookup(vector<string> input, vector<string>& rets);
};


int main(int argc, char** argv) {
    index();

    return 0;
}