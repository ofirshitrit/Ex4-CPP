//
// Created by ofir on 5/11/23.
//

#ifndef EX4_CPP_SMARTTEAM_HPP
#define EX4_CPP_SMARTTEAM_HPP

#include <iostream>
#include <vector>
#include <memory>
#include <unordered_map>

#include "Team.hpp"


namespace ariel {

    class SmartTeam : public Team {
    private:
        std::vector<Character *> ninjas;
    public:
        SmartTeam(Character *leader) : Team(leader), ninjas() {}

        ~SmartTeam() = default;

        void add(Character *character) override;

        void print() override;

        void attack(Team *enemies) override;

        Character *chooseVictim(Team *enemies) override;

        Character *getClosestToNinjas(Team *enemies);

        const std::vector<Character *> &getNinjas() const;

        void fillTheMap(std::unordered_map<double, int> distanceFromEnemies, std::vector<double> distanceFromOldNinja,
                        std::vector<double> distanceFromYoungNinja, std::vector<double> distanceFromTrainedNinja);

        double getSmallestDistance(double &d, double &d1, double &d2);

        std::vector<double> getDistanceFromNinja(Team *enemies);

        void fromOldNinja(Ninja* fighter,Team* enemies, double* minDistance,int* index);
    };
}

#endif //EX4_CPP_SMARTTEAM_HPP
