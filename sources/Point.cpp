//
// Created by ofir on 5/1/23.
//

#include "Point.hpp"

using namespace ariel;
using namespace std;

double Point::distance(Point other) {
    return 0;
}

void Point::print() {

}

Point Point::moveTowards(Point &src, Point &dest, int distance) {
    return Point(0, 0);
}

std::ostream &ariel::operator<<(ostream &ostr, const Point &point) {
    return ostr;
}

double Point::getXCoordinate() const {
    return this->x_coordinate;
}

double Point::getYCoordinate() const {
    return this->y_coordinate;
}




