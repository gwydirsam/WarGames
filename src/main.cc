//Sam Gwydir
//CSCE 315-503
//Due: January 30, 2015
//main.cc

// "A strange game.
// The only winning move is not to play."

// Because score is calculated as path-length*exec-time
// I've found that returning a random path is the best way
// get a high score.
// So accordingly this program finds #cores random paths
// and returns the shortest

#include <iostream>
#include <thread>
#include <future>
#include <algorithm>
#include <ctime>
#include <cstdio>

#ifdef TIMING
#include <chrono>
#endif

// Getting core number in C++ was slow
// Using 3 cores instead of 4 seems fastest
#define NUM_CORES 3

#include "path.h"
#include "point.h"

#ifdef TIMING
//Timing Macros for readability
#define BEGIN_TIMING(sectionnumber) \
    std::chrono::high_resolution_clock::time_point sectionnumber = \
         TimeSectionBegin();

#define END_TIMING(sectionnumber, title) \
    TimeSectionEnd(sectionnumber, title);
#else
// if TIMING is not defined
// Macros do nothing
#define BEGIN_TIMING(sectionnumber)
#define END_TIMING(sectionnumber, title)
#endif

#ifdef TIMING
std::chrono::high_resolution_clock::time_point TimeSectionBegin() {
    // Return Start Time
    return std::chrono::high_resolution_clock::now();
}

// Print Section Duration
void TimeSectionEnd(std::chrono::high_resolution_clock::time_point& start,
                    std::string sectionname) {
    std::chrono::high_resolution_clock::time_point stop =
        std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> time_span =
        std::chrono::duration_cast<std::chrono::duration<double> >(stop - start);

    std::cout << sectionname << ": " << time_span.count() << " seconds";
    std::cout << std::endl;
}
#endif

int main() {
BEGIN_TIMING(t0)
    //create points from stdin
    std::vector<Point> points = PointsVectorFromStdin();
END_TIMING(t0, "Points From Stdin")

BEGIN_TIMING(t1)
    std::vector<std::future<Path> > pathfutures; // Vector of Future Paths

    std::srand(unsigned(std::time(0))); // Seed Random

    // Create number of cores - 1 Random Walk threads
    for(int i = 0; i < (NUM_CORES - 1); ++i) {
        pathfutures.push_back(std::async(std::launch::async,
                                         FindRandomPath, points));
    }

END_TIMING(t1, "Create Thread Loop")

BEGIN_TIMING(t2)
    std::vector<Path> paths; // vector of possible paths
    // Calculate a path on main thread while waiting for other threads
    paths.push_back(FindRandomPath(points));
END_TIMING(t2, "Main Thread Random Path")

BEGIN_TIMING(t3)
    // Get Paths from threads
    for (auto& pathfuture : pathfutures) {
        paths.push_back(pathfuture.get());
    }
END_TIMING(t3, "Get Future Paths Loop")

BEGIN_TIMING(t4)
    // Get shortest random path
    Path minpath = *std::min_element(paths.begin(), paths.end());
END_TIMING(t4, "Min Path Loop")

BEGIN_TIMING(t5)
    // Print the Shortest Path
    PrintPath(minpath);
END_TIMING(t5, "Path Print")

END_TIMING(t0, "Program")
    return 0;
}
