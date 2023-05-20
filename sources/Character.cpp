//
// Created by ofir on 5/1/23.
//

#include "Character.hpp"
#include <iostream>
using namespace ariel;
using namespace std;



string Character::getName() {
    return this->_name;
}

Point& Character::getLocation() {
    return this->_location;
}

bool Character::isAlive() {
    return (_hitPoints > 0);
}

double Character::distance(Character* other) {
    return this->getLocation().distance(other->getLocation());
}

void Character::hit(int num) {
    if ( num < 0) throw invalid_argument("The number of hits cant be negative");
    this->_hitPoints -= num;
}

int Character::getHitPoints() const {
    return this->_hitPoints;
}

string Character::print() {
    string s = "name: " + _name + "\n";
    s += "hit points: " + to_string(_hitPoints) + "\n";
    s += "location: (" + to_string(_location.getXCoordinate()) + ", " + to_string(_location.getYCoordinate()) + ")\n";
    return s;
}

bool Character::isBelongToTeam() const {
    return belongToTeam;
}

void Character::setBelongToTeam(bool belongToTeam) {
    Character::belongToTeam = belongToTeam;
}








