/**
 * Demo file for the exercise on binary tree
 *
 * @author Evgeny Hershkovitch Neiterman
 * @since 2023-03
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cassert>
using namespace std;

#include "sources/Team.hpp" //no need for other includes

using namespace ariel;


int main() {


    /**
     * shoot(2);
        cowboy->reload();
        shoot(6);
        CHECK(target->isAlive()); // Target should still be alive with 10 hit points if the cowboys damage is 10
        shoot(1);
        CHECK(target->isAlive()); // Reloading when the magazine isn't empty shouldn't result in more than 6 bullets, the previous shoot should have no effect //TODO
        cowboy->reload();
        shoot(1);
        CHECK_FALSE(target->isAlive()); // Target should be dead
     */


    Point a(32.3,44),b(1.3,3.5);
//    assert(a.distance(b) == b.distance(a));
    Cowboy *tom = new Cowboy("Tom", a);
    OldNinja *sushi = new OldNinja("sushi", b);
    cout << "hit points in the begining: " << sushi->getHitPoints() << endl;

    for ( int i = 0; i < 6; i++ )  tom->shoot(sushi);
    cout << "hit points after 6: " << sushi->getHitPoints() << endl;

    tom->shoot(sushi);
    cout << "hit points after 1: " << sushi->getHitPoints() << endl;

    tom->reload();

    for ( int i = 0; i < 2; i++ ) tom->shoot(sushi);
    cout << "hit points after 2: " << sushi->getHitPoints() << endl;

    tom->reload();

    for ( int i = 0; i < 6; i++ )  tom->shoot(sushi);
    cout << "hit points after 6: " << sushi->getHitPoints() << endl;
    (sushi->isAlive()) ? cout << "isALive" << endl : cout << "not Alive" << endl;

    tom->shoot(sushi);
    cout << "hit points after 1: " << sushi->getHitPoints() << endl;
    (sushi->isAlive()) ? cout << "isALive" << endl : cout << "not Alive" << endl;

    tom->reload();

    tom->shoot(sushi);
    cout << "hit points after 1: " << sushi->getHitPoints() << endl;
    (sushi->isAlive()) ? cout << "isALive" << endl : cout << "not Alive" << endl;



//    cout << tom->print() <<endl;
//
//    sushi->move(tom);
//    sushi->slash(tom);
//
//    Team team_A(tom);
//    team_A.add(new YoungNinja("Yogi", Point(64,57)));
//
//    // Team b(tom); should throw tom is already in team a
//
//     Team team_B(sushi);
//     team_B.add(new TrainedNinja("Hikari", Point(12,81)));
//
//
//     while(team_A.stillAlive() > 0 && team_B.stillAlive() > 0){
//        team_A.attack(&team_B);
//        team_B.attack(&team_A);
//        team_A.print();
//        team_B.print();
//     }
//
//     if (team_A.stillAlive() > 0) cout << "winner is team_A" << endl;
//     else cout << "winner is team_B" << endl;

     return 0; // no memory issues. Team should free the memory of its members. both a and b teams are on the stack.

}
