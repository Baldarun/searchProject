#include "BFS.h"
#include <iostream>


BFS::BFS(std::vector<std::vector<int> > map)
{
    fmap = map;
    start = {0, 6};
}
//BFS::~BFS(){}
/*
bool BFS::BFSearch()
{
    std::vector<int> start = {2, 6};
    toExpand.push(start);

    while(!toExpand.empty())
    {
        if(fmap[toExpand.front()[0]][toExpand.front()[1]] == 2) std::cout << "true" << std::endl;
        else if(fmap[toExpand.front()[0]][toExpand.front()[1]] != 2) std::cout << "false" << std::endl;

        if(fmap[toExpand.front()[0]][toExpand.front()[1]] == 2) return true;
        toExpand.pop();

        std::vector<int> next = {toExpand.front()[0]++, toExpand.front()[1]};
        std::cout << next[0] << next[1] << std::endl;

        if(inBounds(next, fmap) &&
                std::find(explored.begin(), explored.end(), next)!= explored.end())
            toExpand.push(next);
        //std::cout << toExpand.front()[0] << toExpand.front()[1] << std::endl;

        next[0] = toExpand.front()[0], next[1] = toExpand.front()[1]++;
        std::cout << next[0] << next[1] << std::endl;

        if(inBounds(next, fmap) &&
                std::find(explored.begin(), explored.end(), next)!= explored.end())
            toExpand.push(next);
        //std::cout << toExpand.front()[0] << toExpand.front()[1] << std::endl;

        next[0] = toExpand.front()[0]--, next[1] = toExpand.front()[1];
        std::cout << next[0] << next[1] << std::endl;

        if(inBounds(next, fmap) &&
                std::find(explored.begin(), explored.end(), next)!= explored.end())
            toExpand.push(next);
        //std::cout << toExpand.front()[0] << toExpand.front()[1] << std::endl;

        next[0] = toExpand.front()[0],next[1] = toExpand.front()[1]--;
        std::cout << next[0] << next[1] << std::endl;

        if(inBounds(next, fmap) &&
                std::find(explored.begin(), explored.end(), next)!= explored.end())
            toExpand.push(next);
        //std::cout << toExpand.front()[0] << toExpand.front()[1] << std::endl;

    }
    return false;
}



void BFS::BFSearch()
{
    toExpand.push(start);
    Tree gridTravel = new Tree;
    gridTravel.node = start;

    while(!toExpand.empty())
    {
        //std::cout << toExpand.front()[0] << " " << toExpand.front()[1] << "\n";

        if(fmap[toExpand.front()[0]][toExpand.front()[1]] == 2) break;

        //Added current element to explored
        explored.push_back(toExpand.front());

        //Created dummy variable justExplored allowing us to freely remove by toExpand.pop
        std::vector<int> justExplored = toExpand.front();
        toExpand.pop();

        //In all next allocations use justExplored instead of toExpand.front()
        //Changed from ++ to +1 as i think it may be fiddling with the actual justExplored value
        std::vector<int> next = {justExplored[0]+1, justExplored[1]};

        //If statements used to say "!= explored.end()", debugging shows this makes it false so changed to ==
        if(inBounds(next, fmap) &&
                std::find(explored.begin(), explored.end(), next)== explored.end())
        {
            toExpand.push(next);
            gridTravel.zero = next;
        }


        next[0] = justExplored[0], next[1] = justExplored[1]+1;

        if(inBounds(next, fmap) &&
                std::find(explored.begin(), explored.end(), next)== explored.end())
        {
            toExpand.push(next);
            gridTravel.one.node = next;
        }

        next[0] = justExplored[0]-1, next[1] = justExplored[1];

        if(inBounds(next, fmap) &&
                std::find(explored.begin(), explored.end(), next)== explored.end())
        {
            toExpand.push(next);
            gridTravel.two.node = next;
        }

        next[0] = justExplored[0], next[1] = justExplored[1]-1;

        if(inBounds(next, fmap) &&
                std::find(explored.begin(), explored.end(), next)== explored.end())
        {
            toExpand.push(next);
            gridTravel.three.node = next;
        }
    }
    //return false;
    //return explored;
}

std::vector<std::vector<int>> BFS::pathFollowed(std::vector<std::vector<int>> explored)
{

}
*/
