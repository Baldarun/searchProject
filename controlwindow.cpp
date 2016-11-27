#include "ControlWindow.h"
#include "ui_controlwindow.h"
#include "DisplayWindow.h"
#include "mapoptions.h"
#include "bfswindow.h"
#include "astarwindow.h"

#include <QPainter>

//constructor
ControlWindow::ControlWindow(SimpleSearch * dfs, SimpleSearch * bfs,  AStar *a, MapMaker * map, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ControlWindow), fDFS(dfs), fBFS(bfs), fAStar(a), fMapMaker(map)
{
    ui->setupUi(this);

}
//destructor
ControlWindow::~ControlWindow()
{
    delete ui;
}
//opens a DisplayWindow and shows it when the button is clicked
void ControlWindow::on_runDFS_clicked()
{
    DisplayWindow * view = new DisplayWindow(fDFS);
}

void ControlWindow::on_runBFS_clicked()
{
    BFSWindow * view = new BFSWindow(fBFS);
}

void ControlWindow::on_runAStar_clicked()
{
    AStarWindow * view = new AStarWindow(fAStar);
}

void ControlWindow::on_mapOptions_clicked()
{
    MapOptions * view = new MapOptions(fMapMaker, fDFS, fBFS, fAStar);
}
