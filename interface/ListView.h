#ifndef LISTVIEW_H
#define LISTVIEW_H


#include <QCoreApplication>
#include <QTableWidget>
#include <QPushButton>
#include <QDialog>
#include <QMainWindow>
#include <QDebug>
#include <qstring.h>

#include "AnimalManager.h"
#include "animaldetaildiag.h"

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
    void handleButtonClose();
    void handleButtonDetail();
private:
    //important UI Elements
    Ui::ListView *ui;
    QTableWidget *animalList;
    QPushButton *closeButton;
    QPushButton *detailsButton;

    //pointer to Animal Manager
    AnimalManager *manager;

    void updateListView();
};

#endif // LISTVIEW_H

