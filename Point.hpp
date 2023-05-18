#ifndef POINT_HPP
#define POINT_HPP
namespace ariel{

class Point {
    double cordX;
    double cordY;

    public:

    Point(double cordX,double cordY);
    Point(Point other);
    double distance(Point other);
    string print();
    Point moveTowards(Point src, Point dst, double distance);
    double getX();
    double getY();

};
}
#endif