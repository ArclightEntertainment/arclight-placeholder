#include "ClientDetailDiag.h"
#include "ui_clientdetaildialog.h"
#include <iostream>

//Requires parent widget and manager
ClientDetailDiag::ClientDetailDiag(CUACSController *med, Entity *subject, bool canEdit, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ClientDetailDiag)
{
    ui->setupUi(this);

    closeButton = ui->closeButton;
    editButton = ui->editButton;
    //link buttons and functions
    connect(closeButton, SIGNAL(released()), this,SLOT(handleButtonClose()));
    connect(editButton, SIGNAL(released()), this,SLOT(handleButtonEdit()));

    mediator = med;
    aSubject = subject;

    editMode = canEdit;

    updateFields();
    setEditable(canEdit);
}


void ClientDetailDiag::handleButtonClose()
{
    close();
}
void ClientDetailDiag::handleButtonEdit()
{
    if (editMode == false)
    {
        editButton->setText("Save");
    }
    else
    {
        editButton->setText("Edit");
    }
    editMode = !editMode;
    setEditable(editMode);
}


ClientDetailDiag::~ClientDetailDiag()
{
    delete ui;
}

void ClientDetailDiag::updateFields()
{
    //Fields
//1id, 2fName, 3hasChildrenUnderTwelve, 4hasPets, 5age, 6lName, 7prefTitle, 8phoneNumber, 9streetLine1, 10streetLine2, 11city, 12subnationalDivision, 13country, 14postalCode,
//15lengthOfOwnershipExpectation, 16monthlyBudgetForAnimal, 17availabilityPerDay, 18levelOfMobility, 19levelOfPatience, 20previousExperience, 21physicalAffection
    lineEdits[0] = ui->titleLineEdit;
    lineEdits[0]->setText(QString::fromStdString(aSubject->getString(6)));
    lineEdits[1] = ui->nameLineEdit;
    lineEdits[1]->setText(QString::fromStdString(aSubject->getName() + " " + aSubject->getString(5)));
    lineEdits[2] = ui->phoneLineEdit;
    lineEdits[2]->setText(QString::fromStdString(aSubject->getString(7)));
    lineEdits[3] = ui->postalLineEdit;
    lineEdits[3]->setText(QString::fromStdString(aSubject->getString(13)));
    lineEdits[4] = ui->cityLineEdit;
    lineEdits[4]->setText(QString::fromStdString(aSubject->getString(10)));
    lineEdits[5] = ui->provLineEdit;
    lineEdits[5]->setText(QString::fromStdString(aSubject->getString(11)));
    lineEdits[6] = ui->countryLineEdit;
    lineEdits[6]->setText(QString::fromStdString(aSubject->getString(12)));
    lineEdits[7] = ui->add1LineEdit;
    lineEdits[7]->setText(QString::fromStdString(aSubject->getString(8)));
    lineEdits[8] = ui->add2LineEdit;
    lineEdits[8]->setText(QString::fromStdString(aSubject->getString(9)));
    lineEdits[9] = ui->idLineEdit;
    lineEdits[9]->setText(QString::number(aSubject->getID()));
    lineEdits[9]->setReadOnly(true);
    lineEdits[9]->setStyleSheet(QString::fromStdString("background-color: rgb(245, 243, 241);"));
}
void ClientDetailDiag::updateCurrentClient()
{
    aSubject->setName(ui->nameLineEdit->text.toStdString())
}

void ClientDetailDiag::setEditable (bool canEdit)
{
    for (int i = 0; i < NUMLINES - 1; i++)
    {
        lineEdits[i]->setReadOnly(!canEdit);
        if (canEdit)
        {
            lineEdits[i]->setStyleSheet(QString::fromStdString(""));
        }
        else
        {
            lineEdits[i]->setStyleSheet(QString::fromStdString("background-color: rgb(245, 243, 241);"));
        }
    }
}
