//
// Created by ofir on 5/1/23.
//

#ifndef EX4_CPP_OLDNINJA_HPP
#define EX4_CPP_OLDNINJA_HPP

#include "Ninja.hpp"
constexpr int ON_HIT_POINTS = 150;
constexpr int ON_SPEED = 8;

namespace ariel {
    class OldNinja : public Ninja {
    public:
        OldNinja(std::string name, Point location) : Ninja(ON_HIT_POINTS, name, location, ON_SPEED) {}

//        ~OldNinja() override = default;


    };
}


#endif //EX4_CPP_OLDNINJA_HPP
