#ifndef ASTARWINDOW_H
#define ASTARWINDOW_H

#include <QWidget>
#include <astar.h>

namespace Ui {
class AStarWindow;
}

class AStarWindow : public QWidget
{
    Q_OBJECT

public:
    explicit AStarWindow(AStar * aStar, QWidget *parent = 0);
    ~AStarWindow();

private slots:
    void paintEvent(QPaintEvent *);

private:
    Ui::AStarWindow *ui;

    AStar * fAStar;
};

#endif // ASTARWINDOW_H
