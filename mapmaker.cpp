#include "mapmaker.h"

//default constructor
MapMaker::MapMaker()
{
    //default values initialsied
    fXSize = 30;
    fYSize = 50;
    fPercentWall = 40;

    //the initialise function procedurally generates the layout of the map
    this->intitialise();
}

//arguments constructor
MapMaker::MapMaker(int xSize, int ySize, int percentWall)
{
    fXSize = xSize;
    fYSize = ySize;
    fPercentWall = percentWall;
    this->intitialise();
}

//method to procedurally place obstacles on a map
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
            //for each point of the map there is a percentwall% chance of an obstacle being placed
            random = rand() % 100;
            if(random < fPercentWall)
            {
                fMap[i][j] = 3;
            }else fMap[i][j] = 0;
        }

    //loop the following
    //7 loops chosen after some experimentation because it gives good looking results
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
            //adding 0.7 for an out of bounds square rather than 1 adds a border
            //but avoid excess unusable space around the outside
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


            //different behaviour for first 4 and last 3 loops
            //points added to empty spaces only in early loops
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

    //check could be implemented to ensure map is completeable, but isn't here as it is highly unlikely
}
