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


        int getIndexOfClosestEnemy(Team *enemies);

        void getDistanceAndIndex(Ninja* fighter, Team* enemies, double* minDistance, int* index);
    };
}

#endif //EX4_CPP_SMARTTEAM_HPP
