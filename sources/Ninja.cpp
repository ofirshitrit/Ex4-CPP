//
// Created by ofir on 5/1/23.
//

#include "Ninja.hpp"

using namespace std;
using namespace ariel;


string Ninja::print() {
    string s = "N \n";
    s += Character::print();
   return s;
}

void Ninja::move(const Character* enemy) { //TODO
    double x = this->getLocation().getXCoordinate();
    x =  x + this->_speed;
}

void Ninja::slash(Character* enemy) {
    double distFromEnemy = this->_location.distance(enemy->getLocation());
    if (this->isAlive() && (distFromEnemy < 1)) {
        enemy->hit(40);
    }
}

int Ninja::getSpeed() const {
    return this->_speed;
}


