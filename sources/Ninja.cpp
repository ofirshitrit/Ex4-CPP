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
    if (enemy == this) throw invalid_argument("the enemy cant be itself");
    this->_location = Point::moveTowards(this->_location,enemy->getLocation(),this->_speed);
}

void Ninja::slash(Character* enemy) {
    if (enemy == this) throw runtime_error("character cant heart itself");
    if (!enemy->isAlive()) throw runtime_error("cant slash a dead enemy");
    if (!this->isAlive()) throw runtime_error("dead ninja cant slash");
    double distFromEnemy = this->_location.distance(enemy->getLocation());
    if (this->isAlive() && (distFromEnemy < 1)) {
        enemy->hit(40);
    }
}

int Ninja::getSpeed() const {
    return this->_speed;
}




void Ninja::attack(Character* victim)
{
    if ( victim->isAlive()) {
        if(this->getLocation().distance(victim->getLocation()) < 1) { //the distance less than one meter
//            cout << ninja->getName() << " slash " << victim->getName() << endl;
            this->slash(victim);
        }
        else {
//            cout << ninja->getName() << " is in: " ;
//            ninja->getLocation().print();
//            cout << ninja->getName() << " distance " << ninja->getLocation().distance(victim->getLocation()) << " "  << victim->getName() << endl;
//            cout << ninja->getName() << " move " << endl;
            this->move(victim);
//            cout << ninja->getName() << " is now at: " ;
//            ninja->getLocation().print();
        }
    }
}

