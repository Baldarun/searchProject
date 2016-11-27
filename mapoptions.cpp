#include "mapoptions.h"
#include "ui_mapoptions.h"

#include <QPainter>

MapOptions::MapOptions(MapMaker * map, SimpleSearch * dfs, SimpleSearch * bfs, AStar * aStar, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MapOptions), fMapMaker(map), fDFS(dfs), fBFS(bfs), fAStar(aStar)
{
    ui->setupUi(this);

    //display window
    show();
}

//destructor
MapOptions::~MapOptions()
{
    delete ui;
}

void MapOptions::on_newMap_clicked()
{
    fMapMaker->intitialise();
    update();
}

void MapOptions::on_keepButton_clicked()
{
    fDFS->setMap(fMapMaker->getMap());
    fDFS->setStart(fDFS->findStart());
    fDFS->clearExplored();
    std::vector<std::vector<int>> output = fDFS->DFSearch(fDFS->getStart());

    fBFS->setMap(fMapMaker->getMap());
    fBFS->setStart(fBFS->findStart());
    fBFS->clearExplored();
    output = fBFS->BFSearch(fBFS->getStart());

    fAStar->setMap(fMapMaker->getMap());
    fAStar->setStart(fAStar->findStart());
    fAStar->clearExplored();
    output = fAStar->AStarSearch(fAStar->getStart());
}

//override standard paintEvent
void MapOptions::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    //a loop that runs over every value in the map
    for(int i=0; i<fMapMaker->getSize()[0]; i++)
        for(int j=0; j<fMapMaker->getSize()[1]; j++)
        {
           //draws a black rectangle in each corresponding location
           painter.setPen(Qt::black);
           painter.drawRect(j*30, i*30, 30, 30);

           //three if statements check for the start and finish, and label them
           //and also check for obstacles, and mark those with blacked out spaces
           if(fMapMaker->getMap()[i][j]==1)
           {
               painter.drawText(j*30+10, i*30+15, "S");
           }else if(fMapMaker->getMap()[i][j]==2)
           {
               painter.drawText(j*30+10, i*30+15, "F");
           }else if(fMapMaker->getMap()[i][j]==3)
           {
               painter.fillRect(j*30, i*30, 30, 30, Qt::black);
           }
        }



}
