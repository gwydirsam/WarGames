//Sam Gwydir
//CSCE 315-503
//Due: January 30, 2015
//path.cc

#include "path.h"

#include <iostream>
#include <algorithm>

#include "point.h"

std::ostream& operator<<(std::ostream& os, const Path& path) {
    for (int i = 0; i < path.size(); ++i) {
        os << path.path_[i] << std::endl;
    }

    os << path.length_ << std::endl;
    return os;
}

Path FindRandomPath(const std::vector<Point>& points) {
    // Create Empty Path
    Path path;

    // Add Vertexes to path
    for (Vertex i = 0; i < points.size(); ++i) {
        path.insert(i);
    }

    // add return to 0
    path.insert(0);

    // Randomize path between first vertex and last
    std::random_shuffle(path.path_.begin() + 1, path.path_.end() - 1);

    // calculate and set the length of the path
    for (int i = 0; i < (path.size() - 1); ++i) {
        // Increment Length by Euclidean Distance from Vertex i to i + 1
        path.length_ +=
            EuclideanDistance(points[path.path_[i]],points[path.path_[i+1]]);
    }

    return path;
}

void PrintPath(const Path& path) {
    // Using C printf because cout is slow
    for (int i = 0; i < path.size(); ++i) {
        printf("%d\n",path.path_[i]);
    }

    printf("%f\n",path.length_);
}
