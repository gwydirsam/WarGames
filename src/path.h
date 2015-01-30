//Sam Gwydir
//CSCE 315-503
//Due: January 30, 2015
//path.h

#ifndef HAROLD_HILL_GRAPH_PATH_H_
#define HAROLD_HILL_GRAPH_PATH_H_

#include <iosfwd>
#include <vector>

#include "point.h"

// A vertex is just an int
typedef int Vertex;

// A list of Vertices that form a Hamiltonian cycle
class Path {
public:
    Path(): length_(0) {}

    std::vector<Vertex> path() {return path_;}
    void set_path(std::vector<Vertex> path) {path_ = path;}

    double length() const {return length_;};
    void set_length(double length) {length_ = length;};

    // Size is the size of the vector path_, not the length of the path
    int size() const {return path_.size();}

    void insert(Vertex vertex) {path_.push_back(vertex);}

    friend std::ostream& operator<<(std::ostream& os, const Path& path);

    // A path is less than another if it's length is less
    bool operator<(const Path& path) const {
        return length_ < path.length_;
    }

    // The sum of the weights along the path
    double length_;
    std::vector<Vertex> path_;
};

Path FindRandomPath(const std::vector<Point>& points);
void PrintPath(const Path& path);

#endif // HAROLD_HILL_GRAPH_PATH_H_
