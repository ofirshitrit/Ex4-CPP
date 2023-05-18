//
// Created by ofir on 5/11/23.
//

#include "SmartTeam.hpp"
#include "Team.hpp"
using namespace ariel;
using namespace std;



void SmartTeam::add(Character *character) {
    if (this->fighters.size() == 10) throw runtime_error("The team cant be over 10 fighters");
    if (character->isBelongToTeam()) {
        this->fighters.pop_back(); //remove the character
        throw runtime_error("This character belong to another team");
    }
    character->setBelongToTeam(true);
    this->getFighters().push_back(character);
}

void SmartTeam::print() {
    cout << "SMART TEAM" << endl;
}


