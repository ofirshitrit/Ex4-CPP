/**
 * Demo file for the exercise on binary tree
 *
 * @author Evgeny Hershkovitch Neiterman
 * @since 2023-03
 */

#include <iostream>
#include <random>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cassert>
using namespace std;

#include "sources/Team.hpp" //no need for other includes
#include "sources/SmartTeam.hpp"


using namespace ariel;


int main() {


    Cowboy* c = new Cowboy("c", Point{-1,-1});
    Cowboy* cow = new Cowboy("cy", Point{2,2});
    YoungNinja* youngNinja = new YoungNinja("yn" , Point(0,0));
    OldNinja* oldNinja = new OldNinja("on" , Point(-0.5,-0.5));
    TrainedNinja* trainedNinja = new TrainedNinja("tn" , Point(0.5,0.5));

    Team team1(c);
    team1.add(cow);
    team1.add(youngNinja);
    team1.add(oldNinja);
    team1.add(trainedNinja);

    Cowboy* cowboy1 = new Cowboy("c1", Point{-6,-6});
    Cowboy* cowboy2 = new Cowboy("c2", Point{-7,-7});
    Cowboy* cowboy3 = new Cowboy("c3", Point{-8,-8});
    YoungNinja* youngNinjaa = new YoungNinja("ynn" , Point(0,0));
    YoungNinja* youngNinja2 = new YoungNinja("yn2" , Point(3,3));
    OldNinja* oldNinjaa = new OldNinja("onn" , Point(2,2));
    TrainedNinja* trainedNinjaa = new TrainedNinja("tnn" , Point(1,1));

    SmartTeam team(cowboy1);
    team.add(cowboy2);
    team.add(cowboy3);
    team.add(youngNinjaa);
    team.add(youngNinja2);
    team.add(oldNinjaa);
    team.add(trainedNinjaa);

//    team.print();

//    for ( int i =1; i<=30; i++) {
//        cout << "*** The " << i << " attack!! *** " << endl;
//        team.attack(&team1);
//        if (team1.stillAlive() > 0 ) {
//            cout << "The team is alive!" << endl;
//        } else {
//            cout << "The team is dead!" << endl;
//            break;
//        }
//        cout << endl;
//    }

    return 0; // no memory issues. Team should free the memory of its members. both a and b teams are on the stack.

}
