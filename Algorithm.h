#ifndef ALGORITHM_H
#define ALGORITHM_H

#include <vector>

#include <iostream> //for testing



class Algorithm
{
public:
    Algorithm(); //constructor is unused

    //method declarations for methods that check things. Details in .cpp
    bool inBounds(std::vector<int> toCheck);
    bool isExplored(std::vector<int> toCheck);
    std::vector<int> findStart();

    //clears the list of explored points
    void clearExplored()
    {
        fExplored.clear();
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

    void setMap(std::vector<std::vector<int>> map)
    {
        fMap.swap(map);
    }

    void setStart(std::vector<int> start)
    {
        fStart = start;
    }


//objects declared as protected for inheritance
protected:
    //The 2D map
    std::vector<std::vector<int>> fMap;
    //the point the algorithm will start from. Generally defined by findStart
    std::vector<int> fStart;
    //a list of the points that the algorithm has already expanded
    std::vector<std::vector<int>> fExplored;


};

#endif // ALGORITHM_H
