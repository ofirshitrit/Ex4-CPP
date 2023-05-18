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
    cout << "numbers of alive fighters: " << enemies->stillAlive() << endl;
    if (!this->getLeader()->isAlive()) {
        this->_leader = getNewLeader();
    }
    Character* victim = chooseVictim(enemies);
    cout << "The victim : " << victim->getName() << endl;
    cout << "Victim's Hit Points: " << victim->getHitPoints() << endl;
    for (unsigned int i = 0; i < this->getFighters().size(); i++) {
        Character *fighter = this->getFighters()[i];
        attackVictim(fighter, victim);
        cout << "Victim's Hit Points: " << victim->getHitPoints() << endl;
    }

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
    addSorted(character);
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
    this->fightersAlive = 1;
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
    if (!enemies->getFighters().empty()) {
        for (auto it = enemies->getFighters().begin(); it != enemies->getFighters().end(); ++it) {
            if (*it == victim) {
                enemies->getFighters().erase(it);  // Remove the victim using the iterator
                break;  // Break the loop after removing the element
            }
        }
    }
}

void Team::attackVictim(Character* fighter, Character *victim) {
    if (fighter->isAlive()) {
        if (Cowboy *cowboy = dynamic_cast<Cowboy *>(fighter)) {
            cowboyAttack(cowboy, victim);
        }
        else if (Ninja* ninja = dynamic_cast<Ninja*>(fighter)) {
            ninjaAttack(ninja, victim);
        }
    }
}

void Team::cowboyAttack(Cowboy* cowboy, Character* victim)
{
    if (victim->isAlive()) {
        if (cowboy->hasboolets()) {
            cout << cowboy->getName() << " shoot " << victim->getName() << endl;
            cowboy->shoot(victim);
        }
        else {
            cout << cowboy->getName() << " reload "  << endl;
            cowboy->reload();
        }
    }
}

void Team::ninjaAttack(Ninja* ninja, Character* victim)
{
    if ( victim->isAlive()) {
        if(ninja->getLocation().distance(victim->getLocation()) < 1) { //the distance less than one meter
            cout << ninja->getName() << " slash " << victim->getName() << endl;
            ninja->slash(victim);
        }
        else {
            cout << ninja->getName() << " move " << endl;
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

void Team::addSorted(Character *character) {
    if (Cowboy *cowboy = dynamic_cast<Cowboy *>(character)) {
        fighters.insert(fighters.begin(), character);  // Add cowboy at the beginning
    } else if (Ninja* ninja = dynamic_cast<Ninja*>(character)) {
        fighters.push_back(character);  // Add ninja at the end
    }
}
