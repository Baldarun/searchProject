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

//findGoal returns the coordinates that the goal point is at within the map
std::vector<int> AStar::findGoal()
{
    for(int i=0; i<fMap.size(); i++)
        for(int j=0; j<fMap[i].size(); j++)
        {
            if (fMap[i][j] == 2) return std::vector<int>{i, j};
        }
}

bool AStar::inFrontier(std::vector<int> toCheck)
{
    for (int i=0; i<fFrontier.size(); i++)
    {
        if(toCheck[0]==fFrontier[i].getPoint()[0] && toCheck[1]==fFrontier[i].getPoint()[1]) return true;
    }
    return false;
}


int AStar::maxFHeur()
{
    int max = INT_MIN;
    if(!fFrontier.empty())
    {
        for(int i=0; i<fFrontier.size(); i++)
        {
            if(heuristic(fFrontier[i].getPoint()) > max) max = heuristic(fFrontier[i].getPoint());
        }
    }
    return max;
}

std::vector<hCoord> AStar::sortFrontier()
{
    /*
    int i, j, k;
    for(k=0; k<fFrontier.size(); k++)
    {
        tempH.push_back(fFrontier[k].getHeur());

    }
    tempH.push_back(2);

    std::sort(tempH.begin(), tempH.end());

    try
    {
        for(i=0; i<tempH.size(); i++)
                {
                    for(j=0; j<fFrontier.size(); j++)
                    {
                        std::cout << i << " " << j << " " << k << "\n";
                        if(tempH[i]==fFrontier[j].getHeur())
                        {
                            tempFront.push_back(fFrontier[j]);
                        }
                    }
                }
                fFrontier.clear();
                fFrontier.swap(tempFront);
                tempH.clear();
                tempFront.clear();
    }
    catch(std::bad_alloc& ba)
    {
        std::cout << i << " " << j << "\n";
        throw std::bad_alloc();
    }
*/
    tempH.clear();
    tempFront.clear();

    for(int i=0; i<fFrontier.size(); i++)
    {
        tempH.push_back(fFrontier[i].getHeur());
        std::cout << tempH[i] << " " << fFrontier[i].getHeur() << "\n";
        //std::cout << "fucky: " << fFrontier.size() << " " << fFrontier[i].getHeur() << "\n";

    }
    std::sort(tempH.begin(), tempH.end());

    for(int i=0; i< tempH.size(); i++)
    {
        //std::cout << tempH[i] << " ";
    }
    //std::cout << "\n";

    for(int i=0; i<tempH.size(); i++)
    {
        for(int j=0; j<fFrontier.size(); j++)
        {
            if(tempH[i]==fFrontier[j].getHeur())
            {
                //std::cout << "yes" << "\n";
                tempFront.push_back(fFrontier[j]);

            }
        }
    }

    for(int i=0; i< tempFront.size(); i++)
    {
        std::cout << tempFront[i].getHeur() << " ";
    }
    std::cout << "\n";

    std::cout << fFrontier.size() << "\n";


    for(int i=0; i< fFrontier.size(); i++)
    {
        std::cout << fFrontier[i].getHeur() << " ";
    }
    //std::cout << "\n";

    return tempFront;

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

    std::vector<hCoord> dummy = this->sortFrontier();
    fFrontier.swap(dummy); //Something goes horribly wrong exactly here. Not sure why
    dummy.clear();

    //adds the current point to the list of points already explored
    fExplored.push_back(start);

    //iterates the algorithm until a goal is found
    return AStarSearch(fFrontier.front().getPoint());
}


//differs from the simpleSearch in that it includes a heuristic value
void AStar::addFrontier(std::vector<int> point)
{
    //std::vector<hCoord> tempFrontier;

    //No easy and clean way to iterate over the four adjacent points,
    //so done manually
    std::vector<int> next = {point[0]+1, point[1]};

    //checks that this neighbour is both within the map, hasn't already
    //been explored, and doesn't contain an obstacle
    if(inBounds(next) && !isExplored(next) && !inFrontier(next)
            && fMap[next[0]][next[1]] != 3)
    {
        hCoord temp(next, heuristic(next));
        fFrontier.push_back(temp);
    }

    next[0] = point[0]; next[1] = point[1]+1;

    if(inBounds(next) && !isExplored(next) && !inFrontier(next)
            && fMap[next[0]][next[1]] != 3)
    {
        hCoord temp(next, heuristic(next));
        fFrontier.push_back(temp);
    }

    next[0] = point[0]-1; next[1] = point[1];

    if(inBounds(next) && !isExplored(next) && !inFrontier(next)
            && fMap[next[0]][next[1]] != 3)
    {
        hCoord temp(next, heuristic(next));
        fFrontier.push_back(temp);
    }

    next[0] = point[0]; next[1] = point[1]-1;

    if(inBounds(next) && !isExplored(next) && !inFrontier(next)
            && fMap[next[0]][next[1]] != 3)
    {
        hCoord temp(next, heuristic(next));
        fFrontier.push_back(temp);
    }

/*
    while(!tempFrontier.empty())
    {
        int max = INT_MIN;
        for (int i=0; i<tempFrontier.size(); i++)
        {
            if (tempFrontier[i].getHeur()>=max)
            {
                max = i;

            }
        }

        fFrontier.push_back(tempFrontier[max]);
        tempFrontier.erase(tempFrontier.begin()+max);

    }
*/
}


