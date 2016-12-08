#ifndef DISPLAYWINDOW_H
#define DISPLAYWINDOW_H

#include <QWidget>
#include <simpleSearch.h>
#include <QPainter>
#include <QString>
#include <vector>

namespace Ui {
class DisplayWindow;
}

class DisplayWindow : public QWidget
{
    Q_OBJECT

public:
    //constructor and destructor declaration
    explicit DisplayWindow(SimpleSearch * dfs, QWidget *parent = 0);
    ~DisplayWindow();

private slots:
    void paintEvent(QPaintEvent *);

private:
    //same private variables that it takes from ControlWindow
    Ui::DisplayWindow *ui;

    SimpleSearch * fDFS;
};

#endif // DISPLAYWINDOW_H
