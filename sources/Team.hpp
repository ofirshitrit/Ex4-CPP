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
        int fightersAlive;
    public:
        Team(Character* leader);

        ~Team() = default;

        int stillAlive();

        virtual void add(Character* character);

        void attack(Team *enemies);

        virtual void print();

        Character *getLeader() const;

        std::vector<Character *> &getFighters();

        Character *getNewLeader();

        Character *chooseVictim(Team *enemies);

        void removeVictim(Team *enemies, Character *victim);

        void attackVictim(Character* fighter, Character *victim);

        Character* pickMember(Team* team);
        void cowboyAttack(Cowboy* cowboy, Character* victim);
        void ninjaAttack(Ninja* ninja, Character* victim);

        void addSorted(Character *character);
    };
}


#endif //EX4_CPP_TEAM_HPP
