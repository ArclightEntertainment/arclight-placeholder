#ifndef CLIENTDETAILDIAG_H
#define CLIENTDETAILDIAG_H


#include <QCoreApplication>
#include <QMessageBox>
#include <QDialog>
#include <QLineEdit>
#include <QMainWindow>
#include <QDebug>
#include <qstring.h>

#include "CUACSController.h"

namespace Ui {
    class ClientDetailDiag;
}

class ClientDetailDiag : public QDialog
{
    Q_OBJECT

public:
    explicit ClientDetailDiag(CUACSController *med, Entity* subject, bool canEdit=false, QWidget *parent = 0);
    ~ClientDetailDiag();
private slots:
    void handleButtonClose();
    void handleButtonEdit();
private:
    //UI Elements
    static const int NUMLINES = 11;
    Ui::ClientDetailDiag *ui;
    QPushButton *closeButton;
    QPushButton *editButton;

    QLineEdit *lineEdits[NUMLINES];
    //pointer to manager + subject
    CUACSController *mediator;
    Entity *aSubject;
    //update field values, remove edit privileges
    bool editMode;
    void updateFields();
    std::string getPhoneNumberFromUI();
    void updateCurrentClient();
    void parseName();

    void setEditable (bool canEdit);
};

#endif // CLIENTDETAILDIAG_H
