//
// Created by ofir on 4/30/23.
//
#include <iostream>
#include "Team.hpp"

#include <cfloat>


using namespace ariel;
using namespace std;


Team::Team(Character *leader)  : _leader(leader) , fighters()
{
    if (leader->isBelongToTeam()) {
        throw runtime_error("This captain belong to another team");
    }
    fighters.push_back(leader);
    leader->setBelongToTeam(true);
}

void Team::attackByFighterType(Character* fighter, Character* victim, Team* enemies) {
    if (fighter->isAlive()) {
        fighter->attack(victim);
        if (!victim->isAlive()) {
            if (enemies->stillAlive() == 0) {
                return;
            } else {
                victim = chooseVictim(enemies);
            }
        }
    }
}

void Team::attackByCowboys(Team* enemies, Character* victim) {
    for (Character* fighter : this->getFighters()) {
        if (Cowboy* cowboy = dynamic_cast<Cowboy*>(fighter)) {
            if (cowboy->isAlive()) {
                cowboy->attack(victim);
                if (!victim->isAlive()) {
                    if (enemies->stillAlive() == 0) {
                        return;
                    } else {
                        victim = chooseVictim(enemies);
                    }
                }
            }
        }
    }
}

void Team::attackByNinjas(Team* enemies, Character* victim) {
    for (Character* fighter : this->getFighters()) {
        if (Ninja* ninja = dynamic_cast<Ninja*>(fighter)) {
            if (ninja->isAlive()) {
                ninja->attack(victim);
                if (!victim->isAlive()) {
                    if (enemies->stillAlive() == 0) {
                        return;
                    } else {
                        victim = chooseVictim(enemies);
                    }
                }
            }
        }
    }
}

void Team::attack(Team* enemies) {
    if (this->stillAlive() == 0) {
        throw runtime_error("The team is dead!");
    }
    if (enemies == nullptr) {
        throw invalid_argument("Can't attack nullptr");
    }
    if (enemies->stillAlive() == 0) {
        throw runtime_error("Can't attack dead team!");
    }

    if (!this->getLeader()->isAlive()) {
        this->_leader = getNewLeader();
    }

    Character* victim = chooseVictim(enemies);

    attackByCowboys(enemies, victim);
    attackByNinjas(enemies, victim);
}

Character *Team::getNewLeader() {
    Character* newLeader = getMember(this);
    return newLeader;
}


Character *Team::chooseVictim(Team *enemies) {
    if (enemies == this) throw runtime_error("Team cant choose a victim from itself ");
    Character* victim = getMember(enemies);
    return victim;
}

Character* Team::getMember(Team* team){
    Character* member = nullptr;
    double minDistance = DBL_MAX;
    for( unsigned int i = 0; i < team->getFighters().size(); i++){
        if (team->getFighters()[i]->isAlive()){ //only if the fighter is alive it could be chosen
            double currDistance = team->getFighters()[i]->getLocation().distance(this->_leader->getLocation());
            if (currDistance < minDistance){
                minDistance = currDistance;
                member = team->getFighters()[i];
            }
        }
    }
    return member;
}



int Team::stillAlive() {
    int numbersOAlive = 0;
    for (unsigned int i = 0; i < this->getFighters().size(); i++) {
        if(this->getFighters()[i]->isAlive()) {
            numbersOAlive++;
        }
    }
    return numbersOAlive;
}

void Team::print() {
    for (Character* fighter : this->getFighters()) {
        if (Cowboy* cowboy = dynamic_cast<Cowboy*>(fighter)){
            cout << cowboy->print() << endl;
        }
    }
    for (Character* fighter : this->getFighters()) {
        if (Ninja* ninja = dynamic_cast<Ninja*>(fighter)){
            cout << ninja->print() << endl;
        }
    }
}

void Team::add( Character* character) {
    if (this->fighters.size() == 10) throw runtime_error("The team cant be over 10 fighters");
    if (character->isBelongToTeam()) {
        this->fighters.pop_back(); //remove the character
        throw runtime_error("This character belong to another team");
    }
    character->setBelongToTeam(true);
    this->getFighters().push_back(character);
//    addSorted(character);
}

Character *Team::getLeader() const {
    return _leader;
}

std::vector<Character *> &Team::getFighters(){
    return fighters;
}

Team::~Team() { //TODO
//    for (Character* fighter : fighters) {
//        delete fighter;
//    }
}