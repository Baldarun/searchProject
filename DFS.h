#ifndef DFS_H
#define DFS_H

#include <Algorithm.h>

//child class of Algorithm
class DFS: public Algorithm
{

public:

    //declares a default (no arguments) constuctor
    DFS();
    //declares a constructor that allows the user to manually input a map
    DFS(std::vector<std::vector<int>> map);

    //declares the primary method of the class; the depth-first-search algorithm
    std::vector<std::vector<int>> DFSearch(std::vector<int> start);


};

#endif // DFS_H
