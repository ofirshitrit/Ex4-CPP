//
// Created by ofir on 4/30/23.
//

#ifndef EX4_CPP_TEAM_HPP
#define EX4_CPP_TEAM_HPP

#include <iostream>
#include <vector>
#include <memory>
#include "OldNinja.hpp"
#include "TrainedNinja.hpp"
#include "YoungNinja.hpp"
#include "Cowboy.hpp"


namespace ariel {

    class Team {
    protected:
        Character* _leader;
        std::vector<Character*> fighters;
    public:
        Team(Character* leader);

        ~Team() = default;

        int stillAlive();

        void add(Character* character);

        virtual void attack(Team *other);

        virtual void print();

        Character *getLeader() const;

        std::vector<Character *> &getFighters();

        Character *getNewLeader();

        Character *getVictim(Team *enemies);

        void removeVictim(Team *enemies, Character *victim);

        void attackVictim(Character *victim);
    };
}


#endif //EX4_CPP_TEAM_HPP
