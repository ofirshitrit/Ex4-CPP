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
    if (enemy == this) throw runtime_error("character cant heart itself");
    if (this->hasboolets() && this->isAlive()) {
        enemy->hit(10);
        this->numOfBalls--;
    }
}

bool Cowboy::hasboolets() {

    return (this->numOfBalls > 0);
}

void Cowboy::reload() {
    if (!isAlive()) throw runtime_error("dead cowboy can reload");
    this->numOfBalls += 6;
}

int Cowboy::getNumOfBalls() const {
    return this->numOfBalls;
}
