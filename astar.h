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

    //declares the primary method of the class; the A*-search algorithm
    std::vector<std::vector<int>> AStarSearch(std::vector<int> start);

    //declares a method A* search is dependent on, and efficient to seperate;
    //the heuristic calculator, which calculates the distance between a point and the goal
    int heuristic(std::vector<int> point);

    bool inFrontier(std::vector<int>);

    //method to add values to the frontier
    void addFrontier(std::vector<int>);


private:

    std::vector<hCoord> fFrontier;

    //std::vector<int> tempH;
    //std::vector<hCoord> tempFront;

};

#endif // ASTAR_H
