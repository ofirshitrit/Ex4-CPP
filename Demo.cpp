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


    Cowboy* cowboy = new Cowboy("c", Point{-1,-1});
    Cowboy* cowboyy = new Cowboy("cy", Point{2,2});
    YoungNinja* youngNinja = new YoungNinja("yn" , Point(-0.5,-0.5));
    OldNinja* oldNinja = new OldNinja("on" , Point(0,0));
    TrainedNinja* trainedNinja = new TrainedNinja("tn" , Point(0.5,0.5));
    Team team(cowboy);
    team.add(cowboyy);
    team.add(youngNinja);
    team.add(oldNinja);
    team.add(trainedNinja);


    Cowboy* cowboy1 = new Cowboy("c1", Point{-6,-6});
    Cowboy* cowboy2 = new Cowboy("c2", Point{-7,-7});
    Cowboy* cowboy3 = new Cowboy("c3", Point{-8,-8});
    YoungNinja* youngNinjaa = new YoungNinja("ynn" , Point(0,0));
    YoungNinja* youngNinja2 = new YoungNinja("yn2" , Point(3,3));
    OldNinja* oldNinjaa = new OldNinja("onn" , Point(2,2));
    TrainedNinja* trainedNinjaa = new TrainedNinja("tnn" , Point(1,1));


    Team team2{youngNinjaa};
    team2.add(trainedNinjaa);
    team2.add(oldNinjaa);
    team2.add(youngNinja2);
    team2.add(cowboy1);
    team2.add(cowboy2);
    team2.add(cowboy3);

    std::cout << "TEAM 2: " << std::endl;
    team2.print();
    int j = 0;
    for( int i = 1; i <=2; i++){
        cout << " ++++++ The " << i << " attack! " << endl;
        team.attack(&team2);
        cout << "alive after attack: " << team2.stillAlive() << endl;
        cout << endl;

    }
    j = 3;
    youngNinjaa->isAlive() ? cout << "YN Alive" << endl : cout << "YN dead" << endl;  // dead
    oldNinjaa->isAlive() ? cout << "ON Alive" << endl : cout << "ON dead" << endl;  // alive
    trainedNinjaa->isAlive() ? cout << "TN Alive" << endl : cout << " TN dead" << endl;  // alive
    youngNinja2->isAlive() ? cout << "YN2 Alive" << endl : cout << " YN2 dead" << endl;  // alive
    cout << endl;

    cout << "++++ The " << j << " attack! " << endl;
    team.attack(&team2);
    j++;
    oldNinjaa->isAlive() ? cout << "ON Alive" << endl : cout << "ON dead" << endl;  // alive
    trainedNinjaa->isAlive() ? cout << "TN Alive" << endl : cout << "TN dead" << endl;  // dead
    youngNinja2->isAlive() ? cout << "YN2 Alive" << endl : cout << "YN2 dead" << endl;  // alive
    cout << endl;

    for( int i = 1; i <=2; i++){
        cout << "++++ The " << j << " attack! " << endl;
        team.attack(&team2);
        cout << "alive after attack: " << team2.stillAlive() << endl;
        cout << endl;
        j++;
    }
    trainedNinjaa->isAlive() ? cout << " TN Alive" << endl : cout << " TN dead" << endl;  // dead
    oldNinjaa->isAlive() ? cout << "ON Alive" << endl : cout << "ON dead" << endl;  // dead
    youngNinja2->isAlive() ? cout << "YN2 Alive" << endl : cout << "YN2 dead" << endl;  // alive
    cout << endl;

    for( int i = 1; i <=4; i++){
        cout << " +++++ The " << j << " attack! " << endl;
        team.attack(&team2);
        cout << "alive after attack: " << team2.stillAlive() << endl;
        cout << endl;
        j++;
    }
    oldNinjaa->isAlive() ? cout << "ON Alive" << endl : cout << "ON dead" << endl;  // dead
    youngNinja2->isAlive() ? cout << "YN2 Alive" << endl : cout << " YN2 dead" << endl;  // dead

    for( int i = 1; i <=2; i++){
        cout << "++++ The " << j << " attack! " << endl;
        team.attack(&team2);
        cout << "alive after attack: " << team2.stillAlive() << endl;
        cout << endl;
        j++;
    }

    cout << "++++ The " << j << " attack! " << endl;
    team.attack(&team2);
    cout << "alive after attack: " << team2.stillAlive() << endl;
    youngNinja2->isAlive() ? cout << "YN2 Alive" << endl : cout << "YN2 dead" << endl;  // dead


    team.attack(&team2); // exception
    cout << "alive after attack: " << team2.stillAlive() << endl;








    return 0; // no memory issues. Team should free the memory of its members. both a and b teams are on the stack.

}
