//
// Created by ofir on 5/1/23.
//

#include "Cowboy.hpp"

using namespace ariel;
using namespace std;


string Cowboy::print() {
    string s = "C \n";
    s += Character::print();
    return s;
}

void Cowboy::shoot(Character *enemy) {
    if (this->hasboolets() && this->isAlive()) {
        enemy->hit(10);
        this->numOfBalls--;
    }
}

bool Cowboy::hasboolets() {

    return (this->numOfBalls > 0);
}

void Cowboy::reload() {
    this->numOfBalls += 6;
}

int Cowboy::getNumOfBalls() const {
    return this->numOfBalls;
}
