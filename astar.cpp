#include "astar.h"

//default constructor uses a pre-defined map
AStar::AStar()
{
    fMap = {{0, 0, 0, 0, 0, 0, 1, 0},
            {0, 3, 3, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 3, 0, 0, 0},
            {0, 0, 0, 0, 3, 0, 3, 0},
            {0, 0, 0, 0, 3, 0, 0, 0},
            {0, 0, 3, 0, 3, 0, 0, 0},
            {0, 0, 2, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0}};

    fStart = this->findStart();
    fGoal = this->findGoal();
}

//constructor that would take an input vector to use as the map
AStar::AStar(std::vector<std::vector<int>> map)
{
    fMap = map;
    fStart = this->findStart();
    fGoal = this->findGoal();
}

//implementation of heristic. Takes any given coordinate point as input
//returns the sum of the vertical and horizontal distance between that point and the goal
AStar::heuristic(std::vector<int> point)
{
    return abs(point[0]-fGoal[0]) + abs(point[1] - fGoal[1]);
}

//findGoal returns the coordinates that the goal point is at within the map
std::vector<int> AStar::findGoal()
{
    for(int i=0; i<fMap.size(); i++)
        for(int j=0; j<fMap[i].size(); j++)
        {
            if (fMap[i][j] == 2) return std::vector<int>{i, j};
        }
}

std::vector<std::vector<int>> AStar::AStarSearch()
{

}
