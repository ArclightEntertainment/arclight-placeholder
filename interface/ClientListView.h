#ifndef CLIENTLISTVIEW_H
#define CLIENTLISTVIEW_H


#include <QCoreApplication>
#include <QTableWidget>
#include <QPushButton>
#include <QDialog>
#include <QMainWindow>
#include <QDebug>
#include <qstring.h>

#include "interface/CUACSController.h"
#include "interface/ClientDetailDiag.h"
#include "interface/Attributes.h"

namespace Ui {
class ListView;
}

class ClientListView : public QDialog
{
    Q_OBJECT

public:
    explicit ClientListView(CUACSController *med, QWidget *parent = 0);
    ~ClientListView();

private slots:
    void handleButtonClose();
    void handleButtonDetail();
private:
    //important UI Elements
    Ui::ListView *ui;
    QTableWidget *clientList;
    QPushButton *closeButton;
    QPushButton *detailsButton;

    //pointer to Animal Manager
    CUACSController *mediator;

    void updateListView();
};

#endif // CLIENTLISTVIEW_H

