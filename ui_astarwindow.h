/********************************************************************************
** Form generated from reading UI file 'astarwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ASTARWINDOW_H
#define UI_ASTARWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AStarWindow
{
public:

    void setupUi(QWidget *AStarWindow)
    {
        if (AStarWindow->objectName().isEmpty())
            AStarWindow->setObjectName(QStringLiteral("AStarWindow"));
        AStarWindow->resize(400, 300);

        retranslateUi(AStarWindow);

        QMetaObject::connectSlotsByName(AStarWindow);
    } // setupUi

    void retranslateUi(QWidget *AStarWindow)
    {
        AStarWindow->setWindowTitle(QApplication::translate("AStarWindow", "Form", 0));
    } // retranslateUi

};

namespace Ui {
    class AStarWindow: public Ui_AStarWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ASTARWINDOW_H
