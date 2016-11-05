#include "mapmaker.h"

MapMaker::MapMaker()
{
    //default values initialsied
    fXSize = 30;
    fYSize = 50;
    fPercentWall = 40;

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

    //loop the following 5 times
    for(int k=0; k<7; k++)
    {

        //this loop checks each map coordinate for adjacent obstacles to adjust their placement
        //A point surrounded by 5+ obstacles will become an obstacle, as will one surrounded by
        //one or none (This prevents large empty spaces)
        for(int i=0; i<fXSize; i++)
        for(int j=0; j<fYSize; j++)
        {
            //the number that will increment as it finds adjacent obstacles
            //Or out of bounds squares. Including this creates a neat outer wall
            float count = 0;

            //the following 9 if statements check the point and its neighbours
            if(inBounds(std::vector<int>{i-1, j-1})==false) count+=0.7;
            else if(fMap[i-1][j-1]==3) count++;

            if(inBounds(std::vector<int>{i-1, j})==false) count+=0.7;
            else if(fMap[i-1][j]==3) count++;

            if(inBounds(std::vector<int>{i-1, j+1})==false) count+=0.7;
            else if(fMap[i-1][j+1]==3) count++;

            if(inBounds(std::vector<int>{i, j-1})==false) count+=0.7;
            else if(fMap[i][j-1]==3) count++;

            if(inBounds(std::vector<int>{i, j})==false) count+=0.7;
            else if(fMap[i][j]==3) count++;

            if(inBounds(std::vector<int>{i, j+1})==false) count+=0.7;
            else if(fMap[i][j+1]==3) count++;

            if(inBounds(std::vector<int>{i+1, j-1})==false) count+=0.7;
            else if(fMap[i+1][j-1]==3) count++;

            if(inBounds(std::vector<int>{i+1, j})==false) count+=0.7;
            else if(fMap[i+1][j]==3) count++;

            if(inBounds(std::vector<int>{i+1, j+1})==false) count+=0.7;
            else if(fMap[i+1][j+1]==3) count++;


            if(k<4)
            {
                //assign a value to point i, j on the map based on value of count
                if(count >= 5.0 || count <= 1.0) fMap[i][j] = 3;
                else fMap[i][j] = 0;
            }else
            {
                //assign a value to point i, j on the map based on value of count
                if(count >= 5.0) fMap[i][j] = 3;
                else fMap[i][j] = 0;
            }
            //most of the numerical values chosen for boundaries were picked because
            //they tended to produce better looking maps
        }
    }
    //assign the start and finish points to random empty locations
    int xPos = rand() % fXSize;
    int yPos = rand() % fYSize;

    while(fMap[xPos][yPos] != 0)
    {
        xPos = rand() % fXSize;
        yPos = rand() % fYSize;
    }
    fMap[xPos][yPos] = 1;

    while(fMap[xPos][yPos] != 0)
    {
        xPos = rand() % fXSize;
        yPos = rand() % fYSize;
    }
    fMap[xPos][yPos] = 2;

}
