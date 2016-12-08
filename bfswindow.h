#ifndef BFSWINDOW_H
#define BFSWINDOW_H

#include <QWidget>
#include <simpleSearch.h>
#include <QPainter>
#include <QString>
#include <vector>

namespace Ui {
class BFSWindow;
}

class BFSWindow : public QWidget
{
    Q_OBJECT

    //constructor and destructor declaration
public:
    explicit BFSWindow(SimpleSearch * bfs, QWidget *parent = 0);
    ~BFSWindow();

private slots:
    void paintEvent(QPaintEvent *);


//same private variables that it takes from ControlWindow
private:
    Ui::BFSWindow *ui;

    SimpleSearch * fBFS;
};

#endif // BFSWINDOW_H
