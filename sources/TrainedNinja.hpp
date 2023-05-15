//
// Created by ofir on 5/1/23.
//

#ifndef EX4_CPP_TRAINEDNINJA_HPP
#define EX4_CPP_TRAINEDNINJA_HPP

#include <iostream>
#include "Ninja.hpp"


namespace ariel {
    class TrainedNinja : public Ninja {

    public:
        TrainedNinja(std::string name, Point p) : Ninja(120, name, p, 12) {}

        ~TrainedNinja() override = default;


    };
}


#endif //EX4_CPP_TRAINEDNINJA_HPP
