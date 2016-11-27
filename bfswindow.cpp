#include "bfswindow.h"
#include "ui_bfswindow.h"

#include <QPainter>
#include <QString>
#include <vector>

BFSWindow::BFSWindow(SimpleSearch * bfs, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BFSWindow), fBFS(bfs)
{
    ui->setupUi(this);

    show();
}

BFSWindow::~BFSWindow()
{
    delete ui;
}


//override standard paintEvent
void BFSWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    //call the search method and store its output as a vector if it hasn't already been called
    if(fBFS->getExplored().empty()==true)
        std::vector<std::vector<int>> output = fBFS->BFSearch(fBFS->getStart());

    //loop over the output
    //This loop comes before the grid loop so that the grid is visible over it
    for(int i = 0; i<fBFS->getExplored().size(); i++) //fills explored tiles grey
    {
        //create red rectangles in grid spaces the algorithm visits
        painter.fillRect(fBFS->getExplored()[i][1]*30, fBFS->getExplored()[i][0]*30, 30, 30, Qt::red);
        //copy the loop variable i to a QString value that drawtext can use
        QString qCount = QString::number(i);
        //places the value representing order visited in bottom right of each square
        //the added numbers are offsets to position the characters
        painter.drawText(fBFS->getExplored()[i][1]*30+10, fBFS->getExplored()[i][0]*30+25, qCount);
        //path disappears if you resize the window
    }

    //a loop that runs over every value in the map
    for(int i=0; i<fBFS->getMap().size(); i++)
        for(int j=0; j<fBFS->getMap()[i].size(); j++)
        {
           //draws a black rectangle in each corresponding location
           painter.setPen(Qt::black);
           painter.drawRect(j*30, i*30, 30, 30);

           //three if statements check for the start and finish, and label them
           //and also check for obstacles, and mark those with blacked out spaces
           if(fBFS->getMap()[i][j]==1)
           {
               painter.drawText(j*30+4, i*30+12, "S");
           }else if(fBFS->getMap()[i][j]==2)
           {
               painter.drawText(j*30+4, i*30+12, "F");
           }else if(fBFS->getMap()[i][j]==3)
           {
               painter.fillRect(j*30, i*30, 30, 30, Qt::black);
           }
        }



}
