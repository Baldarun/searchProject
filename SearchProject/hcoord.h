#ifndef HCOORD_H
#define HCOORD_H

#include <vector>


class hCoord
{
public:
    //This class exists as a way to intrinsically link coordinates and heuristic values for the A* search
    hCoord(std::vector<int> point, int val);

    //getters for the two variables
    std::vector<int> getPoint()
    {
        return fPoint;
    }

    int getVal()
    {
        return fVal;
    }


private:

    std::vector<int> fPoint; //coordinate
    int fVal; //associated value
};

#endif // HCOORD_H
