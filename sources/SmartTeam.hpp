//
// Created by ofir on 5/11/23.
//

#ifndef EX4_CPP_SMARTTEAM_HPP
#define EX4_CPP_SMARTTEAM_HPP

#include <iostream>
#include <vector>
#include <memory>
#include "Team.hpp"


namespace ariel {

    class SmartTeam : public Team{
    public:
        SmartTeam(Character *leader) : Team(leader) {}

        ~SmartTeam() = default;


        void attack(Team *other) override;

        void print() override;

    };


}


#endif //EX4_CPP_SMARTTEAM_HPP
