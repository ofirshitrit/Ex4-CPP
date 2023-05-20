//
// Created by ofir on 5/1/23.
//

#ifndef EX4_CPP_POINT_HPP
#define EX4_CPP_POINT_HPP
#include <iostream>

namespace ariel {
    class Point {
    private:
        double x_coordinate;
        double y_coordinate;
    public:
        Point(double x , double y) : x_coordinate(x) , y_coordinate(y){}
        ~Point() = default;
        double distance(Point other) const;
        void print() const;
        static Point moveTowards(Point& src , Point& dest, double distance) ;
        double getXCoordinate() const;
        double getYCoordinate() const;
    };
}



#endif //EX4_CPP_POINT_HPP
