/********************************************************************************
** Form generated from reading UI file 'controlwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONTROLWINDOW_H
#define UI_CONTROLWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ControlWindow
{
public:
    QWidget *centralWidget;
    QPushButton *runDFS;
    QPushButton *placeholder;
    QPushButton *mapOptions;

    void setupUi(QMainWindow *ControlWindow)
    {
        if (ControlWindow->objectName().isEmpty())
            ControlWindow->setObjectName(QStringLiteral("ControlWindow"));
        ControlWindow->resize(400, 300);
        centralWidget = new QWidget(ControlWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        runDFS = new QPushButton(centralWidget);
        runDFS->setObjectName(QStringLiteral("runDFS"));
        runDFS->setGeometry(QRect(20, 20, 75, 23));
        placeholder = new QPushButton(centralWidget);
        placeholder->setObjectName(QStringLiteral("placeholder"));
        placeholder->setGeometry(QRect(110, 20, 75, 23));
        mapOptions = new QPushButton(centralWidget);
        mapOptions->setObjectName(QStringLiteral("mapOptions"));
        mapOptions->setGeometry(QRect(120, 150, 131, 31));
        ControlWindow->setCentralWidget(centralWidget);

        retranslateUi(ControlWindow);

        QMetaObject::connectSlotsByName(ControlWindow);
    } // setupUi

    void retranslateUi(QMainWindow *ControlWindow)
    {
        ControlWindow->setWindowTitle(QApplication::translate("ControlWindow", "ControlWindow", 0));
        runDFS->setText(QApplication::translate("ControlWindow", "Run DFS", 0));
        placeholder->setText(QApplication::translate("ControlWindow", "placeholder", 0));
        mapOptions->setText(QApplication::translate("ControlWindow", "Map Options", 0));
    } // retranslateUi

};

namespace Ui {
    class ControlWindow: public Ui_ControlWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONTROLWINDOW_H
