#include <iostream>
#include <vector>
#include <memory>
#include "ccTest.h"

using namespace std;

void sharp::draw() {
    cout << "sharp::draw()" << endl;
    this->doDraw();
}

rectangle::rectangle() {
    cout << "rectangle constructor" << endl;
}

rectangle::~rectangle() {
    cout << "rectangle destructor" << endl;
}

void rectangle::doDraw() {
    cout << "rectangle::doDraw()" << endl;
}

triangle::triangle() {
    cout << "triangle constructor" << endl;
}

triangle::~triangle() {
    cout << "triangle destructor" << endl;
}

void triangle::doDraw() {
    cout << "triangle::doDraw()" << endl;
}

void ccTest::bridgeTest() {
    vector<sharp *>array;

    array.push_back(new rectangle());
    array.push_back(new triangle());
    array.push_back(new tableBridgeClass());
    shared_ptr<table> t_p = shared_ptr<table>(new table());
    array.push_back(new tableBridgeObject(t_p));

    for(vector<sharp *>::iterator i = array.begin(); i != array.end(); i++) {
        (*i)->draw();
    }
}

void table::tableDraw() {
    cout << "table::tableDraw()" << endl;
}

table::table() {
    cout << "table constructor" << endl;
}

table::~table() {
    cout << "table destructor" << endl;
}

void tableBridgeClass::doDraw() {
    this->tableDraw();
}

tableBridgeClass::tableBridgeClass() {
    cout << "tableBridgeClass constructor" << endl;
}

tableBridgeClass::~tableBridgeClass() {
    cout << "tableBridgeClass destructor" << endl;
}

tableBridgeObject::tableBridgeObject(shared_ptr<table> t_p) {
    cout << "tableBridgeObjct constructor" << endl;
    this->t_p = t_p;
}

tableBridgeObject::~tableBridgeObject() {
    cout << "tableBridgeObject destructor" << endl;
}

void tableBridgeObject::doDraw() {
    this->t_p->tableDraw();
}
