#include "mapoptions.h"
#include "ui_mapoptions.h"

#include <iostream>

//constructor
MapOptions::MapOptions(MapMaker * map, SimpleSearch * dfs, SimpleSearch * bfs, AStar * aStar, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MapOptions), fMapMaker(map), fDFS(dfs), fBFS(bfs), fAStar(aStar)
{
    ui->setupUi(this);

    //display window maximised
    QWidget::showMaximized();
}

//destructor
MapOptions::~MapOptions()
{
    delete ui;
    delete fMapMaker;
    delete fDFS;
    delete fBFS;
    delete fAStar;
}

//generates a new map when the button is clicked
void MapOptions::on_newMap_clicked()
{
    fMapMaker->intitialise(); //calls the initialise method to redo the procedural generation
    update(); //prompts a repaint to display updated features
}

//saves the new map to each variable so other GUI elements can use it
void MapOptions::on_keepButton_clicked()
{
    //uses setters to change each object to the newly generated parameters
    fDFS->setMap(fMapMaker->getMap());
    fDFS->setStart(fDFS->findStart());
    fDFS->setGoal(fDFS->findGoal());
    //this clear is so that it will effectively refresh the search. It it were not here the
    //searches would return the values for all searches they had done previously
    fDFS->clearAll();
    //std::cout << "DFS: " << fDFS->getExplored().size() << "\n";

    fBFS->setMap(fMapMaker->getMap());
    fBFS->setStart(fBFS->findStart());
    fBFS->setGoal(fBFS->findGoal());
    fBFS->clearAll();


    fAStar->setMap(fMapMaker->getMap());
    fAStar->setStart(fAStar->findStart());
    fAStar->setGoal(fAStar->findGoal());
    fAStar->clearAll();
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
           painter.drawRect(j*30+110, i*30, 30, 30);

           //three if statements check for the start and finish, and label them
           //and also check for obstacles, and mark those with blacked out spaces
           if(fMapMaker->getMap()[i][j]==1)
           {
               painter.drawText(j*30+120, i*30+15, "S");
           }else if(fMapMaker->getMap()[i][j]==2)
           {
               painter.drawText(j*30+120, i*30+15, "F");
           }else if(fMapMaker->getMap()[i][j]==3)
           {
               painter.fillRect(j*30+110, i*30, 30, 30, Qt::black);
           }
        }



}
