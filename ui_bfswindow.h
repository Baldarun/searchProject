/********************************************************************************
** Form generated from reading UI file 'bfswindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BFSWINDOW_H
#define UI_BFSWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BFSWindow
{
public:

    void setupUi(QWidget *BFSWindow)
    {
        if (BFSWindow->objectName().isEmpty())
            BFSWindow->setObjectName(QStringLiteral("BFSWindow"));
        BFSWindow->resize(400, 300);

        retranslateUi(BFSWindow);

        QMetaObject::connectSlotsByName(BFSWindow);
    } // setupUi

    void retranslateUi(QWidget *BFSWindow)
    {
        BFSWindow->setWindowTitle(QApplication::translate("BFSWindow", "Form", 0));
    } // retranslateUi

};

namespace Ui {
    class BFSWindow: public Ui_BFSWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BFSWINDOW_H
