#ifndef simpleSearch_H
#define simpleSearch_H
#include <Algorithm.h>

//inherits from Algorithm
class SimpleSearch: public Algorithm
{

public:

    //declares a default (no arguments) constuctor
    SimpleSearch();

    //declares a constructor that allows the user to manually input a map
    SimpleSearch(std::vector<std::vector<int>> map);

    //declares a primary method of the class; the depth-first-search algorithm
    std::vector<std::vector<int>> DFSearch(std::vector<int> start);

    //declares a primary method of the class; the breadth-first-search algorithm
    std::vector<std::vector<int>> BFSearch(std::vector<int> start);

    //method to add values to the frontier, used the same by both searches
    void addFrontier(std::vector<int>);
};

#endif // simpleSearch_H
