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

//this method will perform an A* search starting at the point given as an argument
//it will return a list of coordinate sets that form the path it uses.
//method is identical do BFSearch, as A* only differs in handling of its frontier
std::vector<std::vector<int>> AStar::AStarSearch(std::vector<int> start)
{
    //return if the goal is found
    if(fMap[start[0]][start[1]]==2)
    {
        fExplored.push_back(start);
        return fExplored;

    }
    //removes the first element of the frontier unless it's empty
    //prevents repeatedly searching the same point
    if (fFrontier.empty()==false) fFrontier.erase(fFrontier.begin());

    //expands the current point and adds the adjacent points to the
    //frontier to be explored
    this->addFrontier(start);
    //adds the current point to the list of points already explored
    fExplored.push_back(start);

    //iterates the algorithm until a goal is found
    return AStarSearch(fFrontier.front());
}

//differs from the simpleSearch in that it orders points by a heuristic
void AStar::addFrontier(std::vector<int> point)
{
    //No easy and clean way to iterate over the four adjacent points,
    //so done manually
    std::vector<int> next = {point[0]+1, point[1]};

    //checks that this neighbour is both within the map, hasn't already
    //been explored, and doesn't contain an obstacle
    if(inBounds(next)==true && isExplored(next)==false && inFrontier(next)==false
            && fMap[next[0]][next[1]] != 3)
    {
        tempFrontier.push_back(next);
        tempHeuristics.push_back(heuristic(next));
    }

    next[0] = point[0]; next[1] = point[1]+1;

    if(inBounds(next)==true && isExplored(next)==false && inFrontier(next)==false
            && fMap[next[0]][next[1]] != 3)
    {
        tempFrontier.push_back(next);
        tempHeuristics.push_back(heuristic(next));
    }

    next[0] = point[0]-1; next[1] = point[1];

    if(inBounds(next)==true && isExplored(next)==false && inFrontier(next)==false
            && fMap[next[0]][next[1]] != 3)
    {
        tempFrontier.push_back(next);
        tempHeuristics.push_back(heuristic(next));
    }

    next[0] = point[0]; next[1] = point[1]-1;

    if(inBounds(next)==true && isExplored(next)==false && inFrontier(next)==false
            && fMap[next[0]][next[1]] != 3)
    {
        tempFrontier.push_back(next);
        tempHeuristics.push_back(heuristic(next));
    }


    while(!tempFrontier.empty())
    {
        int min = INT_MAX;
        int minLoc = 0;
        for (int i=0; i<tempFrontier.size(); i++)
        {
            if (tempHeuristics[i]<min)
            {
                min = tempHeuristics[i];
                minLoc = i;
            }
        }
        fFrontier.push_back(tempFrontier[minLoc]);
        tempFrontier.erase(tempFrontier.begin()+minLoc);
        tempHeuristics.erase(tempHeuristics.begin()+minLoc);
    }

}


