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
    Point a(0,0),b(0,0.5),c(0,3),d(0,10);
    Cowboy *tom = new Cowboy("Tom", a);
    Cowboy *t = new Cowboy("T", a);
    Cowboy *to = new Cowboy("To", d);
    Cowboy *tom1 = new Cowboy("Tom1", d);


    OldNinja *sush = new OldNinja("sush", d);
    OldNinja *sushi = new OldNinja("sushi", d);
    OldNinja *s = new OldNinja("s", b);
    OldNinja *sus = new OldNinja("sus", c);
    OldNinja *ssss = new OldNinja("ssss", d);
    OldNinja *stttt = new OldNinja("stttt", d);


    Team team_A(s);
    team_A.add(sus);
    team_A.add(tom1);

    Team team_B(sushi);
//    team_B.add(s);
//    team_B.add(sus);
    team_B.add(tom);
    team_B.add(ssss);
    team_B.add(stttt);
    team_B.add(to);

    cout << "TeamA: " << endl;
    team_A.print();
    cout << "TeamB: " << endl;
    team_B.print();

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
