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

    bool inFrontier(std::vector<int>);

    //declares the method to add values to fFrontier
    void addFrontier(std::vector<int>);

//privately declared objects, as nothing will inherit directly from DFS
private:
    //A queue of points to expand
    std::vector<std::vector<int>> fFrontier;

};

#endif // DFS_H
