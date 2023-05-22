//
// Created by ofir on 5/1/23.
//

#ifndef EX4_CPP_COWBOY_HPP
#define EX4_CPP_COWBOY_HPP
constexpr int hit_points = 110;
constexpr int num_of_balls = 6;
#include "Character.hpp"

namespace ariel {
    class Cowboy : public Character {
    private:
        int numOfBalls = num_of_balls;
    public:
        Cowboy(std::string name, Point point) : Character(hit_points, name, point) {}

        ~Cowboy() override = default;

        std::string print() override;

        void shoot(Character* enemy);

        bool hasboolets();

        void reload();

        int getNumOfBalls() const;

        void attack(Character* victim) override;

        //for tidy
        Cowboy(const Cowboy&) = delete;
        Cowboy& operator=(const Cowboy&) = delete;
        Cowboy(Cowboy&&) = delete;
        Cowboy& operator=(Cowboy&&) = delete;

    };
}


#endif //EX4_CPP_COWBOY_HPP
