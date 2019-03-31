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

    setFields();
    updateFields();
    setEditable(canEdit);
}


void ClientDetailDiag::handleButtonClose()
{
    close();
}
void ClientDetailDiag::handleButtonEdit()
{
    editMode = !editMode;
    if (editMode == false)
    {
        editButton->setText("Edit");
        updateCurrentClient();
    }
    else
    {

        QValidator *pNumValidator = new QRegExpValidator(QRegExp("([0-9]|-|\\)|\\(|\\ ){1,20}"), this);
        QValidator *postValidator = new QRegExpValidator(QRegExp("([0-9]|[a-z]|[A-Z]|\\ ){1,7}"), this);
        QValidator *textValidator = new QRegExpValidator(QRegExp("([A-Z]|[a-z]|-|.){1,50}"), this);

        ui->cityLineEdit->setValidator(textValidator);
        ui->provLineEdit->setValidator(textValidator);
        ui->countryLineEdit->setValidator(textValidator);
        ui->phoneLineEdit->setValidator(pNumValidator);
        ui->postalLineEdit->setValidator(postValidator);

        ui->nameLineEdit->setValidator(textValidator);
        editButton->setText("Save");
    }
    setEditable(editMode);


}


ClientDetailDiag::~ClientDetailDiag()
{
    delete ui;
}

void ClientDetailDiag::setFields(){
    comboBoxes[0] = ui->titleComboBox;
    lineEdits[0] = ui->titleLineEdit;
    lineEdits[1] = ui->nameLineEdit;
    lineEdits[2] = ui->phoneLineEdit;
    lineEdits[3] = ui->postalLineEdit;
    lineEdits[4] = ui->cityLineEdit;
    lineEdits[5] = ui->provLineEdit;
    lineEdits[6] = ui->countryLineEdit;
    lineEdits[7] = ui->add1LineEdit;
    lineEdits[8] = ui->add2LineEdit;
    lineEdits[9] = ui->idLineEdit;
    lineEdits[9]->setReadOnly(true);
    lineEdits[9]->setStyleSheet(QString::fromStdString("background-color: rgb(245, 243, 241);"));

    //declare preference values here
}
void ClientDetailDiag::updateFields()
{
    //Fields
//1id, 2fName, 3hasChildrenUnderTwelve, 4hasPets, 5age, 6lName, 7prefTitle, 8phoneNumber, 9streetLine1, 10streetLine2, 11city, 12subnationalDivision, 13country, 14postalCode,
//15lengthOfOwnershipExpectation, 16monthlyBudgetForAnimal, 17availabilityPerDay, 18levelOfMobility, 19levelOfPatience, 20previousExperience, 21physicalAffection

    comboBoxes[0]->setCurrentIndex(comboBoxes[0]->findText(QString::fromStdString(aSubject->getString(6))));

    lineEdits[0]->setText(QString::fromStdString(aSubject->getString(6)));
    lineEdits[1]->setText(QString::fromStdString(aSubject->getName() + " " + aSubject->getString(5)));
    lineEdits[2]->setText(QString::fromStdString(aSubject->getString(7)));
    lineEdits[3]->setText(QString::fromStdString(aSubject->getString(13)));
    lineEdits[4]->setText(QString::fromStdString(aSubject->getString(10)));
    lineEdits[5]->setText(QString::fromStdString(aSubject->getString(11)));
    lineEdits[6]->setText(QString::fromStdString(aSubject->getString(12)));
    lineEdits[7]->setText(QString::fromStdString(aSubject->getString(8)));
    lineEdits[8]->setText(QString::fromStdString(aSubject->getString(9)));
    lineEdits[9]->setText(QString::number(aSubject->getID()));

    //update the preference page values here
}
void ClientDetailDiag::updateCurrentClient()
{
    aSubject->setString(6, comboBoxes[0]->currentText().toStdString());

    //handle name updating
    //lineEdits[1]->setText(QString::fromStdString(aSubject->getName() + " " + aSubject->getString(5)));

    aSubject->setString(7, lineEdits[2]->text().toStdString());
    aSubject->setString(13, lineEdits[3]->text().toStdString());
    aSubject->setString(10, lineEdits[4]->text().toStdString());
    aSubject->setString(11, lineEdits[5]->text().toStdString());
    aSubject->setString(12, lineEdits[6]->text().toStdString());
    aSubject->setString(8, lineEdits[7]->text().toStdString());
    aSubject->setString(9, lineEdits[8]->text().toStdString());

    updateFields();
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

    int lineWidth = 16777215;
    int otherWidth = 0;
    if (canEdit)
    {
        lineWidth = 0;
        otherWidth = 16777215;
    }
    /*Need to:
    1. Species, Sex, Age, Max Age, Immunized. Set line Edits to 0, Set other to INTEGER_MAX_INT
    2. Sliders Set Progress Bars to 0, other to MAX
    number of ineditable == NUMLINES -(NUMBARS+NUMCHECK+NUMCOMBO+NUMSPIN)
    */

    //int numDone = NUMLINES -(NUMBARS+NUMCHECK+NUMCOMBO+NUMSPIN);
    int numDone = NUMLINES - NUMCOMBO;
    for (int i = 0; i < NUMCOMBO; i++)
    {
        comboBoxes[i]->setMaximumWidth((editMode) ? 60 : 0);
        lineEdits[i]->setMaximumWidth((editMode) ? 0 : 40);
    }
    numDone += NUMCOMBO;
    //for (int i = 0; i < NUMSPIN; i++)
    //{
    //    spinBoxes[i]->setMaximumWidth(otherWidth);
    //}
    //numDone += NUMSPIN;
    //for (int i = 0; i < NUMCHECK; i++)
    //{
    //    checkBoxes[i]->setCheckable(true);
    //    checkBoxes[i]->setMaximumWidth(otherWidth);
    //}
    for (int i = numDone; i < NUMLINES; i++)
    {
        lineEdits[i]->setMaximumWidth((lineWidth > otherWidth) ? lineWidth : otherWidth);
    }
    //for (int i = 0; i < NUMBARS; i++)
    //{
    //    sliders[i]->setMaximumWidth(otherWidth);
    //    progBars[i]->setMaximumWidth(lineWidth);
    //}
}
