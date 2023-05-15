#ifndef POINT_HPP
#define POINT_HPP
namespace ariel{

class Point {
    double cordX;
    double cordY;

    public:

    Point(double cordX,double cordY);
    double distance(Point other);
    void print();
    Point moveTowards(Point src, Point dst, double distance);
    double getX();
    double getY();

};
}
#endif