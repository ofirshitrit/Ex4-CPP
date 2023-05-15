//
// Created by ofir on 5/1/23.
//

#include "Cowboy.hpp"

using namespace ariel;
using namespace std;


string Cowboy::print() {
    return "non";
}

void Cowboy::shoot(const Character *enemy) {

}

bool Cowboy::hasboolets() {
    return false;
}

void Cowboy::reload() {

}

ostream &ariel::operator<<(ostream &ostream, const Cowboy &cowboy) {
    return ostream;
}

int Cowboy::getNumOfBalls() const {
    return this->numOfBalls;
}
