#ifndef ALGORITHM_H
#define ALGORITHM_H

#include <vector>

//parent class for searches and maps. Designed to be versatile so more can be added easily
//contains methods and variables used pretty universally by search algorithms
class Algorithm
{
public:
    Algorithm(); //constructor is unused

    //method to check if a given point is within the object's map
    bool inBounds(std::vector<int> toCheck);

    //method to check if a given point is within the object's explored vector
    bool isExplored(std::vector<int> toCheck);

    //method that will return the location of fStart.
    //Useful due to Algorithm objects often being created procedurally rather than manually
    std::vector<int> findStart();

    //method to check if a given vector is within the object's frontier
    //declared virtual because a class that instead uses hCoords will override
    virtual bool inFrontier(std::vector<int> toCheck);

    //declares method to find the coordinates of the objective in a map
    std::vector<int> findGoal();

    //method to find the path from start to finish
    std::vector<std::vector<int>> findPath(std::vector<int> point);

    //clears the list of explored points, the path found, and the frontier
    void clearAll()
    {
        fExplored.clear();
        fPath.clear();
        fFrontier.clear();
    }

    //standard getters for class objects
    std::vector<std::vector<int>> getExplored()
    {
        return fExplored;
    }

    std::vector<std::vector<int>> getMap()
    {
        return fMap;
    }

    std::vector<int> getStart()
    {
        return fStart;
    }

    std::vector<int> getGoal()
    {
        return fGoal;
    }

    std::vector<std::vector<int>> getPath()
    {
        return fPath;
    }

    void setMap(std::vector<std::vector<int>> map)
    {
        fMap.swap(map); //swap used to replace old map. = can add on top of it instead
    }

    void setStart(std::vector<int> start)
    {
        fStart.swap(start);
    }

    void setGoal(std::vector<int> goal)
    {
        fGoal.swap(goal);
    }


//objects declared as protected for inheritance
protected:
    //The 2D map
    std::vector<std::vector<int>> fMap;

    //the point the algorithm will start from. Generally defined by findStart
    std::vector<int> fStart;

    //a list of the points that the algorithm has already expanded
    std::vector<std::vector<int>> fExplored;

    //A vector of points to expand. Treated such that it functions as a queue or stack
    //these data types were not used due to the GUI's need to access elements without popping them
    std::vector<std::vector<int>> fFrontier;

    //Point that marks the goal on the map
    std::vector<int> fGoal;

    //vector linking each coordinate to the one that it was expanded from
    //intended to take 4d vectors with points of each point and its parent
    std::vector<std::vector<int>> fCameFrom;

    //the path between start and goal
    std::vector<std::vector<int>> fPath;

};

#endif // ALGORITHM_H
