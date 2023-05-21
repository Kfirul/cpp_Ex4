#ifndef POINT_HPP
#define POINT_HPP
#include <string>
using namespace std;
namespace ariel{

class Point {
    double cordX;
    double cordY;

    public:

    Point(double cordX,double cordY);
    double distance(Point other);
    string print() const;
    static Point moveTowards(Point src, Point dst, double distance);
    double getX();
    double getY();

};
}
#endif