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
int AStar::heuristic(std::vector<int> point)
{
    return abs(point[0]-fGoal[0]) + abs(point[1] - fGoal[1]);
}

bool AStar::inFrontier(std::vector<int> toCheck)
{
    for (int i=0; i<fFrontier.size(); i++)
    {
        if(toCheck[0]==fFrontier[i].getPoint()[0] &&
                toCheck[1]==fFrontier[i].getPoint()[1]) return true;
    }
    return false;
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
        fFrontier.clear();
        fGoal.clear();
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
    return AStarSearch(fFrontier.front().getPoint());
}


//differs from the simpleSearch in that it includes a heuristic value
void AStar::addFrontier(std::vector<int> point)
{
    std::vector<hCoord> tempFront;
    std::vector<int> tempH;

    //No easy and clean way to iterate over the four adjacent points,
    //so done manually
    std::vector<int> next = {point[0]+1, point[1]};

    //checks that this neighbour is both within the map, hasn't already
    //been explored, and doesn't contain an obstacle
    if(inBounds(next) && !isExplored(next) && !inFrontier(next)
            && fMap[next[0]][next[1]] != 3)
    {
        hCoord temp(next, heuristic(next));
        tempFront.push_back(temp);
    }

    next[0] = point[0]; next[1] = point[1]+1;

    if(inBounds(next) && !isExplored(next) && !inFrontier(next)
            && fMap[next[0]][next[1]] != 3)
    {
        hCoord temp(next, heuristic(next));
        tempFront.push_back(temp);
    }

    next[0] = point[0]-1; next[1] = point[1];

    if(inBounds(next) && !isExplored(next) && !inFrontier(next)
            && fMap[next[0]][next[1]] != 3)
    {
        hCoord temp(next, heuristic(next));
        tempFront.push_back(temp);
    }

    next[0] = point[0]; next[1] = point[1]-1;

    if(inBounds(next) && !isExplored(next) && !inFrontier(next)
            && fMap[next[0]][next[1]] != 3)
    {
        hCoord temp(next, heuristic(next));
        tempFront.push_back(temp);
    }


    for(int i=0; i<fFrontier.size(); i++)
    {
        tempFront.push_back(fFrontier[i]);
    }

    fFrontier.clear();

    for(int i=0; i<tempFront.size(); i++)
    {
        tempH.push_back(tempFront[i].getHeur());
    }

    std::sort(tempH.begin(), tempH.end());

    for(int i=0; i<tempH.size(); i++)
    {
        for(int j=0; j<tempFront.size(); j++)
        {
            if(tempH[i]==tempFront[j].getHeur())
            {
                fFrontier.push_back(tempFront[j]);
                tempFront.erase(tempFront.begin()+j);

            }
        }
    }
    tempFront.clear();
    tempH.clear();

}


