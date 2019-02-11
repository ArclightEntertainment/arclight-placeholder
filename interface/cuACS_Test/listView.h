#ifndef LISTVIEW_H
#define LISTVIEW_H


#include <QCoreApplication>
#include <QTableWidget>
#include <QPushButton>
#include <QDialog>
#include <QMainWindow>
#include <QDebug>
#include <qstring.h>

#include "animalmanager.h"

namespace Ui {
class ListView;
}

class ListView : public QDialog
{
    Q_OBJECT

public:
    explicit ListView(AnimalManager *aM, QWidget *parent = 0);
    ~ListView();
private slots:
    void updateListView();
private:
    Ui::ListView *ui;
    QTableWidget *animalList;

    AnimalManager *manager;
};

#endif // LISTVIEW_H

