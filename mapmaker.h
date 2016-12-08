#ifndef MAPMAKER_H
#define MAPMAKER_H

#include <algorithm.h>
#include <vector>
#include <stdlib.h>
#include <time.h>

//inherits from Algorithm to use the same map objects
class MapMaker: public Algorithm
{
public:
    //default constructor
    MapMaker();

    //arguments constructor
    //allows custom size and initial obstacle percentage
    MapMaker(int xSize, int ySize, int percentWall);

    //getter adn setter methods
    std::vector<int> getSize()
    {
        std::vector<int> size = {fXSize, fYSize};
        return size;
    }

    int getPercentWall(){

        return fPercentWall;
    }

    //declaration of the method that calls the procedural generation effect
    void intitialise();

private:

    //the horizontal and vertical size of the map
    int fXSize;
    int fYSize;

    //the percentage of the map that should initially be obstacle
    int fPercentWall;

};

#endif // MAPMAKER_H
