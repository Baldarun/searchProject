/********************************************************************************
** Form generated from reading UI file 'dfswindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DFSWINDOW_H
#define UI_DFSWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DFSWindow
{
public:

    void setupUi(QWidget *DFSWindow)
    {
        if (DFSWindow->objectName().isEmpty())
            DFSWindow->setObjectName(QStringLiteral("DFSWindow"));
        DFSWindow->resize(400, 300);

        retranslateUi(DFSWindow);

        QMetaObject::connectSlotsByName(DFSWindow);
    } // setupUi

    void retranslateUi(QWidget *DFSWindow)
    {
        DFSWindow->setWindowTitle(QApplication::translate("DFSWindow", "Form", 0));
    } // retranslateUi

};

namespace Ui {
    class DFSWindow: public Ui_DFSWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DFSWINDOW_H
