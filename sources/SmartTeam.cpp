//
// Created by ofir on 5/11/23.
//

#include "SmartTeam.hpp"
#include "Team.hpp"
using namespace ariel;
using namespace std;

void SmartTeam::attack(Team *other) {
    if (other == nullptr) throw invalid_argument("cant attack nullptr");

}

void SmartTeam::print() {

}

void SmartTeam::add(Character *character) {
    if (this->fighters.size() == 10) throw runtime_error("The team cant be over 10 fighters");
    if (character->getTeam() != SMART_TEAM) throw runtime_error("This character is in other team");
    character->setTeam(SMART_TEAM);
    this->fighters.push_back(character);
}
