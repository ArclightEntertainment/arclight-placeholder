#ifndef ACMListView_H
#define ACMListView_H


#include <QCoreApplication>
#include <QTableWidget>
#include <QPushButton>
#include <QDialog>
#include <QMainWindow>
#include <QDebug>
#include <qstring.h>

#include "mytablewidgetitem.h"
#include "interface/CUACSController.h"
#include "interface/Attributes.h"

#include "interface/CandidateSet.h"

namespace Ui {
class ListView;
}

class ACMListView : public QDialog
{
    Q_OBJECT

public:
    explicit ACMListView(CUACSController *med, QWidget *parent = 0);
    ~ACMListView();

private slots:
    void handleButtonClose();
    void handleButtonDetail();
private:
    //important UI Elements
    Ui::ListView *ui;
    QTableWidget *acmList;
    QPushButton *closeButton;
    QPushButton *detailsButton;

    //pointer to Animal Manager
    CUACSController *mediator;

    CandidateSet * candidateSet;

    void updateListView();
};

#endif // ACMListView_H

