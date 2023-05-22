//
// Created by ofir on 5/11/23.
//

#include "SmartTeam.hpp"
#include "Team.hpp"
#include <cfloat>


using namespace ariel;
using namespace std;



void SmartTeam::add(Character *character) {
    if (this->getFighters().size() == 10) throw runtime_error("The team cant be over 10 fighters");
    if (character->isBelongToTeam()) {
        throw runtime_error("This character belong to another team");
    }
    character->setBelongToTeam(true);
    this->getFighters().push_back(character);
}

void SmartTeam::print() {
    for (Character* fighter : this->getFighters()) {
        cout << fighter->print() << endl;
    }
}
 /**
  * The idea:
  * The victim is choosen such that he will be closest to the ninjas,
  * because Ninjas are hit the most in the enemy's hit points.
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
        setLeader(getNewLeader());
    }

    Character* victim = chooseVictim(enemies);
    if (victim->isAlive()) {
        attackByNinjas(enemies, victim);
    }

    if (victim->isAlive()) {
        attackByCowboys(enemies, victim);
    }

}

Character* SmartTeam::chooseVictim(Team *enemies) {
    Character* victim = getClosestToNinjas(enemies);
    return victim;
}

Character* SmartTeam::getClosestToNinjas(Team *enemies) {

    unsigned int indexOfClosestEnemy = getIndexOfClosestEnemy(enemies);

    Character* enemy =  enemies->getFighters()[indexOfClosestEnemy];
    return enemy;
}


unsigned int SmartTeam::getIndexOfClosestEnemy(Team *enemies) {
    double minDistance = DBL_MAX;
    unsigned int index = 0;
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

void SmartTeam::getDistanceAndIndex(Ninja* fighter, Team* enemies, double* minDistance, unsigned int* index)
{
    for (unsigned int i = 0; i < enemies->getFighters().size(); i++ ){
        Character* enemy = enemies->getFighters()[i];
        if (enemy->isAlive()) {
            double currDistance = fighter->getLocation().distance(enemy->getLocation());
            if (currDistance < *minDistance) {
                *minDistance = currDistance;
                *index = i;
            }
        }
    }
}

