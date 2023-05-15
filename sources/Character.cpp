//
// Created by ofir on 5/1/23.
//

#include "Character.hpp"
#include <iostream>
using namespace ariel;
using namespace std;



ostream &ariel::operator<<(ostream &ostream, const Character &character) {
    return ostream;
}


string Character::getName() {
    return this->_name;
}

Point Character::getLocation() {
    return this->_location;
}

bool Character::isAlive() {
    return false;
}

double Character::distance(Character* other) {
    return 1;
}

void Character::hit(int num) {

}

int Character::getHitPoints() const {
    return this->_hitPoints;
}








