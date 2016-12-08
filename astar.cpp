#include "astar.h"

//default constructor uses a pre-defined 8x8 map
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

//functions identically to the Algorithm version, but with a frontier of hcoords rather than int vectors
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
//it will return a list of coordinate sets that are each point it expands.
//method is largely identical do BFSearch, as A* only differs in handling of its frontier
std::vector<std::vector<int>> AStar::AStarSearch(std::vector<int> start)
{
    //return if the goal is found
    if(fMap[start[0]][start[1]]==2)
    {
        //pushes this point to explored before returning the whole vector
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
    //oldest points in the frontier expanded, resulting in the frontier effectively being a queue
    //however the queue is sorted in the addFrontier method, so it is a priority queue
    return AStarSearch(fFrontier.front().getPoint());
}



//argument point is the point to be expanded
//this method adds all viable points from the four adjacent to the input to the frontier
//differs from the simpleSearch in that it includes a heuristic and sorts the frontier by it
void AStar::addFrontier(std::vector<int> point)
{
    //temporary objects used for sorting
    std::vector<hCoord> tempFront;
    std::vector<int> tempH;

    //No easy and clean way to iterate over the four adjacent points,
    //so done manually using a temporary object
    std::vector<int> next = {point[0]+1, point[1]};

    //checks that this neighbour is both within the map, hasn't already
    //been explored, and doesn't contain an obstacle
    if(inBounds(next) && !isExplored(next) && !inFrontier(next)
            && fMap[next[0]][next[1]] != 3)
    {
        //if these conditions are met it creates the hCoord for that point from the coordinates and heuristic value
        hCoord temp(next, heuristic(next));
        //this is pushed to the temporary frontier
        tempFront.push_back(temp);
        //then pushes the point and the point being expanded as a single vector to camefrom
        std::vector<int> tempCame{next[0], next[1], point[0], point[1]};
        fCameFrom.push_back(tempCame);
    }

    //does the same for each point
    next[0] = point[0]; next[1] = point[1]+1;

    if(inBounds(next) && !isExplored(next) && !inFrontier(next)
            && fMap[next[0]][next[1]] != 3)
    {
        hCoord temp(next, heuristic(next));
        tempFront.push_back(temp);
        std::vector<int> tempCame{next[0], next[1], point[0], point[1]};
        fCameFrom.push_back(tempCame);
    }

    next[0] = point[0]-1; next[1] = point[1];

    if(inBounds(next) && !isExplored(next) && !inFrontier(next)
            && fMap[next[0]][next[1]] != 3)
    {
        hCoord temp(next, heuristic(next));
        tempFront.push_back(temp);
        std::vector<int> tempCame{next[0], next[1], point[0], point[1]};
        fCameFrom.push_back(tempCame);
    }

    next[0] = point[0]; next[1] = point[1]-1;

    if(inBounds(next) && !isExplored(next) && !inFrontier(next)
            && fMap[next[0]][next[1]] != 3)
    {
        hCoord temp(next, heuristic(next));
        tempFront.push_back(temp);
        std::vector<int> tempCame{next[0], next[1], point[0], point[1]};
        fCameFrom.push_back(tempCame);
    }


    //the existing frontier is pushed into the temporary frontier
    for(int i=0; i<fFrontier.size(); i++)
    {
        tempFront.push_back(fFrontier[i]);
    }

    //the original frontier is then emptied
    fFrontier.clear();

    //heuristic values are taken from the temporary frontier and put into tempH
    for(int i=0; i<tempFront.size(); i++)
    {
        tempH.push_back(tempFront[i].getHeur());
    }

    //tempH can then be sorted into ascending order
    std::sort(tempH.begin(), tempH.end());

    //this loop pushes values from tempFront into fFrontier in the order they appear in tempH
    //it erases them from tempFront as it goes so as not to repeat itself
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


