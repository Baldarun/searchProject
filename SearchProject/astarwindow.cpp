#include "astarwindow.h"
#include "ui_astarwindow.h"

//constructor
AStarWindow::AStarWindow(AStar * aStar, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AStarWindow), fAStar(aStar)
{
    ui->setupUi(this);

    //display window maximised
    QWidget::showMaximized();
}

//destructor
AStarWindow::~AStarWindow()
{
    delete ui;
    delete fAStar;
}



//override standard paintEvent
void AStarWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    //call the search method and store its output as a vector if it hasn't already been called
    if(fAStar->getExplored().empty()==true)
    {
        std::vector<std::vector<int>> output = fAStar->AStarSearch(fAStar->getStart());
        output = fAStar->findPath(fAStar->getGoal());
    }

    //loop over the output
    //This loop comes before the grid loop so that the grid is visible over it
    for(int i = 0; i<fAStar->getExplored().size(); i++)
    {
        //create red squares in grid spaces the algorithm visits
        painter.fillRect(fAStar->getExplored()[i][1]*30, fAStar->getExplored()[i][0]*30, 30, 30, Qt::red);
        //copy the loop variable i to a QString value that drawtext can use
        QString qCount = QString::number(i);
        //places the value representing order visited in bottom right of each square
        //the added numbers are offsets to position the characters
        painter.drawText(fAStar->getExplored()[i][1]*30+10, fAStar->getExplored()[i][0]*30+25, qCount);
    }

    //separate loop to draw the path in green over the explored tiles, as this vector is a different length
    for(int i=0; i<fAStar->getPath().size(); i++)
    {
        //draws this object in the top right corner so the explored status is still visible
        painter.fillRect(fAStar->getPath()[i][1]*30+15, fAStar->getPath()[i][0]*30, 15, 15, Qt::green);
    }

    //a loop that runs over every value in the map
    //easier to do grid by doing it on top of the explored squares than fiddling about with their sizes so
    //that they draw inside the lines.
    for(int i=0; i<fAStar->getMap().size(); i++)
        for(int j=0; j<fAStar->getMap()[i].size(); j++)
        {
           //draws a black rectangle in each corresponding location
           painter.setPen(Qt::black);
           painter.drawRect(j*30, i*30, 30, 30);

           //three if statements check for the start and finish, and label them
           //and also check for obstacles, and mark those with blacked out spaces
           if(fAStar->getMap()[i][j]==1)
           {
               painter.drawText(j*30+4, i*30+12, "S");
           }else if(fAStar->getMap()[i][j]==2)
           {
               painter.drawText(j*30+4, i*30+12, "F");
           }else if(fAStar->getMap()[i][j]==3)
           {
               painter.fillRect(j*30, i*30, 30, 30, Qt::black);
           }
        }



}
