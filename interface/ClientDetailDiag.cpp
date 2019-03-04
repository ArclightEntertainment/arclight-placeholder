#include "ClientDetailDiag.h"
#include "ui_clientdetaildialog.h"
#include <iostream>

//Requires parent widget and manager
ClientDetailDiag::ClientDetailDiag(ClientManager *manager, Client *subject, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ClientDetailDiag)
{
    ui->setupUi(this);

    closeButton = ui->closeButton;

    //link buttons and functions
    connect(closeButton, SIGNAL(released()), this,SLOT(handleButtonClose()));

    aManager = manager;
    aSubject = subject;
    updateFields();
}


void ClientDetailDiag::handleButtonClose()
{
    close();
}

ClientDetailDiag::~ClientDetailDiag()
{
    delete ui;
}

void ClientDetailDiag::updateFields()
{
    //Fields

    QLineEdit *lineEdits[NUMLINES];
    lineEdits[0] = ui->titleLineEdit;
    lineEdits[0]->setText(QString::fromStdString(aSubject->getTitle()));
    lineEdits[1] = ui->nameLineEdit;
    lineEdits[1]->setText(QString::fromStdString(aSubject->getFirstName() + " " + aSubject->getLastName()));
    lineEdits[2] = ui->idLineEdit;
    lineEdits[2]->setText(QString::number(aSubject->getClientID()));
    lineEdits[3] = ui->phoneLineEdit;
    lineEdits[3]->setText(QString::fromStdString(aSubject->getPhoneNumberString()));
    lineEdits[4] = ui->postalLineEdit;
    lineEdits[4]->setText(QString::fromStdString(aSubject->getAddress().getPostalCode()));
    lineEdits[5] = ui->cityLineEdit;
    lineEdits[5]->setText(QString::fromStdString(aSubject->getAddress().getCity()));
    lineEdits[6] = ui->provLineEdit;
    lineEdits[6]->setText(QString::fromStdString(aSubject->getAddress().getSubnationalDivision()));
    lineEdits[7] = ui->countryLineEdit;
    lineEdits[7]->setText(QString::fromStdString(aSubject->getAddress().getCountry()));
    lineEdits[8] = ui->add1LineEdit;
    lineEdits[8]->setText(QString::fromStdString(aSubject->getAddress().getStreetLine1()));
    lineEdits[9] = ui->add2LineEdit;
    lineEdits[9]->setText(QString::fromStdString(aSubject->getAddress().getStreetLine2()));

    for (int i = 0; i < NUMLINES; i++)
    {
        lineEdits[i]->setReadOnly(true);
    }
}
