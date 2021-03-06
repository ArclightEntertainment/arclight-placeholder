#ifndef ANIMALListView_H
#define ANIMALListView_H


#include <QCoreApplication>
#include <QTableWidget>
#include <QPushButton>
#include <QDialog>
#include <QMainWindow>
#include <QDebug>
#include <qstring.h>

#include "mytablewidgetitem.h"
#include "interface/CUACSController.h"
#include "AnimalDetailDiag.h"
#include "interface/Attributes.h"

namespace Ui {
class ListView;
}

class AnimalListView : public QDialog
{
    Q_OBJECT

public:
    explicit AnimalListView(CUACSController *med, QWidget *parent = 0);
    ~AnimalListView();

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
    CUACSController *mediator;

    void updateListView();
};

#endif // ANIMALListView_H

