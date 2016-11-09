#ifndef MAPOPTIONS_H
#define MAPOPTIONS_H

#include <QWidget>
#include <mapmaker.h>
#include <DFS.h>

namespace Ui {
class MapOptions;
}

class MapOptions : public QWidget
{
    Q_OBJECT

public:
    //constructor and destructor
    explicit MapOptions(MapMaker * map, DFS * dfs, QWidget *parent = 0);
    ~MapOptions();

private slots:
    void paintEvent(QPaintEvent *event);

    void on_newMap_clicked();

    void on_keepButton_clicked();

private:
    //same private variables as ControlWindow, besides fDFS, which isn't needed
    Ui::MapOptions *ui;

    MapMaker * fMapMaker;
    DFS * fDFS;
};

#endif // MAPOPTIONS_H
