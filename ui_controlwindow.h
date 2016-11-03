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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ControlWindow
{
public:
    QPushButton *runDFS;
    QPushButton *mapOptions;
    QPushButton *placeholder;

    void setupUi(QWidget *ControlWindow)
    {
        if (ControlWindow->objectName().isEmpty())
            ControlWindow->setObjectName(QStringLiteral("ControlWindow"));
        ControlWindow->resize(400, 300);
        runDFS = new QPushButton(ControlWindow);
        runDFS->setObjectName(QStringLiteral("runDFS"));
        runDFS->setGeometry(QRect(50, 20, 291, 23));
        mapOptions = new QPushButton(ControlWindow);
        mapOptions->setObjectName(QStringLiteral("mapOptions"));
        mapOptions->setGeometry(QRect(130, 220, 121, 51));
        placeholder = new QPushButton(ControlWindow);
        placeholder->setObjectName(QStringLiteral("placeholder"));
        placeholder->setGeometry(QRect(50, 60, 291, 23));

        retranslateUi(ControlWindow);

        QMetaObject::connectSlotsByName(ControlWindow);
    } // setupUi

    void retranslateUi(QWidget *ControlWindow)
    {
        ControlWindow->setWindowTitle(QApplication::translate("ControlWindow", "Form", 0));
        runDFS->setText(QApplication::translate("ControlWindow", "Run Depth First Search", 0));
        mapOptions->setText(QApplication::translate("ControlWindow", "Display Map Options", 0));
        placeholder->setText(QApplication::translate("ControlWindow", "Placeholer", 0));
    } // retranslateUi

};

namespace Ui {
    class ControlWindow: public Ui_ControlWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONTROLWINDOW_H
