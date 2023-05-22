//
// Created by ofir on 5/1/23.
//

#ifndef EX4_CPP_NINJA_HPP
#define EX4_CPP_NINJA_HPP

#include "Character.hpp"

namespace ariel {
    class Ninja : public Character {
    private:
        int _speed;
    public:
        Ninja(int hitPoints, std::string name, Point &loc, int spd) : Character(hitPoints, name, loc), _speed(spd) {}

        ~Ninja() override = default;

        std::string print() override;

        void move(Character* enemy);

        void slash(Character* enemy);

        int getSpeed() const;

        void attack(Character* victim) override;

        //for tidy
        Ninja(const Ninja &) = delete;
        Ninja &operator=(const Ninja &) = delete;
        Ninja(Ninja &&) = delete;
        Ninja &operator=(Ninja &&) = delete;

    };
}


#endif //EX4_CPP_NINJA_HPP
