//
// Created by ofir on 5/11/23.
//

#include "SmartTeam.hpp"
#include "Team.hpp"
#include <unordered_map>
#include <algorithm>
#include <cfloat>


using namespace ariel;
using namespace std;



void SmartTeam::add(Character *character) {
    if (this->fighters.size() == 10) throw runtime_error("The team cant be over 10 fighters");
    if (character->isBelongToTeam()) {
        throw runtime_error("This character belong to another team");
    }
    character->setBelongToTeam(true);
    this->getFighters().push_back(character);
    if (Ninja* ninja = dynamic_cast<Ninja*>(character)) {
        this->ninjas.push_back(ninja);
    }
}

void SmartTeam::print() {
    for (Character* fighter : this->getFighters()) {
        cout << fighter->print() << endl;
    }
}
 /**
  * This function works on this method:
  * The victim is choosen such that he will be the closest enemy to one of the ninjas.
  * Ninjas attack first because they can hit the most at the enemy's hit points.
  * Then the cowboys attack
  * @param enemies
  */

void SmartTeam::attack(Team* enemies) {
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

Character* SmartTeam::chooseVictim(Team *enemies) {
    Character* victim = getClosestToNinjas(enemies);
    return victim;
}

Character* SmartTeam::getClosestToNinjas(Team *enemies) {

    int indexOfClosestEnemy = getIndexOfClosestEnemy(enemies);
    cout << "indexOfClosestEnemy: " << indexOfClosestEnemy << endl; //TODO

    Character* enemy =  enemies->getFighters()[indexOfClosestEnemy];
    cout << enemy->print() << endl;
    return enemy;
}

const vector<Character*> &SmartTeam::getNinjas() const {
    return ninjas;
}

int SmartTeam::getIndexOfClosestEnemy(Team *enemies) {
    double minDistance = DBL_MAX;
    int index = 0;
    for (Character* fighter : this->getFighters()) {
        if ( OldNinja* oldninja = dynamic_cast<OldNinja*>(fighter)) {
            getDistanceAndIndex(oldninja,enemies,&minDistance,&index);
        } else if ( TrainedNinja* trainedNinja = dynamic_cast<TrainedNinja*>(fighter)) {
            getDistanceAndIndex(trainedNinja,enemies,&minDistance,&index);
        } else if ( YoungNinja* youngNinja = dynamic_cast<YoungNinja*>(fighter)) {
            getDistanceAndIndex(youngNinja,enemies,&minDistance,&index);
        }
    }
    return index;
}

void SmartTeam::getDistanceAndIndex(Ninja* fighter, Team* enemies, double* minDistance, int* index)
{
    for (unsigned int i = 0; i < enemies->getFighters().size(); i++ ){
        Character* enemy = enemies->getFighters()[i];
        double currDistance = fighter->getLocation().distance(enemy->getLocation());
        if (currDistance < *minDistance) {
            *minDistance = currDistance;
            *index = i;
        }
    }
}

