#ifndef HCOORD_H
#define HCOORD_H

#include <vector>


class hCoord
{
public:
    hCoord(std::vector<int> point, int heur);

    std::vector<int> getPoint()
    {
        return fPoint;
    }

    int getHeur()
    {
        return fHeur;
    }



//private:

    std::vector<int> fPoint;
    int fHeur;
};

#endif // HCOORD_H
