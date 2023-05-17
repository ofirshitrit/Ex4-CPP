//
// Created by ofir on 5/1/23.
//

#ifndef EX4_CPP_YOUNGNINJA_HPP
#define EX4_CPP_YOUNGNINJA_HPP
#include <iostream>
#include "Ninja.hpp"

namespace ariel {
    class YoungNinja : public Ninja{
    public:
        YoungNinja(std::string name ,Point p) : Ninja(100, name, p, 14){}
        ~YoungNinja() override = default;

    };
}



#endif //EX4_CPP_YOUNGNINJA_HPP
