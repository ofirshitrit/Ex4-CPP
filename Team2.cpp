//
// Created by ofir on 5/11/23.
//

#include "Team2.hpp"
#include "Team.hpp"
using namespace ariel;
using namespace std;


//
//void Team2::attack(Team *other) {
//    if (other == nullptr) throw invalid_argument("cant attack nullptr");
//
//}


void Team2::print() {
    cout << "TEAM 2" << endl;
}

void Team2::add(Character *character) {
    if (this->fighters.size() == 10) throw runtime_error("The team cant be over 10 fighters");
    if (character->isBelongToTeam()) {
        this->fighters.pop_back(); //remove the character
        throw runtime_error("This character belong to another team");
    }
    character->setBelongToTeam(true);
    this->getFighters().push_back(character);
}


