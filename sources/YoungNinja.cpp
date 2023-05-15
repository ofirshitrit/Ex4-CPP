//
// Created by ofir on 5/1/23.
//

#include "YoungNinja.hpp"
#include <iostream>

using namespace ariel;
using namespace std;

ostream &ariel::operator<<(ostream &ostream, const YoungNinja &youngNinja) {
    return ostream;
}

string YoungNinja::print() {
    return "non";
}
