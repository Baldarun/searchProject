#ifndef BFS_H
#define BFS_H

#include <queue>
#include <vector>
#include <string>
#include <algorithm>    //find method
#include <Algorithm.h>


class BFS: public Algorithm
{
    public:
        BFS(std::vector<std::vector<int>> map);

        void BFSearch();
        std::vector<std::vector<int>> pathFollowed(std::vector<std::vector<int>> explored);


    protected:

        std::queue<std::vector<int>> toExpand;
        std::vector<std::vector<int>> fpath;

};

#endif // BFS_H
