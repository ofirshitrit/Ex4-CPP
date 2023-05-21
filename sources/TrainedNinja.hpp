//
// Created by ofir on 5/1/23.
//

#ifndef EX4_CPP_TRAINEDNINJA_HPP
#define EX4_CPP_TRAINEDNINJA_HPP

#include <iostream>
#include "Ninja.hpp"
#define TN_HIT_POINTS 120
#define TN_SPEED 12


namespace ariel {
    class TrainedNinja : public Ninja {

    public:
        TrainedNinja(std::string name, Point location) : Ninja(TN_HIT_POINTS, name, location, TN_SPEED) {}

        ~TrainedNinja() override = default;


    };
}


#endif //EX4_CPP_TRAINEDNINJA_HPP
