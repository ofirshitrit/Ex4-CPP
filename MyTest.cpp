//
// Created by ofir on 5/1/23.
//


#include "doctest.h"
#include <stdexcept>
#include "sources/Team.hpp"
#include "sources/Team2.hpp"
#include "sources/SmartTeam.hpp"

using namespace std;
using namespace ariel;


TEST_SUITE("Point class functions") {
    Point p1(0,0) , p2(0,2) , p3(0,-1), p4(0,10);

    TEST_CASE("Distance function") {
        CHECK((p1.distance(p2) == 1));
        CHECK((p1.distance(p3) == 2));
        CHECK((p2.distance(p3) == 3));
    }

    TEST_CASE("MoveTowards function") {

        double x1 = p1.moveTowards(p1,p4,2).getXCoordinate();
        double y1 = p1.moveTowards(p1,p4,2).getYCoordinate();
        CHECK(( x1 == p2.getXCoordinate() && y1 == p2.getYCoordinate() ));

        double x2 = p1.moveTowards(p1,p3,2).getXCoordinate();
        double y2 = p1.moveTowards(p1,p3,2).getYCoordinate();
        CHECK(( x1 == p3.getXCoordinate() && y1 == p3.getYCoordinate() ));

    }

}

TEST_SUITE("Cowboy class functions") {
    Point p1(0, 0), p2(0, 2), p3(0, -1),p4(5,10);
    Cowboy* cowboy1 = new Cowboy("cowboy1", p1);
    Cowboy* cowboy2 = new Cowboy("cowboy2", p2);
    Cowboy* cowboy3 = new Cowboy("cowboy3", p3);
    Ninja* enemy = new Ninja(5, "enemy", p4, 10);


    TEST_CASE("Distance function") {
        CHECK((cowboy1->distance(cowboy2) == 1));
        CHECK((cowboy1->distance(cowboy3) == 2));
        CHECK((cowboy2->distance(cowboy3) == 3));
    }

    TEST_CASE("Hit and isAlive functions") {
        int hitPoints = cowboy1->getHitPoints();
        cowboy1->hit(3); // cowboy1 has left 2 hit points
        CHECK((cowboy1->isAlive() == true));
        CHECK((cowboy1->getHitPoints() == (hitPoints - 3)));
        cowboy1->hit(2); // cowboy1 stay with no hit points
        CHECK((cowboy1->isAlive() == false));
        CHECK((cowboy1->getHitPoints() == (hitPoints - 5)));
    }

    TEST_CASE("Shoot , Hasboolets , and Reload functions") {
        cowboy1->shoot(enemy); // cowboy1 has left 5 balls
        CHECK((cowboy1->hasboolets() == true));
        for (int i = 1; i <= 5; ++i) {
            cowboy1->shoot(enemy);
        }
        CHECK((cowboy1->hasboolets() == false));// cowboy1 stay with no balls
        cowboy1->reload();
        CHECK((cowboy1->hasboolets() == true));
    }

}

TEST_SUITE("Ninja class and derived classes functions") {
    Point p1(0, 0), p2(0, 2), p3(0, -1),p4(0,15);
    OldNinja* oldNinja = new OldNinja("oldNinja",p1);
    YoungNinja* youngNinja = new YoungNinja("youngNinja",p2);
    TrainedNinja* trainedNinja = new TrainedNinja("trainedNinja",p3);
    Cowboy* enemy = new Cowboy("enemy",p4);
    Cowboy* enemy2 = new Cowboy("enemy2",p1);
    Cowboy* enemy3 = new Cowboy("enemy3",p2);

    TEST_CASE("Distance function") {
        CHECK((oldNinja->distance(youngNinja) == 1));
        CHECK((oldNinja->distance(trainedNinja) == 2));
        CHECK((youngNinja->distance(trainedNinja) == 3));
    }

    TEST_CASE("Hit and isAlive functions") {
        oldNinja->hit(100); // old ninja has left 50 hit points
        CHECK((oldNinja->isAlive() == true));
        oldNinja->hit(50); // old ninja stay with no hit points
        CHECK((oldNinja->isAlive() == false));

        youngNinja->hit(100); // young Ninja has left 50 hit points
        CHECK((youngNinja->isAlive() == true));
        youngNinja->hit(20); // young ninja stay with no hit points
        CHECK((youngNinja->isAlive() == false));

        trainedNinja->hit(80); // trained Ninja has left 50 hit points
        CHECK((trainedNinja->isAlive() == true));
        trainedNinja->hit(20); // trained ninja stay with no hit points
        CHECK((trainedNinja->isAlive() == false));
    }
    TEST_CASE("Move function") {
        int speed = oldNinja->getSpeed();
        Point& location = oldNinja->getLocation();
        oldNinja->move(enemy);
        Point& newLocation = oldNinja->getLocation();
        CHECK((location.distance(newLocation) == speed));

        int speed2 = youngNinja->getSpeed() ;
        Point& location2 = youngNinja->getLocation();
        oldNinja->move(enemy);
        Point& newLocation2 = youngNinja->getLocation();
        CHECK((location.distance(newLocation) == speed2));

        int speed3 = trainedNinja->getSpeed();
        Point& location3 = trainedNinja->getLocation();
        oldNinja->move(enemy);
        Point& newLocation3 = trainedNinja->getLocation();
        CHECK((location.distance(newLocation) == speed3));


    }

    TEST_CASE("Slash function") {
        oldNinja->slash(enemy); // The cowboy now has 70 hit points
        CHECK((enemy->isAlive() == true));
        oldNinja->slash(enemy); // The cowboy now has 30 hit points
        oldNinja->slash(enemy); // The cowboy now has -10 hit points
        CHECK((enemy->isAlive() == false));

        youngNinja->slash(enemy2); // The cowboy now has 70 hit points
        CHECK((enemy2->isAlive() == true));
        youngNinja->slash(enemy2); // The cowboy now has 30 hit points
        youngNinja->slash(enemy2); // The cowboy now has -10 hit points
        CHECK((enemy2->isAlive() == false));

        trainedNinja->slash(enemy3); // The cowboy now has 70 hit points
        CHECK((enemy->isAlive() == true));
        trainedNinja->slash(enemy3); // The cowboy now has 30 hit points
        trainedNinja->slash(enemy3); // The cowboy now has -10 hit points
        CHECK((enemy3->isAlive() == false));

    }

}



TEST_SUITE("Team class and derived classes functions") {
    Point p1(0,0), p2(1,0) , p3(3,0);
    Cowboy *cowboy1 = new Cowboy("cowboy1", p1);
    Cowboy *cowboy2 = new Cowboy("cowboy2", p1);
    OldNinja* oldNinja = new OldNinja("oldNinja",p1);
    YoungNinja* youngNinja = new YoungNinja("youngNinja",p2);
    TrainedNinja* trainedNinja = new TrainedNinja("trainedNinja",p3);

    Team team_A(cowboy1);
    Team2 team_B(oldNinja);
    SmartTeam team_C(youngNinja);

    TEST_CASE("Add function") {
        int size = team_A.getFighters().size();
        team_A.add(cowboy2);
        CHECK((size == 2)) ;
        team_A.add(oldNinja);
        team_A.add(youngNinja);
        team_A.add(trainedNinja);
        CHECK((size == 5)) ;
        for(int i=1; i<=5; i++)
            team_A.add(cowboy2);
        CHECK((size == 10)) ;
        CHECK_THROWS((team_A.add(cowboy2)));

    }

    TEST_CASE("Attack and StillAlive functions") {
        for (int i = 0; i < 10; ++i) {
            team_A.add(oldNinja);
            team_B.add(cowboy2);
            team_C.add(cowboy1);
        }

        for (int i = 0; i < 10; ++i)
            team_B.attack(&team_A);
        CHECK((team_A.stillAlive() == false));
        team_C.attack(&team_B);
        CHECK((team_B.stillAlive() == true));
        team_C.attack(&team_B);
        CHECK((team_A.stillAlive() == true));

    }

}