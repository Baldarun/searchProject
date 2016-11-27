#ifndef BFSWINDOW_H
#define BFSWINDOW_H

#include <QWidget>
#include <simpleSearch.h>

namespace Ui {
class BFSWindow;
}

class BFSWindow : public QWidget
{
    Q_OBJECT

public:
    explicit BFSWindow(SimpleSearch * bfs, QWidget *parent = 0);
    ~BFSWindow();

private slots:
    void paintEvent(QPaintEvent *);



private:
    Ui::BFSWindow *ui;

    SimpleSearch * fBFS;
};

#endif // BFSWINDOW_H
