#ifndef CONTROLWINDOW_H
#define CONTROLWINDOW_H

#include <QMainWindow>
#include <DFS.h>
#include <mapmaker.h>

namespace Ui {
class ControlWindow;
}

class ControlWindow : public QMainWindow
{
    Q_OBJECT

    //constructor and destructor declaration
public:
    explicit ControlWindow(DFS * dfs, MapMaker * map, QWidget *parent = 0);
    ~ControlWindow();

    //slot declared for objects made in the .ui form
private slots:

    void on_runDFS_clicked();
    void on_mapOptions_clicked();

private:
    Ui::ControlWindow *ui;

    //DFS to be used declared as a pointer to the input
    DFS * fDFS;
    MapMaker * fMapMaker;

};

#endif // CONTROLWINDOW_H
