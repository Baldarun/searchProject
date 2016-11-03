#include "mapoptions.h"
#include "ui_mapoptions.h"

#include <QPainter>

MapOptions::MapOptions(MapMaker * map, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MapOptions), fMapMaker(map)
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

//override standard paintEvent
void MapOptions::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    //a loop that runs over every value in the map
    for(int i=0; i<fMapMaker->getMap().size(); i++)
        for(int j=0; j<fMapMaker->getMap()[i].size(); j++)
        {
           //draws a black rectangle in each corresponding location
           painter.setPen(Qt::black);
           painter.drawRect(j*40, i*40, 40, 40);

           //three if statements check for the start and finish, and label them
           //and also check for obstacles, and mark those with blacked out spaces
           if(fMapMaker->getMap()[i][j]==1)
           {
               painter.drawText(j*40+10, i*40+15, "S");
           }else if(fMapMaker->getMap()[i][j]==2)
           {
               painter.drawText(j*40+10, i*40+15, "F");
           }else if(fMapMaker->getMap()[i][j]==3)
           {
               painter.fillRect(j*40, i*40, 40, 40, Qt::black);
           }
        }



}


