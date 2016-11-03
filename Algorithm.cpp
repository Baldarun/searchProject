#include "Algorithm.h"

//default constructor
Algorithm::Algorithm()
{}

//argument toCheck is a coordinate point to check
//the inBounds method returns true if the point toCheck is within the map, false if it
//is not
bool Algorithm::inBounds(std::vector<int> toCheck)
{
    if(toCheck[0] >= fMap.size() || toCheck[1] >= fMap[0].size()){ return false;
    }else return true;
}

//argument toCheck is a coordinate point to check
//argument explored is the array of points the algorithm has visited
//returns true if the input point has already been explored (is already in the explored vector)
bool Algorithm::isExplored(std::vector<int> toCheck)
{
    for (int i=0; i<fExplored.size(); i++)
    {
        if(toCheck[0]==fExplored[i][0] && toCheck[1]==fExplored[i][1]) return true;
    }
    return false;
}

//findStart returns the coordinates that the start point is at within the map
std::vector<int> Algorithm::findStart()
{
    for(int i=0; i<fMap.size(); i++)
        for(int j=0; j<fMap[i].size(); j++)
        {
            if (fMap[i][j] == 1) return std::vector<int>{i, j};
        }
}

