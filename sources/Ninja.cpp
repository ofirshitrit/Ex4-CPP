//
// Created by ofir on 5/1/23.
//

#include "Ninja.hpp"

using namespace std;
using namespace ariel;



ostream &ariel::operator<<(ostream &ostream, const Ninja &ninja) {
    return ostream;
}

string Ninja::print() {
   return "non";
}

void Ninja::move(const Character* enemy) {

}

void Ninja::slash(const Character* enemy) {

}

int Ninja::getSpeed() const {
    return this->_speed;
}


