#include <iostream>
#include <memory>
#include <list>
#include "ccTest.h"
#include "sharedPtr.h"

using namespace std;

void sharedPtrTest::test() {
    list<shared_ptr<sharp>> array;
    array.push_back(shared_ptr<rectangle>(new rectangle()));
    array.push_back(shared_ptr<triangle>(new triangle()));
    array.push_back(shared_ptr<tableBridgeClass>(new tableBridgeClass()));

    shared_ptr<table> t_p = shared_ptr<table>(new table());
    array.push_back(shared_ptr<tableBridgeObject>(new tableBridgeObject(t_p)));

    for (list<shared_ptr<sharp>>::iterator i = array.begin(); i != array.end(); i++) {
        (*i)->draw();
    }
    
    shared_ptr<tableBridgeClass> a_p = shared_ptr<tableBridgeClass>(new tableBridgeClass());
}
