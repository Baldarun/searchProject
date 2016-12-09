#include "Algorithm.h"

//default constructor. Goes unused.
Algorithm::Algorithm()
{}

//argument toCheck is a coordinate point to check
//the inBounds method returns true if the point toCheck is within the map, false if it is not
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

//findGoal returns the coordinates that the goal point is at within the map
std::vector<int> Algorithm::findGoal()
{

    for(int i=0; i<fMap.size(); i++)
        for(int j=0; j<fMap[i].size(); j++)
        {
            if (fMap[i][j] == 2)
            {
                return std::vector<int>{i, j};
            }
        }
}

//argument toCheck is a coordinate point to check
//returns true if this point is in the frontier, false if it isn't
bool Algorithm::inFrontier(std::vector<int> toCheck)
{
    for (int i=0; i<fFrontier.size(); i++)
    {
        if(toCheck[0]==fFrontier[i][0] && toCheck[1]==fFrontier[i][1]) return true;
    }
    return false;
}

//argument point is typically inputted as the finishing/goal point of the search, and is then used for recursive calls
//this method returns the path between goal and start found by an algorithm, after recursively assembling it
std::vector<std::vector<int>> Algorithm::findPath(std::vector<int> point)
{
    //finishing point for the algorithm when it gets back to the start
    if(point[0]==fStart[0] && point[1]==fStart[1])
    {
        //final point is pushed to the vector
        fPath.push_back(fStart);
        //returns the complete path
        return fPath;
    }
    else{
        //for every point before the finish
        for(int i=0; i<fCameFrom.size(); i++)
            //search the CameFrom array for this point
            if (fCameFrom[i][0] == point[0] && fCameFrom[i][1] == point[1])
            {
                //push it to the vector
                fPath.push_back(point);
                //find the corresponding point in the camefrom vector that this point was expanded from and assemble it as a temporary object
                std::vector<int> temp{fCameFrom[i][2], fCameFrom[i][3]};
                //erase that entry from camefrom so it isn't referenced again
                //prevents infinite loops
                fCameFrom.erase(fCameFrom.begin()+i);
                //recursively calls this method with the point
                return findPath(temp);
                //doing this will work its way back through each point and its previous one until the method goes from finish to start
            }
    }
}
