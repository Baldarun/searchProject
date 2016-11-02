#include "DFS.h"

//default constructor uses a pre-defined map
DFS::DFS()
{
    fMap = {{0, 0, 0, 0, 0, 0, 1, 0},
            {0, 3, 3, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 3, 0, 0, 0},
            {0, 0, 0, 0, 3, 0, 3, 0},
            {0, 0, 0, 0, 3, 0, 0, 0},
            {0, 0, 3, 0, 3, 0, 0, 0},
            {0, 0, 2, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0}};
}

//constructor that would take an input vector to use as the map
DFS::DFS(std::vector<std::vector<int>> map)
{
    fMap = map;
}

//this method will perform a depth first search starting at the point given as an argument
//it will return a list of coordinate sets that form the path it uses.
std::vector<std::vector<int>> DFS::DFSearch(std::vector<int> start)
{
    //current point has been expanded
    fExplored.push_back(start);
    //if goal found, return path
    if(fMap[start[0]][start[1]] == 2) return fExplored;
    //output current location and its value for testing
    std::cout << "current: " << start[0] << " " << start[1] << "\n";
    //std::cout << fMap[start[0]][start[1]] << "\n";

    //No good variable to loop over, so the four "next" values and their if statements are
    //for checking the direct neighbours of the start point
    std::vector<int> next = {start[0]+1, start[1]};
    //testing: output coordinates of next and its value
    std::cout << "nextdown: " << next[0] << " " << next[1] << "\n";
    if(inBounds(next)) std::cout << "value: " << fMap[next[0]][next[1]] << "\n";


    //checks that this neighbour is both within the map, hasn't already been explored,
    //and doesn't contain an obstacle
    if(inBounds(next)==true && isExplored(next)==false && fMap[next[0]][next[1]] != 3)
    {

        //iterates the algorithm. This will progress through the map and create
        //the path to return
        return DFSearch(next);
    }

    next[0] = start[0]; next[1] = start[1]+1;
    //testing: output coordinates of next and its value
    std::cout << "nextright: " << next[0] << " " << next[1] << "\n";
    if(inBounds(next)) std::cout << "value: " << fMap[next[0]][next[1]] << "\n";

    if(inBounds(next)==true && isExplored(next)==false && fMap[next[0]][next[1]] != 3)
    {
        return DFSearch(next);
    }

    next[0] = start[0]-1; next[1] = start[1];
    //testing: output coordinates of next and its value
    std::cout << "nextup: " << next[0] << " " << next[1] << "\n";
    if(inBounds(next)) std::cout << "value: " << fMap[next[0]][next[1]] << "\n";

    if(inBounds(next)==true && isExplored(next)==false && fMap[next[0]][next[1]] != 3)
    {
        return DFSearch(next);
    }

    next[0] = start[0]; next[1] = start[1]-1;
    //testing: output coordinates of next and its value
    std::cout << "nextleft: " << next[0] << " " << next[1] << "\n";
    if(inBounds(next)) std::cout << "value: " << fMap[next[0]][next[1]] << "\n";

    if(inBounds(next)==true && isExplored(next)==false && fMap[next[0]][next[1]] != 3)
    {
        return DFSearch(next);
    }
    //if the entire map has been searched and no goal found, the algorithm returns
    //an empty vector
    else return std::vector<std::vector<int>>();
}
