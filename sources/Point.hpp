#ifndef POINT_HPP
#define POINT_HPP

using namespace std;
namespace ariel{

class Point {
    double cordX;
    double cordY;

    public:

    Point(double cordX,double cordY);
    Point(Point const & other);
    double distance(Point other);
    string print();
    Point moveTowards(Point src, Point dst, double distance);
    double getX();
    double getY();

};
}
#endif