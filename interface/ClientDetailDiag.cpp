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
    quizButton = ui->quizButton;
    //link buttons and functions
    connect(closeButton, SIGNAL(released()), this,SLOT(handleButtonClose()));
    connect(editButton, SIGNAL(released()), this,SLOT(handleButtonEdit()));
    connect(quizButton, SIGNAL(released()), this,SLOT(handleButtonQuiz()));

    mediator = med;
    aSubject = subject;

    editMode = canEdit;

    setFields();
    updateFields();
    setEditable(canEdit);

    std::cout << "call With: " << aSubject->getBool(99) << std::endl;
    //setPreferences(aSubject->getBool(99));
    setPreferences(true);
}

void ClientDetailDiag::setPreferences(bool visible)
{
    int numDone = 10;
    for (int i = 0; i < NUMSPIN; i++)
    {
        spinBoxes[i]->setVisible(visible);
        lineEdits[i + numDone]->setVisible(visible);
    }
    numDone += NUMSPIN;
    for (int i = 0; i < NUMCHECK; i++)
    {
        checkBoxes[i]->setVisible(visible);

        lineEdits[i + numDone]->setVisible(visible);
    }
    numDone += NUMCHECK;
    for (int i = numDone; i < NUMLINES; i++)
    {
        lineEdits[i]->setVisible(visible);
    }
    for (int i = 0; i < NUMBAR; i++)
    {
        sliders[i]->setVisible(visible);
        progBars[i]->setVisible(visible);
    }

    ui->ageLabel        ->setVisible(visible);
    ui->lengthLabel     ->setVisible(visible);
    ui->childrenLabel   ->setVisible(visible);
    ui->petLabel        ->setVisible(visible);
    ui->budgetLabel     ->setVisible(visible);
    ui->timeLabel       ->setVisible(visible);
    ui->mobilityLabel   ->setVisible(visible);
    ui->patienceLabel   ->setVisible(visible);
    ui->experienceLabel ->setVisible(visible);
    ui->affectionLabel  ->setVisible(visible);
}
void ClientDetailDiag::handleButtonQuiz()
{
    QuestionnaireDialog diag(mediator, aSubject, this);
    diag.setWindowTitle("Matching QuestionWidgetnaire");
    diag.exec();
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
        QValidator *numValidator = new QRegExpValidator(QRegExp("([0-9]|,){1,50}"), this);

        ui->cityLineEdit->setValidator(textValidator);
        ui->provLineEdit->setValidator(textValidator);
        ui->countryLineEdit->setValidator(textValidator);
        ui->phoneLineEdit->setValidator(pNumValidator);
        ui->postalLineEdit->setValidator(postValidator);
        ui->budgetLineEdit->setValidator(numValidator);
        ui->timeLineEdit->setValidator(numValidator);

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

    lineEdits[10] = ui->budgetLineEdit;
    lineEdits[11] = ui->timeLineEdit;
    lineEdits[12] = ui->ageLineEdit;
    lineEdits[13] = ui->lengthLineEdit;
    lineEdits[14] = ui->childrenLineEdit;
    lineEdits[15] = ui->petsLineEdit;
    lineEdits[16] = ui->mobilityLineEdit;
    lineEdits[17] = ui->patienceLineEdit;
    lineEdits[18] = ui->experienceLineEdit;
    lineEdits[19] = ui->affectionLineEdit;

    spinBoxes[0] = ui->ageSpinBox;
    spinBoxes[1] = ui->lengthSpinBox;

    checkBoxes[0] = ui->childrenCheckBox;
    checkBoxes[1] = ui->petsCheckBox;

    sliders[0] = ui->mobilitySlider;
    sliders[1] = ui->patienceSlider;
    sliders[2] = ui->experienceSlider;
    sliders[3] = ui->affectionSlider;

    progBars[0] = ui->mobilityBar;
    progBars[1] = ui->patienceBar;
    progBars[2] = ui->experienceBar;
    progBars[3] = ui->affectionBar;

}
void ClientDetailDiag::updateFields()
{
    //Fields

    comboBoxes[0]->setCurrentIndex(comboBoxes[0]->findText(QString::fromStdString(aSubject->getString(6))));

    lineEdits[0]->setText(QString::fromStdString(aSubject->getString(6)));
    lineEdits[1] = ui->nameLineEdit;
    lineEdits[1]->setText(QString::fromStdString(aSubject->getName() + " " + aSubject->getString(5)));
    lineEdits[2] = ui->phoneLineEdit;
    lineEdits[2]->setText(QString::fromStdString(aSubject->getString(7)));
    lineEdits[3]->setText(QString::fromStdString(aSubject->getString(13)));
    lineEdits[4]->setText(QString::fromStdString(aSubject->getString(10)));
    lineEdits[5]->setText(QString::fromStdString(aSubject->getString(11)));
    lineEdits[6]->setText(QString::fromStdString(aSubject->getString(12)));
    lineEdits[7]->setText(QString::fromStdString(aSubject->getString(8)));
    lineEdits[8]->setText(QString::fromStdString(aSubject->getString(9)));
    lineEdits[9]->setText(QString::number(aSubject->getID()));


    //fix values with correct ids
    lineEdits[10]->setText(QString::number(aSubject->getInt(9)));
    lineEdits[11]->setText(QString::number(aSubject->getInt(9)));
    lineEdits[12]->setText(QString::fromStdString(aSubject->getString(9)));
    lineEdits[13]->setText(QString::fromStdString(aSubject->getString(9)));
    lineEdits[14]->setText(QString::number(aSubject->getInt(9)));
    lineEdits[15]->setText(QString::number(aSubject->getInt(9)));
    lineEdits[16]->setText(QString::fromStdString(aSubject->getString(9)));
    lineEdits[17]->setText(QString::fromStdString(aSubject->getString(9)));
    lineEdits[18]->setText(QString::fromStdString(aSubject->getString(9)));
    lineEdits[19]->setText(QString::fromStdString(aSubject->getString(9)));

    spinBoxes[0]->setValue(aSubject->getInt(9));
    spinBoxes[1]->setValue(aSubject->getInt(9));

    checkBoxes[0]->setChecked(aSubject->getBool(0));
    checkBoxes[1]->setChecked(aSubject->getBool(1));

    sliders[0]->setValue(aSubject->getInt(9));
    sliders[1]->setValue(aSubject->getInt(9));
    sliders[2]->setValue(aSubject->getInt(9));
    sliders[3]->setValue(aSubject->getInt(9));

    progBars[0]->setValue(aSubject->getInt(9));
    progBars[1]->setValue(aSubject->getInt(9));
    progBars[2]->setValue(aSubject->getInt(9));
    progBars[3]->setValue(aSubject->getInt(9));

    //update the preference page values here
}
void ClientDetailDiag::updateCurrentClient()
{
    aSubject->setString(6, comboBoxes[0]->currentText().toStdString());

    //handle name updating
    //lineEdits[1]->setText(QString::fromStdString(aSubject->getName() + " " + aSubject->getString(5)));

    std::string nameText = lineEdits[1]->text().toStdString();
    std::string fName = nameText.substr(0, nameText.find(' ', 0));
    std::string lName = nameText.substr(nameText.find(' ', 0) + 1, nameText.length());

    aSubject->setName(fName);
    aSubject->setString(5, lName);

    aSubject->setString(7, lineEdits[2]->text().toStdString());
    aSubject->setString(13, lineEdits[3]->text().toStdString());
    aSubject->setString(10, lineEdits[4]->text().toStdString());
    aSubject->setString(11, lineEdits[5]->text().toStdString());
    aSubject->setString(12, lineEdits[6]->text().toStdString());
    aSubject->setString(8, lineEdits[7]->text().toStdString());
    aSubject->setString(9, lineEdits[8]->text().toStdString());

    aSubject->setInt(5, sliders[0]->value());
    aSubject->setInt(6, sliders[1]->value());
    aSubject->setInt(7, sliders[2]->value());
    aSubject->setInt(8, sliders[3]->value());

    aSubject->setBool(10, checkBoxes[0]->isChecked());
    aSubject->setBool(11, checkBoxes[1]->isChecked());

    updateFields();
}


void ClientDetailDiag::setEditable (bool canEdit)
{
    for (int i = 0; i < NUMLINES; i++)
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

    int maxWidth = 16777215;
    for (int i = 0; i < NUMCOMBO; i++)
    {
        comboBoxes[i]->setMaximumWidth((canEdit) ? 60 : 0);
        lineEdits[i]->setMaximumWidth((canEdit) ? 0 : 40);
    }

    int numDone = 12;
    for (int i = 0; i < NUMSPIN; i++)
    {
        spinBoxes[i]->setMaximumWidth((canEdit) ? 80 : 0);
        lineEdits[i + numDone]->setMaximumWidth((canEdit) ? 0 : 60);
    }
    numDone += NUMSPIN;
    for (int i = 0; i < NUMCHECK; i++)
    {
        checkBoxes[i]->setCheckable(canEdit);
        checkBoxes[i]->setMaximumWidth((canEdit) ? maxWidth : 0);

        lineEdits[i + numDone]->setMaximumWidth((canEdit) ? 0 : 60);
    }
    numDone += NUMCHECK;
    for (int i = numDone; i < NUMLINES; i++)
    {
        lineEdits[i]->setMaximumWidth((canEdit) ? 0 : 60);
    }
    for (int i = 0; i < NUMBAR; i++)
    {
        sliders[i]->setMaximumWidth((canEdit) ? maxWidth : 0);
        progBars[i]->setMaximumWidth((canEdit) ? 0 : maxWidth);
    }
}
