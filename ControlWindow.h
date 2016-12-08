#ifndef CONTROLWINDOW_H
#define CONTROLWINDOW_H

#include <QMainWindow>
#include <simpleSearch.h>
#include <mapmaker.h>
#include <astar.h>

namespace Ui {
class ControlWindow;
}

class ControlWindow : public QMainWindow
{
    Q_OBJECT

    //constructor and destructor declaration
public:
    explicit ControlWindow(SimpleSearch * dfs, SimpleSearch * bfs, AStar * a, MapMaker * map, QWidget *parent = 0);
    ~ControlWindow();

    //slot declared for objects made in the .ui form
private slots:

    void on_runDFS_clicked();
    void on_runBFS_clicked();
    void on_runAStar_clicked();
    void on_mapOptions_clicked();

private:
    Ui::ControlWindow *ui;

    //objects to be used declared as a pointers to the input
    SimpleSearch * fDFS;
    SimpleSearch * fBFS;
    AStar * fAStar;
    MapMaker * fMapMaker;

};

#endif // CONTROLWINDOW_H
