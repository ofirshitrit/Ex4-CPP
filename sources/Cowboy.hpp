//
// Created by ofir on 5/1/23.
//

#ifndef EX4_CPP_COWBOY_HPP
#define EX4_CPP_COWBOY_HPP

#include "Character.hpp"

namespace ariel {
    class Cowboy : public Character {
    private:
        int numOfBalls = 6;
    public:
        Cowboy(std::string name, Point &point) : Character(110, name, point) {}

        ~Cowboy() = default;

        std::string print() override;

        void shoot(const Character* enemy);

        bool hasboolets();

        void reload();

        friend std::ostream &operator<<(std::ostream &ostr, const Cowboy &cowboy);

        int getNumOfBalls() const;

    };
}


#endif //EX4_CPP_COWBOY_HPP
