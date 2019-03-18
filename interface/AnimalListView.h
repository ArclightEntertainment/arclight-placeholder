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
#include "AnimalManager.h"
#include "AnimalDetailDiag.h"

namespace Ui {
class ListView;
}

class AnimalListView : public QDialog
{
    Q_OBJECT

public:
    explicit AnimalListView(AnimalManager *aM, QWidget *parent = 0);
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
    AnimalManager *manager;

    void updateListView();
    void resizeCols(int numElements, int * allElements);
};

#endif // ANIMALListView_H

