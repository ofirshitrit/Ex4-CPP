//
// Created by ofir on 4/30/23.
//
#include <iostream>
#include "Team.hpp"


using namespace ariel;
using namespace std;




void Team::attack(Team* other) {
    if (other == nullptr) throw invalid_argument("cant attack nullptr");
    if (!other->getLeader()->isAlive()) this->_leader = getNewLeader();
    while (!other->getFighters().empty()) {
        Character* victim = getVictim(other);
        while (victim->isAlive()) {
            attackVictim(victim);
        }
        removeVictim(other,victim);
    }
}

int Team::stillAlive() {
    return this->fighters.size();
}

void Team::print() {
    for(unsigned int i = 0; i < this->fighters.size(); i++)
    {
       this->fighters[i]->print();
    }
}

void Team::add( Character* character) {
    if (this->fighters.size() == 10) throw runtime_error("The team cant be over 10 fighters");
    if (character->isBelongToTeam()) {
        this->fighters.pop_back(); //remove the character
        throw runtime_error("this character belong to other team");
    }
    character->setBelongToTeam(true);
    this->fighters.push_back(character);
}

Character *Team::getLeader() const {
    return _leader;
}

 std::vector<Character *> &Team::getFighters(){
    return fighters;
}

Team::Team(Character *leader)  : _leader(leader) , fighters()
{
    if (leader->isBelongToTeam()) {
        this->fighters.pop_back(); //remove the leader
        throw runtime_error("this captain belong to other team");
    }
    fighters.push_back(leader);
    leader->setBelongToTeam(true);
}

Character *Team::getNewLeader() {
    Character* newLeader = nullptr;
    double minDistance = 100000000;
    for( unsigned int i = 0; i < this->fighters.size(); i++){
        if (fighters[i]->isAlive()){
            double currDistasnce = fighters[i]->getLocation().distance(this->_leader->getLocation());
            if (currDistasnce < minDistance){
                newLeader = fighters[i];
            }
        }
    }
    return newLeader;
}

Character *Team::getVictim(Team *enemies) {
    Character* victim = nullptr;
    double minDistance = 100000000;
    for( unsigned int i = 0; i < enemies->getFighters().size(); i++){
        if (enemies->getFighters()[i]->isAlive()){
            double currDistasnce = enemies->getFighters()[i]->getLocation().distance(this->_leader->getLocation());
            if (currDistasnce < minDistance){
                victim = enemies->getFighters()[i];
            }
        }
    }
    return victim;
}

void Team::removeVictim(Team* enemies, Character* victim) {
    std::vector<Character*>& fighters = enemies->getFighters();
    for (auto it = fighters.begin(); it != fighters.end(); ++it) {
        if (*it == victim) {
            fighters.erase(it);  // Remove the victim using the iterator
            break;  // Break the loop after removing the element
        }
    }
}

void Team::attackVictim(Character *victim) {
    for (unsigned int i = 0; i < this->getFighters().size(); i++) {
        Character *fighter = this->getFighters()[i];
        if (fighter->isAlive()) {
            if (Cowboy *cowboy = dynamic_cast<Cowboy *>(fighter)) {
                if (cowboy->hasboolets())
                    cowboy->shoot(victim);
                else cowboy->reload();
            }
            else if (Ninja* ninja = dynamic_cast<Ninja*>(fighter)) {
                if(ninja->getLocation().distance(victim->getLocation()) <= 1) //the distance less than one meter
                    ninja->slash(victim);
                else ninja->move(victim);
            }
        }
    }
}




