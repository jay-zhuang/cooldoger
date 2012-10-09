#include <iostream>
#include <string>

#include "adapter.h"

using namespace std;

void adapterTest::game(enemyAttacker* a) {
    a->assignDriver("Jay");
    a->driveForward();
    a->driveForward();
    a->fireWeapon();
}

void adapterTest::test() {
    enemyTank *t1 = new enemyTank();
    game(t1);
}

void enemyTank::fireWeapon() {
    cout << "Tank fire weapon" << endl;
}

void enemyTank::driveForward() {
    cout << "Tank drive forward" << endl;
}

void enemyTank::assignDriver(string name) {
    cout << name << " is driving Tank" << endl;
}
