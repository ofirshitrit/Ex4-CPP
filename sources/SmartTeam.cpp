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
        this->fighters.pop_back(); //remove the character
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
        fighter->print();
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
/**
 * To get the closest enemy to the ninjas:
 * 1. Get the smallest distance from the ninjas and the index of the enemy
 * 2. Store it in a map such that the pulling of the index's enemy will be easy
 * 3. From all the three distance get the smallest distance
 * 4. Get it's value from the map
 * 5. Return the fighter that in the index above in the eneimes fighters
 * @param enemies
 * @return closest enemy to the ninjas
 */
Character* SmartTeam::getClosestToNinjas(Team *enemies) {

    /**
     * Those functions return two values:
     * 1. the smallest distance from a specific ninja
     * 2. the index of the enemy that closest to the ninja
     */
    vector<double> distanceFromOldNinja = getDistanceFromNinja(enemies);
    vector<double> distanceFromYoungNinja = getDistanceFromNinja(enemies);
    vector<double> distanceFromTrainedNinja = getDistanceFromNinja(enemies);

    /**
    * Create a map to store the values we get above.
    */
    unordered_map<double, int> distanceFromEnemies;
    fillTheMap(distanceFromEnemies,distanceFromOldNinja,distanceFromYoungNinja,distanceFromTrainedNinja);
    distanceFromEnemies[distanceFromOldNinja[0]] = distanceFromOldNinja[1];
    distanceFromEnemies[distanceFromYoungNinja[0]] = distanceFromYoungNinja[1];
    distanceFromEnemies[distanceFromTrainedNinja[0]] = distanceFromTrainedNinja[1];

    /**
     * From all the distance from the ninjas , we want the smallest one.
     */
    double smallestDistance = getSmallestDistance(distanceFromOldNinja[0],distanceFromYoungNinja[0],distanceFromTrainedNinja[0]);

    /**
     * Now we have the key of the victim that we want.
     */
    int indexOfVictim = distanceFromEnemies[smallestDistance];

    return enemies->getFighters()[indexOfVictim];
}

const vector<Character*> &SmartTeam::getNinjas() const {
    return ninjas;
}

void SmartTeam::fillTheMap(unordered_map<double, int> distanceFromEnemies,vector<double> distanceFromOldNinja, vector<double> distanceFromYoungNinja, vector<double> distanceFromTrainedNinja) {
    distanceFromEnemies[distanceFromOldNinja[0]] = distanceFromOldNinja[1];
    distanceFromEnemies[distanceFromYoungNinja[0]] = distanceFromYoungNinja[1];
    distanceFromEnemies[distanceFromTrainedNinja[0]] = distanceFromTrainedNinja[1];
}

double SmartTeam::getSmallestDistance(double &d, double &d1, double &d2) {

    return min({d,d1,d2});
}

vector<double> SmartTeam::getDistanceFromNinja(Team *enemies) {
    vector<double> distanceAndIndex;
    double minDistance = DBL_MAX;
    int index = 0;
    for (Character* fighter : this->getFighters()) {
        if ( OldNinja* oldninja = dynamic_cast<OldNinja*>(fighter)) {
            for (unsigned int i = 0; i < enemies->getFighters().size(); i++ ){
                Character* enemy = enemies->getFighters()[i];
                double currDistance = getDistance(enemy, oldninja);
                if (currDistance < minDistance) {
                    minDistance = currDistance;
                    index = i;
                }
            }
        }
    }
    distanceAndIndex[0] = minDistance;
    distanceAndIndex[1] = index;

    return distanceAndIndex;
}

void SmartTeam::fromOldNinja(Ninja* fighter,Team* enemies, double* minDistance,int* index)
{
    for (unsigned int i = 0; i < enemies->getFighters().size(); i++ ){
        Character* enemy = enemies->getFighters()[i];
        double currDistance = getDistance(enemy, oldninja);
        if (currDistance < *minDistance) {
            *minDistance = currDistance;
            *index = i;
        }
    }
}

