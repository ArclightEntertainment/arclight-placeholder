/********************************************************************************
** Form generated from reading UI file 'listview.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LISTVIEW_H
#define UI_LISTVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_ListView
{
public:
    QTableWidget *animalTableWidget;

    void setupUi(QDialog *ListView)
    {
        if (ListView->objectName().isEmpty())
            ListView->setObjectName(QStringLiteral("ListView"));
        ListView->resize(581, 531);
        animalTableWidget = new QTableWidget(ListView);
        animalTableWidget->setObjectName(QStringLiteral("animalTableWidget"));
        animalTableWidget->setGeometry(QRect(40, 20, 501, 451));

        retranslateUi(ListView);

        QMetaObject::connectSlotsByName(ListView);
    } // setupUi

    void retranslateUi(QDialog *ListView)
    {
        ListView->setWindowTitle(QApplication::translate("ListView", "Animal List", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ListView: public Ui_ListView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LISTVIEW_H
