#include "Point.hpp"
#include <iostream>
#include <cmath>

using namespace std;
using namespace ariel; 

    Point::Point(double cordX, double cordY) : cordX(cordX), cordY(cordY) {}

    Point::Point(Point const & other) : cordX(other.cordX), cordY(other.cordY) {}

    double Point::distance(Point other) {
        double dx = cordX - other.getX();
        double dy = cordY - other.getY();
        return sqrt(dx * dx + dy * dy);
    }

    string Point::print() const{
        return "(" + to_string(cordX) + ", " + to_string(cordY) + ")";
    }


    Point  Point::moveTowards(Point src, Point dst, double distance){
    if (distance<0) throw invalid_argument("distance cannot be smaller than 0");
    double dx = dst.getX() - src.getX();
    double dy = dst.getY() - src.getY();
    double currentDistance = sqrt(dx * dx + dy * dy);
    if (currentDistance <= distance) 
        return dst;
    double ratio = distance / currentDistance;
    double newX =src.getX() + ratio * dx;
    double newY =src.getY() + ratio * dy;
    
    return Point(newX, newY);
    
}
    

    double Point::getX() {
        return cordX;
    }

    double Point::getY() {
        return cordY;
    }


