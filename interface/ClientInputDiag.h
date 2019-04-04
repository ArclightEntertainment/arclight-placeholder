#ifndef CLIENTINPUTDIAG_H
#define CLIENTINPUTDIAG_H

#include <QCoreApplication>
#include <QPushButton>
#include <QMessageBox>
#include <QDialog>
#include <QMainWindow>
#include <QDebug>
#include <qstring.h>

#include "CUACSController.h"
#include "interface/Attributes.h"

namespace Ui {
class ClientInputDiag;
}

class ClientInputDiag : public QDialog
{
    Q_OBJECT

public:
    explicit ClientInputDiag(CUACSController* med, QWidget *parent = 0);
    ~ClientInputDiag();

private slots:
    void handleButtonSave();
    void handleButtonCancel();
private:
    Ui::ClientInputDiag *ui;
    QPushButton *saveButton;
    QPushButton *cancelButton;

    CUACSController* mediator;

    int newClientID;

    bool checkInputValid();
    std::string getPhoneNumberFromUI();
};

#endif // CLIENTINPUTDIAG_H
