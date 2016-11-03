#ifndef MAPOPTIONS_H
#define MAPOPTIONS_H

#include <QWidget>
#include <DFS.h>

namespace Ui {
class MapOptions;
}

class MapOptions : public QWidget
{
    Q_OBJECT

public:
    //constructor and destructor
    explicit MapOptions(DFS * dfs, QWidget *parent = 0);
    ~MapOptions();

private slots:
    void paintEvent(QPaintEvent *event);

private:
    //same private variables as ControlWindow
    Ui::MapOptions *ui;

    DFS * fDFS;
};

#endif // MAPOPTIONS_H
