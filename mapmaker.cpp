#include "mapmaker.h"

MapMaker::MapMaker()
{
    //default values initialsied
    fXSize = 30;
    fYSize = 30;
    fPercentWall = 45;

    //the initialise function initialises fMap with randomly added obstacles
    this->intitialise();
}

MapMaker::MapMaker(int xSize, int ySize, int percentWall)
{
    fXSize = xSize;
    fYSize = ySize;
    fPercentWall = percentWall;
    this->intitialise();
}

void MapMaker::intitialise()
{
    //intitialise random numbers using time as the seed
    srand (time(NULL));
    int random;

    //to initialise fMap, filled to full size with vectors of 0
    std::vector<int> empty;
    for(int i=0; i<fYSize; i++) empty.push_back(0);
    for (int j=0; j<fXSize; j++) fMap.push_back(empty);

    //the loop then adds in obstacles randomly
    for(int i=0; i<fXSize; i++)
        for(int j=0; j<fYSize; j++)
        {
            random = rand() % 100;
            if(random < fPercentWall)
            {
                fMap[i][j] = 3;
            }else fMap[i][j] = 0;
        }
}
