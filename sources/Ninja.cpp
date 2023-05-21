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

void Ninja::move(Character* enemy) {
    if (enemy == this) throw invalid_argument("The enemy cant be itself");
    this->getLocation() = Point::moveTowards(this->getLocation(),enemy->getLocation(),this->_speed);
}

void Ninja::slash(Character* enemy) {
    if (this == enemy) throw runtime_error("Character cant heart itself");
    if (!enemy->isAlive()) throw runtime_error("Cant slash a dead enemy");
    if (!this->isAlive()) throw runtime_error("Dead ninja cant slash");
    double distFromEnemy = this->getLocation().distance(enemy->getLocation());
    if (this->isAlive() && (distFromEnemy < 1)) {
        enemy->hit(40);
    }
}

int Ninja::getSpeed() const {
    return this->_speed;
}


void Ninja::attack(Character *victim) {
    double distance = this->getLocation().distance(victim->getLocation()); //the distance less than one meter
    if (victim->isAlive() && this->isAlive()) {
        if ((distance < 1) && this->isAlive() ) {
            this->slash(victim);
        } else {
            this->move(victim);
        }
    }
}

