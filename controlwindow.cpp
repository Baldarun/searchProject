#include "ControlWindow.h"
#include "ui_controlwindow.h"
#include "DisplayWindow.h"
#include "mapoptions.h"

#include <QPainter>

//constructor
ControlWindow::ControlWindow(DFS * dfs, MapMaker * map, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ControlWindow), fDFS(dfs), fMapMaker(map)
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

void ControlWindow::on_mapOptions_clicked()
{
    MapOptions * view = new MapOptions(fMapMaker, fDFS);
}
