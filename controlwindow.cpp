#include "ControlWindow.h"
#include "ui_controlwindow.h"
#include "DisplayWindow.h"

//constructor
ControlWindow::ControlWindow(DFS * dfs, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ControlWindow), fDFS(dfs)
{
    ui->setupUi(this);

}
//destructor
ControlWindow::~ControlWindow()
{
    delete ui;
}
//opens a DisplayWindow and shows it when the button is clicked
void ControlWindow::on_pushButton_clicked()
{
    DisplayWindow * view = new DisplayWindow(fDFS);
}
