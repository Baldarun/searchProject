#ifndef ASTARWINDOW_H
#define ASTARWINDOW_H

#include <QWidget>
#include <astar.h>
#include <QPainter>
#include <QString>
#include <vector>


namespace Ui {
class AStarWindow;
}

class AStarWindow : public QWidget
{
    Q_OBJECT

    //constructor and destructor declaration
public:
    explicit AStarWindow(AStar * aStar, QWidget *parent = 0);
    ~AStarWindow();

private slots:
    void paintEvent(QPaintEvent *);

    //same private variables that it takes from ControlWindow
private:
    Ui::AStarWindow *ui;

    AStar * fAStar;


};

#endif // ASTARWINDOW_H
