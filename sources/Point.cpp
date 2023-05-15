#include "Point.hpp"
#include <iostream>
#include <cmath>

using namespace std;
using namespace ariel; 

    Point::Point(double cordX, double cordY) : cordX(cordX), cordY(cordY) {}

    double Point::distance(Point other) {
        double dx = cordX - other.getX();
        double dy = cordY - other.getY();
        return sqrt(dx * dx + dy * dy);
    }

    void Point::print() {
        std::cout << "(" << cordX << ", " << cordY << ")" << std::endl;
    }

    Point Point::moveTowards(Point src, Point dst, double distance) {
        // double dx = dst.getX() - src.getX();
        // double dy = dst.getY() - src.getY();
        // double currentDistance = sqrt(dx * dx + dy * dy);
        // double ratio = distance / currentDistance;
        // double newX = src.getX() + ratio * dx;
        // double newY = src.getY() + ratio * dy;
        // return Point(newX, newY);
        return Point(0,0);
    }

    double Point::getX() {
        return cordX;
    }

    double Point::getY() {
        return cordY;
    }


