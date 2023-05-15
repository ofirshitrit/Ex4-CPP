//
// Created by ofir on 5/11/23.
//

#ifndef EX4_CPP_TEAM2_HPP
#define EX4_CPP_TEAM2_HPP

#include "Team.hpp"
namespace ariel {

    class Team2 : public Team{
    private:
    public:
        Team2(Character *leader) : Team(leader) {}

        ~Team2() = default;

        void attack(Team *other) override;

        void print() override;

        void add(Character* character) override;

    };



}


#endif //EX4_CPP_TEAM2_HPP
