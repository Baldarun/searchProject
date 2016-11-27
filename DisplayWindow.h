#ifndef DISPLAYWINDOW_H
#define DISPLAYWINDOW_H

#include <QWidget>
#include <simpleSearch.h>

namespace Ui {
class DisplayWindow;
}

class DisplayWindow : public QWidget
{
    Q_OBJECT

public:
    //constructor and destructor
    explicit DisplayWindow(SimpleSearch * dfs, QWidget *parent = 0);
    ~DisplayWindow();

private slots:
    void paintEvent(QPaintEvent *);

private:
    //same private variables as ControlWindow
    Ui::DisplayWindow *ui;

    SimpleSearch * fDFS;
};

#endif // DISPLAYWINDOW_H
