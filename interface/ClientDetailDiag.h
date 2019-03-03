#ifndef CLIENTDETAILDIAG_H
#define CLIENTDETAILDIAG_H


#include <QCoreApplication>
#include <QMessageBox>
#include <QDialog>
#include <QMainWindow>
#include <QDebug>
#include <qstring.h>

#include "ClientManager.h"

namespace Ui {
    class ClientDetailDiag;
}

class ClientDetailDiag : public QDialog
{
    Q_OBJECT

public:
    explicit ClientDetailDiag(ClientManager *manager, Client* subject, QWidget *parent = 0);
    ~ClientDetailDiag();
private slots:
    void handleButtonClose();
private:
    //UI Elements
    const int NUMLINES = 9;
    Ui::ClientDetailDiag *ui;
    QPushButton *closeButton;
    //pointer to manager + subject
    ClientManager *aManager;
    Client *aSubject;
    //update field values, remove edit privileges
    void updateFields();
};

#endif // CLIENTDETAILDIAG_H
