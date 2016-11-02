#ifndef CONTROLWINDOW_H
#define CONTROLWINDOW_H

#include <QMainWindow>
#include <DFS.h>

namespace Ui {
class ControlWindow;
}

class ControlWindow : public QMainWindow
{
    Q_OBJECT

    //constructor and destructor declaration
public:
    explicit ControlWindow(DFS * dfs, QWidget *parent = 0);
    ~ControlWindow();

    //slot declared for objects made in the .ui form
private slots:

    void on_pushButton_clicked();

private:
    Ui::ControlWindow *ui;

    //DFS to be used declared as a pointer to the input
    DFS * fDFS;

};

#endif // CONTROLWINDOW_H
