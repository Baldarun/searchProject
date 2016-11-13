#include <ControlWindow.h>
#include <QApplication>
#include <DFS.h>
#include <mapmaker.h>

#include <sstream>  //testing
#include <iostream> //testing

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    DFS dfs;                //declares a default DFS object
    MapMaker map;
    ControlWindow w (&dfs, &map); //creates a ControlWindow with that as input
    w.show();               //displays the control window

    //testing: prints out the map being used to the console
/*
    std::stringstream ss;
    for(int i=0; i<map.getSize()[0]; i++)
    {
        for(int j=0; j<map.getSize()[1]; j++)
        {
            ss << map.getMap()[i][j] << "\t";
        }
        ss << std::endl;
    }
    std::string testOut = ss.str();
    std::cout << testOut << std::endl;
*/
    return a.exec();
}
