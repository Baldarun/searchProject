#ifndef DISPLAYWINDOW_H
#define DISPLAYWINDOW_H

#include <QWidget>
#include <DFS.h>

namespace Ui {
class DisplayWindow;
}

class DisplayWindow : public QWidget
{
    Q_OBJECT

public:
    //constructor and destructor
    explicit DisplayWindow(DFS * dfs, QWidget *parent = 0);
    ~DisplayWindow();

private slots:
    void paintEvent(QPaintEvent *);

private:
    //same private variables as ControlWindow
    Ui::DisplayWindow *ui;

    DFS * fDFS;
};

#endif // DISPLAYWINDOW_H
