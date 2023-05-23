//
// Created by ofr on 5/23/23.
//
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cassert>
using namespace std;

#include "sources/Team.hpp"
#include "sources/SmartTeam.hpp"

using namespace ariel;


int main() {


    /*** Team ***/

    Cowboy* bob = new Cowboy("Bob", Point(0, 0));
    bool ans = bob->isBelongToTeam(); // false
    Team A(bob);
    bool ans1 = bob->isBelongToTeam(); // true
    cout << "ans = " << ans << endl;
    cout << "ans1 = " << ans1 << endl;

    Cowboy* bob2 = new Cowboy("Bob2", Point(0, 2));
    Cowboy* bob3 = new Cowboy("Bob3", Point(0, 3));
    OldNinja* alice2 = new OldNinja("alice2",Point(1,1));
    TrainedNinja* alice3 = new TrainedNinja("alice3",Point(1,1));
    A.add(bob2);
    A.add(bob3);
    A.add(alice2);
    A.add(alice3);



    OldNinja* alice = new OldNinja("alice",Point(1,1));
    Team B(alice);
    Cowboy* bob4 = new Cowboy("Bob4", Point(0, 3));
    Cowboy* bob5 = new Cowboy("Bob5", Point(8, 3));
    OldNinja* alice4 = new OldNinja("alice4",Point(1,1));
    YoungNinja* alice5 = new YoungNinja("alice5",Point(1,1));
    B.add(bob4);
    B.add(bob5);
    B.add(alice4);
    B.add(alice5);

    Character* victimFromA = B.chooseVictim(&A); // alice2
    victimFromA->print();

    Character* victimFromB = A.chooseVictim(&B); // alice
    victimFromB->print();

    /*** SmartTeam ***/
    Cowboy* bob6 = new Cowboy("Bob6", Point(0, 3));
    Cowboy* bob7 = new Cowboy("Bob7", Point(8, 3));
    OldNinja* alice6 = new OldNinja("alice6",Point(1,1));
    YoungNinja* alice7 = new YoungNinja("alice7",Point(1,1));
    SmartTeam C(bob6);
    C.add(bob7);
    C.add(alice6);
    C.add(alice7);

    Cowboy* bob8 = new Cowboy("Bob8", Point(0, 3));
    Cowboy* bob9 = new Cowboy("Bob9", Point(10, 3));
    OldNinja* alice8 = new OldNinja("alice6",Point(15,1));
    YoungNinja* alice9 = new YoungNinja("alice7",Point(88,1));
    SmartTeam D(bob8);
    D.add(bob9);
    D.add(alice8);
    D.add(alice9);

    Character* victimFromD = C.chooseVictim(&D); // Bob8
    victimFromD->print();

    Character* victimFromC = D.chooseVictim(&C); // Bob7
    victimFromC->print();







    return 0; // no memory issues. Team should free the memory of its members. both a and b teams are on the stack.

}