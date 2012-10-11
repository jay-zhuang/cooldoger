#include <iostream>
#include <string>
#include <list>
#include "composite.h"

using namespace std;

song::song(string name, int year) {
    this->songName = name;
    this->releaseYear = year;
}

string song::getSongName() {
    return this->songName;
}

int song::getReleaseYear() {
    return this->releaseYear;
}

void song::displaySongInfor() {
    cout << "Song: " << this->songName << ", " << this->releaseYear << endl;
}

void songGroup::add(songComponent& s) {
}

void songGroup::remove(songComponent& s) {
}

int songComponent::getReleaseYear() {
    return 1980;
}

string songComponent::getSongName() {
    return "NULL";
}

void songGroup::displaySongInfor() {
    list<songComponent*>::iterator i;
    cout << "Group: " << this->groupName << ", " << this->groupDescription << endl;
    for (i = this->child.begin(); i != child.end(); i++) {
        (*i)->displaySongInfor();
    }
}

songGroup::songGroup(string name, string desp) : groupName(name), groupDescription(desp) {
}

void compositeTest::test() {
    songGroup a;
}
