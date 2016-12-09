#include <ControlWindow.h>
#include <QApplication>
#include <simpleSearch.h>
#include <mapmaker.h>
#include <astar.h>


int main(int argc, char *argv[])
{

    //Declares a set of default argument objects to be used as arguments for the control window it opens
    QApplication a(argc, argv);
    SimpleSearch bfs;
    SimpleSearch dfs;
    AStar aStar;
    MapMaker map;
    ControlWindow w (&dfs, &bfs, &aStar, &map); //creates a ControlWindow with that as input
    w.show();               //displays the control window

    return a.exec();
}
