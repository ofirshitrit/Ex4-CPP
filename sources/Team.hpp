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
    private:
        Character* _leader;
        std::vector<Character*> fighters;
    public:
        Team(Character* leader);

        ~Team();

        int stillAlive();

        virtual void add(Character* character);

        virtual void attack(Team *enemies);

        virtual void print();

        Character *getLeader() const;

        void setLeader(Character *leader);

        std::vector<Character *> &getFighters();

        Character *getNewLeader();

        virtual Character *chooseVictim(Team *enemies);

        Character* getMember(Team* team);

        void attackByNinjas(Team* enemies, Character* victim);

        void attackByCowboys(Team* enemies, Character* victim);

    };
}


#endif //EX4_CPP_TEAM_HPP
