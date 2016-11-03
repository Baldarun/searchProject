#include "mapmaker.h"

MapMaker::MapMaker()
{
    fXSize = 30;
    fYSize = 30;
    fPercentWall = 45;
    fMap = this->intitialise();
}

MapMaker::MapMaker(int xSize, int ySize, int percentWall)
{
    fXSize = xSize;
    fYSize = ySize;
    fPercentWall = percentWall;
    fMap = this->intitialise();
}

std::vector<std::vector<int>> MapMaker::intitialise()
{
    //intitialise random numbers using time as the seed
    srand (time(NULL));
    int random;

    std::vector<std::vector<int>> output;

    for(int i=0; i<fXSize; i++)
        for(int j=0; j<fYSize; j++)
        {
            random = rand() % 100;
            if(random < fPercentWall)
            {
                output[i][j] = 3;
            }else output[i][j] = 0;
        }
}
