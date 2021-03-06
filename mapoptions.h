#ifndef MAPOPTIONS_H
#define MAPOPTIONS_H

#include <QWidget>
#include <mapmaker.h>
#include <simpleSearch.h>
#include <astar.h>
#include <QPainter>

namespace Ui {
class MapOptions;
}

class MapOptions : public QWidget
{
    Q_OBJECT

public:
    //constructor and destructor
    explicit MapOptions(MapMaker * map, SimpleSearch * dfs, SimpleSearch * bfs, AStar * aStar, QWidget *parent = 0);
    ~MapOptions();

private slots:
    void paintEvent(QPaintEvent *event);

    void on_newMap_clicked();

    void on_keepButton_clicked();

private:

    //keeps each other object as a variable so it can set their maps
    Ui::MapOptions *ui;

    MapMaker * fMapMaker;
    SimpleSearch * fDFS;
    SimpleSearch * fBFS;
    AStar * fAStar;
};

#endif // MAPOPTIONS_H
