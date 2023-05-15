//
// Created by ofir on 5/1/23.
//

#ifndef EX4_CPP_OLDNINJA_HPP
#define EX4_CPP_OLDNINJA_HPP

#include "Ninja.hpp"


namespace ariel {
    class OldNinja : public Ninja {
    private:
    public:
        OldNinja(std::string name, Point p) : Ninja(150, name, p, 8) {}

        ~OldNinja() override = default;


    };
}


#endif //EX4_CPP_OLDNINJA_HPP
