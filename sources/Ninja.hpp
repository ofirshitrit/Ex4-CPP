//
// Created by ofir on 5/1/23.
//

#ifndef EX4_CPP_NINJA_HPP
#define EX4_CPP_NINJA_HPP

#include "Character.hpp"

namespace ariel {
    class Ninja : public Character {
    protected:
        int _speed;
    public:
        Ninja(int hp, std::string name, Point &loc, int spd) : Character(hp, name, loc), _speed(spd) {}

        virtual ~Ninja() override = default;

        std::string print() override;

        void move(const Character* enemy);

        void slash(Character* enemy);

        int getSpeed() const;

    };
}


#endif //EX4_CPP_NINJA_HPP
