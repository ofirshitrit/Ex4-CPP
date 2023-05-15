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

        ~TrainedNinja() = default;

        std::string print() override;

        friend std::ostream &operator<<(std::ostream &ostream, const TrainedNinja &trainedNinja);

    };
}


#endif //EX4_CPP_TRAINEDNINJA_HPP
