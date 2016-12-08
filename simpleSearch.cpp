#include "simpleSearch.h"

//default constructor uses a pre-defined 8x8 map
SimpleSearch::SimpleSearch()
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
SimpleSearch::SimpleSearch(std::vector<std::vector<int>> map)
{
    fMap = map;
    fStart = this->findStart();
    fGoal = this->findGoal();
}

//this method will perform a depth first search starting at the point given as an argument
//it will return a list of coordinate sets that are each point it expands.
std::vector<std::vector<int>> SimpleSearch::DFSearch(std::vector<int> start)
{
    //return if the goal is found
    if(fMap[start[0]][start[1]]==2)
    {
        //pushes this point to explored before returning the whole vector
        fExplored.push_back(start);
        return fExplored;
    }

    //removes the last element of the frontier unless it's empty
    //prevents repeatedly searching the same point
    if (fFrontier.empty()==false) fFrontier.erase(fFrontier.end());

    //expands the current point and adds the adjacent points to the
    //frontier to be explored
    this->addFrontier(start);

    //adds the current point to the list of points already explored
    fExplored.push_back(start);

    //iterates the algorithm until a goal is found
    //most recently added point is used, resulting in the frontier vector effectively being a stack
    return DFSearch(fFrontier.back());

}

//this method will perform a breadth first search starting at the point given as an argument
//it will return a list of coordinate sets that are each point it expands.
//method is identical do DFSearch, though using queue logic rather than stack logic
std::vector<std::vector<int>> SimpleSearch::BFSearch(std::vector<int> start)
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
    return BFSearch(fFrontier.front());

}

//argument point is the point to be expanded
//this method adds all viable points from the four adjacent to the input to the frontier
void SimpleSearch::addFrontier(std::vector<int> point)
{
    //No easy and clean way to iterate over the four adjacent points
    //so done manually using a temporary object
    std::vector<int> next = {point[0]+1, point[1]};

    //checks that this neighbour is both within the map, hasn't already
    //been explored, and doesn't contain an obstacle
    if(inBounds(next) && !isExplored(next) && !inFrontier(next)
            && fMap[next[0]][next[1]] != 3)
    {
        //if these conditions are met it pushes it to the frontier
        fFrontier.push_back(next);
        //then pushes the point and the point being expanded as a single vector to camefrom
        std::vector<int> tempCame{next[0], next[1], point[0], point[1]};
        fCameFrom.push_back(tempCame);
    }

    //does the same for each point
    next[0] = point[0]; next[1] = point[1]+1;

    if(inBounds(next) && !isExplored(next) && !inFrontier(next)
            && fMap[next[0]][next[1]] != 3)
    {
        fFrontier.push_back(next);
        std::vector<int> tempCame{next[0], next[1], point[0], point[1]};
        fCameFrom.push_back(tempCame);
    }

    next[0] = point[0]-1; next[1] = point[1];

    if(inBounds(next) && !isExplored(next) && !inFrontier(next)
            && fMap[next[0]][next[1]] != 3)
    {
        fFrontier.push_back(next);
        std::vector<int> tempCame{next[0], next[1], point[0], point[1]};
        fCameFrom.push_back(tempCame);
    }

    next[0] = point[0]; next[1] = point[1]-1;

    if(inBounds(next) && !isExplored(next) && !inFrontier(next)
            && fMap[next[0]][next[1]] != 3)
    {
        fFrontier.push_back(next);
        std::vector<int> tempCame{next[0], next[1], point[0], point[1]};
        fCameFrom.push_back(tempCame);
    }
}

