#ifndef DFSWINDOW_H
#define DFSWINDOW_H

#include <QWidget>
#include <simpleSearch.h>
#include <QPainter>
#include <QString>
#include <vector>

namespace Ui {
class DFSWindow;
}

class DFSWindow : public QWidget
{
    Q_OBJECT

public:
    //constructor and destructor declaration
    explicit DFSWindow(SimpleSearch * dfs, QWidget *parent = 0);
    ~DFSWindow();

private slots:
    void paintEvent(QPaintEvent *);

private:
    //same private variables that it takes from ControlWindow
    Ui::DFSWindow *ui;

    SimpleSearch * fDFS;
};

#endif // DFSWINDOW_H
