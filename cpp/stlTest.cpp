#include <iostream>
#include <string.h>
#include <string>
#include <vector>

using namespace std;

template<class T>
class myVector {
public:
    void push();

};

class myString {
private:
    char *d;
    int len;
public:
    myString();
    myString(const myString&);
    myString(const char *);
    char* c_str() const;
    char* data() const;
    int size() const;
    int length() const;
    int find(char);
    int find(const myString&);
    ~myString();
    char& operator[](int);
    bool operator==(myString);
    myString& operator+=(const myString&);
    myString& operator=(const myString&);
    friend myString operator+(const myString&, const myString&);
    friend ostream& operator<<(ostream&, const myString&);
    friend istream& operator>>(istream&, const myString&);
};

myString::myString() {
   this->d = new char[1];
   this->len = 0;
   this->d[0] = '\0';
}

myString::myString(const char *s) {
    int n;
    n = strlen(s);    
    this->len = n;
    this->d = new char[this->len + 1];
    strcpy(this->d, s);
}

int myString::find(char c) {
    char *p = strchr(this->d, c);

    if (p) {
        return p - this->d;
    }
}

int myString::find(const myString& s) {
    char *p = strstr(this->d, s.c_str());

    if (p) {
        return p - this->d;
    }
}

int myString::size() const {
    return this->len;
}

int myString::length() const {
    return this->len;
}

char* myString::c_str() const {
    return this->d;
}

char* myString::data() const {
    return this->d;
}

char& myString::operator[](int idx) {
    return this->d[idx];
}

myString::myString(const myString& s) {
    this->len = s.size();
    this->d = new char[this->len + 1];
    strcpy(this->d, s.c_str());
}

myString& myString::operator=(const myString& s) {
    delete[] this->d;
    this->len = s.size();
    this->d = new char[this->len + 1];
    strcpy(this->d, s.c_str());
    return *this;
}

myString::~myString() {
    delete[] this->d;
}

ostream& operator<<(ostream& out, const myString& s) {
    out << s.d;
}

void myStringTest() {
    string c;
    cout << "size of empty string: " << sizeof(c) << endl;
    string d = "abcd";
    cout << "size of 4 chars string: " << sizeof(d) << endl;
    string ss = "ccd";
    ss += d;
    cout << ss << endl;

    myString m("asdf");

    cout << m << endl;

    myString m2(m);
    cout << m2 << endl;

    myString m3;

    m3 = m2;
    cout << m3 << endl;
    
    cout << m3[2] << endl;

    cout << m3.find('s') << endl;

    cout << m3.find("sd") << endl;
}

void vectorTest() {
    int n = 10000;

    vector<myString> v1, v2;

    for (int k = 0; k != n; k++) {
        vector<myString>::size_type cap = v1.capacity();
        v1.push_back(myString("asdf"));
        if (v1.capacity() != cap) {
            cout << "k: " << k << ", new capacity: " << v1.capacity() << endl;
        }
    }
}


int main(int argc, char **argv) {
    //myStringTest();
    vectorTest();
    return 0;
}
