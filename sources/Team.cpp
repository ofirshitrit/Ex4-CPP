//
// Created by ofir on 4/30/23.
//
#include <iostream>
#include "Team.hpp"


using namespace ariel;
using namespace std;




void Team::attack(Team* enemies) {
    if (enemies == nullptr) throw invalid_argument("Cant attack nullptr");
    if (enemies->stillAlive() == 0) throw runtime_error("Cant attack dead team!");
    if (!enemies->getLeader()->isAlive()) {
        this->_leader = getNewLeader();
    }
    while (!enemies->getFighters().empty()) {
        Character* victim = chooseVictim(enemies);
        while (victim->isAlive()) {
            attackVictim(victim);
        }
        cout << victim->getName() << " is dead" << endl;
        removeVictim(enemies, victim);
    }
    cout << "The enemy is dead!" << endl;
}

int Team::stillAlive() {

    return this->fighters.size();
}

void Team::print() {
    for(unsigned int i = 0; i < this->fighters.size(); i++)
    {
       cout << this->fighters[i]->print() << endl;
    }
}

void Team::add( Character* character) {
    if (this->fighters.size() == 10) throw runtime_error("The team cant be over 10 fighters");
    if (character->isBelongToTeam()) {
        this->fighters.pop_back(); //remove the character
        throw runtime_error("This character belong to another team");
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
        throw runtime_error("This captain belong to another team");
    }
    fighters.push_back(leader);
    leader->setBelongToTeam(true);
}

Character *Team::getNewLeader() {
    Character* newLeader = pickMember(this);
    return newLeader;
}

Character *Team::chooseVictim(Team *enemies) {
    if (enemies == this) throw runtime_error("Team cant choose a victim from itself ");
    Character* victim = pickMember(enemies);
    return victim;
}

void Team::removeVictim(Team* enemies, Character* victim) {
    if (enemies == this) throw runtime_error("Team cant remove a victim from itself ");
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
                cowboyAttack(cowboy, victim);
            }
            else if (Ninja* ninja = dynamic_cast<Ninja*>(fighter)) {
                ninjaAttack(ninja, victim);
            }
        }
    }
}

void Team::cowboyAttack(Cowboy* cowboy, Character* victim)
{
    if (victim->isAlive()) {
        if (cowboy->hasboolets()) {
            cowboy->shoot(victim);
        }
        else {
            cowboy->reload();
        }
    }
}

void Team::ninjaAttack(Ninja* ninja, Character* victim)
{
    if ( victim->isAlive()) {
        if(ninja->getLocation().distance(victim->getLocation()) <= 1) { //the distance less than one meter
            ninja->slash(victim);
        }
        else {
            ninja->move(victim);
        }
    }
}

Character* Team::pickMember(Team* team){
    Character* member = nullptr;
    double minDistance = 100000000;
    for( unsigned int i = 0; i < team->getFighters().size(); i++){
        if (team->getFighters()[i]->isAlive()){
            double currDistance = team->getFighters()[i]->getLocation().distance(this->_leader->getLocation());
            if (currDistance < minDistance){
                minDistance = currDistance;
                member = team->getFighters()[i];
            }
        }
    }
    return member;
}
