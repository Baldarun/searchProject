/********************************************************************************
** Form generated from reading UI file 'mapoptions.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAPOPTIONS_H
#define UI_MAPOPTIONS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MapOptions
{
public:
    QPushButton *newMap;
    QPushButton *keepButton;

    void setupUi(QWidget *MapOptions)
    {
        if (MapOptions->objectName().isEmpty())
            MapOptions->setObjectName(QStringLiteral("MapOptions"));
        MapOptions->resize(400, 300);
        newMap = new QPushButton(MapOptions);
        newMap->setObjectName(QStringLiteral("newMap"));
        newMap->setGeometry(QRect(20, 10, 101, 23));
        keepButton = new QPushButton(MapOptions);
        keepButton->setObjectName(QStringLiteral("keepButton"));
        keepButton->setGeometry(QRect(154, 10, 91, 23));

        retranslateUi(MapOptions);

        QMetaObject::connectSlotsByName(MapOptions);
    } // setupUi

    void retranslateUi(QWidget *MapOptions)
    {
        MapOptions->setWindowTitle(QApplication::translate("MapOptions", "Form", 0));
        newMap->setText(QApplication::translate("MapOptions", "Generate New Map", 0));
        keepButton->setText(QApplication::translate("MapOptions", "Keep This Map", 0));
    } // retranslateUi

};

namespace Ui {
    class MapOptions: public Ui_MapOptions {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAPOPTIONS_H
