#ifndef ASTAR_H
#define ASTAR_H
#include <algorithm.h>
//#include <math.h>
//#include <climits>

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

    //declares method to find the coordinates of the objective in a map
    std::vector<int> findGoal();

    //method to add values to the frontier
    void addFrontier(std::vector<int>);

private:
    //due to using heuristic, A* uniquely needs to store the goal
    std::vector<int> fGoal;

    std::vector<int> tempHeuristics;

    std::vector<std::vector<int>> tempFrontier;

};

#endif // ASTAR_H
