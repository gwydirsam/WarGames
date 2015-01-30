//Sam Gwydir
//CSCE 315-503
//Due: January 30, 2015
//point.cc

#include "point.h"

#include <cstdio>

#include <cmath>
#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>

std::ostream& operator<<(std::ostream& os, const Point& point) {
    os << "(" << point.x_ << "," << point.y_ << ")";
    return os;
}

double EuclideanDistance(Point p, Point q) {
    return sqrt(pow((p.x() - q.x()),2) + pow((p.y() - q.y()),2));
}

std::vector<Point> PointsVectorFromStdin() {
    std::vector<Point> points;

    // Make cin faster by not syncing buffers
    std::ios_base::sync_with_stdio (false);

    //read file from stdin
    const int buffersize = 128;
    char line[buffersize];
    while(std::fgets(line, buffersize, stdin) != NULL) {
        int x, y;
        if(line[0] != '#') {
            std::sscanf(line, "%d %d", &x, &y);
            points.push_back(Point(x,y));
        }
    }
#ifdef VERBOSE
    // Print points vector
    for (int i = 0; i < points.size(); ++i) {
        std::cout << points[i] << std::endl;
    }
#endif
    return points;
}
