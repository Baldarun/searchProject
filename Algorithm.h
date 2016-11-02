#ifndef ALGORITHM_H
#define ALGORITHM_H

#include <vector>
#include <iostream> //for testing



class Algorithm
{
public:
    Algorithm(); //constructor is unused

    //method declarations for .cpp large enough to warrant being there
    bool inBounds(std::vector<int> toCheck);
    bool isExplored(std::vector<int> toCheck);
    std::vector<int> findStart();

    //standard getters for class objects
    std::vector<std::vector<int>> getExplored()
    {
        return fExplored;
    }

    std::vector<std::vector<int>> getMap()
    {
        return fMap;
    }


    //objects declared as protected for inheritance
protected:
    //The 2D map
    std::vector<std::vector<int>> fMap;
    //the point the algorithm will start from. Generally defined by findStart
    std::vector<int> fStart;
    //a list of the coordinates the algorithm has already been to
    std::vector<std::vector<int>> fExplored;

};

#endif // ALGORITHM_H
