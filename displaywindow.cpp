#include "DisplayWindow.h"
#include "ui_DisplayWindow.h"

//constructor
DisplayWindow::DisplayWindow(SimpleSearch * dfs, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DisplayWindow), fDFS(dfs)
{
    ui->setupUi(this);

    //display window maximised
    QWidget::showMaximized();

}

//destructor
DisplayWindow::~DisplayWindow()
{
    delete ui;
    delete fDFS;
}

//override standard paintEvent
void DisplayWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    //call the search and findpath methods and store its output as a vector if it hasn't already been called
    if(fDFS->getExplored().empty()==true)
    {
        //the output vector is a dummy variable used to call the methods. It is otherwise unused
        std::vector<std::vector<int>> output = fDFS->DFSearch(fDFS->getStart());
        output = fDFS->findPath(fDFS->getGoal());
    }

    //loop over the output
    //This loop comes before the grid loop so that the grid is visible over it
    for(int i = 0; i<fDFS->getExplored().size(); i++)
    {
        //create red squares in grid spaces the algorithm visits
        painter.fillRect(fDFS->getExplored()[i][1]*30, fDFS->getExplored()[i][0]*30, 30, 30, Qt::red);
        //copy the loop variable i to a QString value that drawtext can use
        QString qCount = QString::number(i);
        //places the value representing order visited in bottom right of each square
        //the added numbers are offsets to position the characters
        painter.drawText(fDFS->getExplored()[i][1]*30+10, fDFS->getExplored()[i][0]*30+25, qCount);
    }

    //separate loop to draw the path in green over the explored tiles, as this vector is a different length
    for(int i=0; i<fDFS->getPath().size(); i++)
    {
        //draws this object in the top right corner so the explored status is still visible
        painter.fillRect(fDFS->getPath()[i][1]*30+15, fDFS->getPath()[i][0]*30, 15, 15, Qt::green);
    }

    //a loop that runs over every value in the map to draw the map.
    //easier to do grid by doing it on top of the explored squares than fiddling about with their sizes so
    //that they draw inside the lines.
    for(int i=0; i<fDFS->getMap().size(); i++)
        for(int j=0; j<fDFS->getMap()[i].size(); j++)
        {
           //draws a black rectangle in each corresponding location
           painter.setPen(Qt::black);
           painter.drawRect(j*30, i*30, 30, 30);

           //three if statements check for the start and finish, and label them
           //and also check for obstacles, and mark those with blacked out spaces
           if(fDFS->getMap()[i][j]==1)
           {
               painter.drawText(j*30+4, i*30+12, "S");
           }else if(fDFS->getMap()[i][j]==2)
           {
               painter.drawText(j*30+4, i*30+12, "F");
           }else if(fDFS->getMap()[i][j]==3)
           {
               painter.fillRect(j*30, i*30, 30, 30, Qt::black);
           }
        }



}
