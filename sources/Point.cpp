//
// Created by ofir on 5/1/23.
//

#include "Point.hpp"
#include <cmath>
#include <iomanip>

using namespace ariel;
using namespace std;

double Point::distance(Point other) const {
    double dx = this->getXCoordinate() - other.getXCoordinate();
    double dy = this->getYCoordinate() - other.getYCoordinate();
    double result = sqrt(dx * dx + dy * dy);
    return result;
}

void Point::print() const{
    cout << "(" << x_coordinate << ", " << y_coordinate << ")" << endl;
}

Point Point::moveTowards(Point &src, Point &dest, double distance) {
    if (distance < 0) throw invalid_argument("Distance cant be negative");
    // Calculate the distance between the source and destination points
    double dist = src.distance(dest);

    // If the distance is less than or equal to the maximum distance, the destination point is the closest point
    if (dist <= distance) {
        return dest;
    }

    // Otherwise, we need to find the point on the line between the source and destination points
    // that is at most the maximum distance away from the source point
    double ratio = distance / dist;
    double x = src.getXCoordinate() + (dest.getXCoordinate() - src.getXCoordinate()) * ratio;
    double y = src.getYCoordinate() + (dest.getYCoordinate() - src.getYCoordinate()) * ratio;

    Point closetPoint(x,y);
    return closetPoint;
}


double Point::getXCoordinate() const {
    return this->x_coordinate;
}

double Point::getYCoordinate() const {
    return this->y_coordinate;
}




