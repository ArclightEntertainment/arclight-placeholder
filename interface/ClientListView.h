#ifndef CLIENTLISTVIEW_H
#define CLIENTLISTVIEW_H


#include <QCoreApplication>
#include <QTableWidget>
#include <QPushButton>
#include <QDialog>
#include <QMainWindow>
#include <QDebug>
#include <qstring.h>

#include "ClientManager.h"
#include "ClientDetailDiag.h"

namespace Ui {
class ListView;
}

class ClientListView : public QDialog
{
    Q_OBJECT

public:
    explicit ClientListView(ClientManager *aM, QWidget *parent = 0);
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
    ClientManager *manager;

    void updateListView();
    void resizeCols(int colCount, int * weights);
};

#endif // CLIENTLISTVIEW_H

