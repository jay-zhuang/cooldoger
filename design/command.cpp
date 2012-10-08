#include <iostream>
#include "command.h"

using namespace std;

void commandTest::test() {
    tv *t = new tv();
    turnOn *c1 = new turnOn(t);
    c1->execute();

    command *c = new simpleCommand<tv>(t,&tv::off);
    c->execute();
    return;
}

void tv::on() {
    cout << "Turn TV on" << endl;
    return;
}

void tv::off() {
    cout << "Turn TV off" << endl;
    return;
}

void tv::volumeUp() {
    cout << "Trun TV volume up: " << ++(this->volume);
    return;
}

void tv::volumeDown() {
    cout << "Trun TV volume down: " << --(this->volume);
    return;
}

turnOn::turnOn(electronicDevice* d) {
    this->device = d;
}

void turnOn::execute() {
    this->device->on();
    return;
}

template<class Receiver>
void simpleCommand<Receiver>::execute() {
    (_receiver->*_action)();
}
