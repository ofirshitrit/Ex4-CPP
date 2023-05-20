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

using namespace ariel;


int main() {

//
//    Cowboy* c = new Cowboy("c", Point{-1,-1});
//    Cowboy* cow = new Cowboy("cy", Point{2,2});
//    YoungNinja* youngNinja = new YoungNinja("yn" , Point(0,0));
//    OldNinja* oldNinja = new OldNinja("on" , Point(-0.5,-0.5));
//    TrainedNinja* trainedNinja = new TrainedNinja("tn" , Point(0.5,0.5));
//    Team team(c);
//    team.add(cow);
//    team.add(youngNinja);
//    team.add(oldNinja);
//    team.add(trainedNinja);
//
//
//    Cowboy* cowboy1 = new Cowboy("c1", Point{-6,-6});
//    Cowboy* cowboy2 = new Cowboy("c2", Point{-7,-7});
//    Cowboy* cowboy3 = new Cowboy("c3", Point{-8,-8});
//    YoungNinja* youngNinjaa = new YoungNinja("ynn" , Point(0,0));
//    YoungNinja* youngNinja2 = new YoungNinja("yn2" , Point(3,3));
//    OldNinja* oldNinjaa = new OldNinja("onn" , Point(2,2));
//    TrainedNinja* trainedNinjaa = new TrainedNinja("tnn" , Point(1,1));
//
//
//    Team team2{youngNinjaa};
//    team2.add(trainedNinjaa);
//    team2.add(oldNinjaa);
//    team2.add(youngNinja2);
//    team2.add(cowboy1);
//    team2.add(cowboy2);
//    team2.add(cowboy3);
//
//
//    for( unsigned int i = 0; i < team2.getFighters().size(); i++) {
//        cout << team2.getFighters()[i]->getName() << endl;
//    }
//
//
//    int j = 0;
//    for( int i = 1; i <=2; i++){
//        cout << " ++++++ The " << i << " attack! " << endl;
//        team.attack(&team2);
//        cout << "alive after attack: " << team2.stillAlive() << endl;
//        cout << endl;
//
//    }
//    j = 3;
//    cout << endl;
//
//    cout << "++++ The " << j << " attack! " << endl;
//    team.attack(&team2);
//    j++;
//    cout << endl;
//
//    for( int i = 1; i <=2; i++){
//        cout << "++++ The " << j << " attack! " << endl;
//        team.attack(&team2);
//        cout << "alive after attack: " << team2.stillAlive() << endl;
//        cout << endl;
//        j++;
//    }
//    cout << endl;
//
//    for( int i = 1; i <=4; i++){
//        cout << " +++++ The " << j << " attack! " << endl;
//        team.attack(&team2);
//        cout << "alive after attack: " << team2.stillAlive() << endl;
//        cout << endl;
//        j++;
//    }
//
//    for( int i = 1; i <=2; i++){
//        cout << "++++ The " << j << " attack! " << endl;
//        team.attack(&team2);
//        cout << "alive after attack: " << team2.stillAlive() << endl;
//        cout << endl;
//        j++;
//    }
//
//    cout << "++++ The " << j << " attack! " << endl;
//    team.attack(&team2);
//    cout << "alive after attack: " << team2.stillAlive() << endl;
//    cout << endl;
//
//    cout << "This attack soulnd happend" << endl;
//    team.attack(&team2); // exception
//    cout << "alive after attack: " << team2.stillAlive() << endl;
//
//






    return 0; // no memory issues. Team should free the memory of its members. both a and b teams are on the stack.

}
