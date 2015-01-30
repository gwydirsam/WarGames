//Sam Gwydir
//CSCE 315-503
//Due: January 30, 2015
//point.h

#ifndef HAROLD_HILL_GRAPH_POINT_H_
#define HAROLD_HILL_GRAPH_POINT_H_

#include <iosfwd>
#include <vector>

class Point {
public:
    Point() {};
    Point(int x, int y): x_(x), y_(y) {}

    int x() const {return x_;}
    int y() const {return y_;}

    friend std::ostream& operator<<(std::ostream& os, const Point& point);
private:
    int x_;
    int y_;
};

double EuclideanDistance(Point p, Point q);
std::vector<Point> PointsVectorFromStdin();

#endif // HAROLD_HILL_GRAPH_POINT_H_
