#ifndef MAPMAKER_H
#define MAPMAKER_H

#include <vector>
#include <stdlib.h>
#include <time.h>


class MapMaker
{
public:
    //default constructor
    MapMaker();

    //arguments constructor
    MapMaker(int xSize, int ySize, int percentWall);

    //getter methods
    std::vector<int> getSize()
    {
        std::vector<int> size = {fXSize, fYSize};
        return size;
    }

    int getPercentWall(){

        return fPercentWall;
    }

    std::vector<std::vector<int>> getMap()
    {
        return fMap;
    }

    void setMap(std::vector<std::vector<int>> map)
    {
        fMap = map;
    }

    //declaration of the method that initialises the map which will then be cleaned up
    void intitialise();

private:

    //the horizontal and vertical size of the map
    int fXSize;
    int fYSize;

    //the percentage of the map that should be obstacle
    int fPercentWall;

    //the map
    std::vector<std::vector<int>> fMap;

};

#endif // MAPMAKER_H
