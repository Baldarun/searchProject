#ifndef ASTAR_H
#define ASTAR_H

#include <algorithm.h>
#include <hcoord.h>
#include <algorithm>
#include <math.h>

//child class of Algorithm
class AStar: public Algorithm
{
public:

    //declares a default (no arguments) constuctor
    AStar();

    //declares a constructor that allows the user to manually input a map
    AStar(std::vector<std::vector<int>> map);

    //declares the primary method of the class; the A* search algorithm
    std::vector<std::vector<int>> AStarSearch(std::vector<int> start);

    //declares a method A* search is dependent on, and efficient to seperate
    //the heuristic calculator, which calculates the manhattan distance between a point and the goal
    int heuristic(std::vector<int> point);

    //overrides the Algorithm method as a different frontier is used, which must be accessed differently
    bool inFrontier(std::vector<int> toCheck);

    //method to add values to the frontier
    void addFrontier(std::vector<int> point);


private:

    //A* uses hCoords rather than integer vectors, so has its own fFrontier
    std::vector<hCoord> fFrontier;
};

#endif // ASTAR_H
