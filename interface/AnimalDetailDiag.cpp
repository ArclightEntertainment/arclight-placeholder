#include "AnimalDetailDiag.h"
#include "ui_animaldetaildialog.h"
#include <iostream>

//Requires parent widget and manager
AnimalDetailDiag::AnimalDetailDiag(CUACSController *med, Entity *subject, bool canEdit, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AnimalDetailDiag)
{
    ui->setupUi(this);

    closeButton = ui->closeButton;
    editButton = ui->editButton;

    //link buttons and functions
    connect(closeButton, SIGNAL(released()), this,SLOT(handleButtonClose()));
    connect(editButton, SIGNAL(released()), this,SLOT(handleButtonEdit()));

    editMode = canEdit;

    mediator = med;
    aSubject = subject;
    setFields();
    updateFields();
    setEditable(editMode);
}

void AnimalDetailDiag::setFields()
{
    lineEdits[0] = ui->idLineEdit;
    lineEdits[1] = ui->nameLineEdit;
    lineEdits[2] = ui->dietLineEdit;
    lineEdits[3] = ui->mobilityLineEdit;
    lineEdits[4] = ui->disabilityLineEdit;
    lineEdits[5] = ui->expenditureLineEdit;
    lineEdits[6] = ui->breedLineEdit;

    lineEdits[7] = ui->speciesLineEdit;
    lineEdits[8] = ui->sexLineEdit;
    lineEdits[9] = ui->ageLineEdit;
    lineEdits[10] = ui->maxAgeLineEdit;
    lineEdits[11] = ui->immunizedLineEdit;

    lineEdits[12] = ui->energyLineEdit;
    lineEdits[13] = ui->trainingLineEdit;
    lineEdits[14] = ui->trainabilityLineEdit;
    lineEdits[15] = ui->adultAffinityLineEdit;
    lineEdits[16] = ui->childAffinityLineEdit;
    lineEdits[17] = ui->animalAffinityLineEdit;
    lineEdits[18] = ui->approachabilityLineEdit;
    lineEdits[19] = ui->timeCommitmentLineEdit;
    lineEdits[20] = ui->careLineEdit;


    textEdits[0] = ui->bioTextEdit;
    textEdits[1] = ui->historyTextEdit;

    progBars[0] = ui->trainingBar;
    progBars[1] = ui->trainabilityBar;
    progBars[2] = ui->adultAffinityBar;
    progBars[3] = ui->childAffinityBar;
    progBars[4] = ui->animalAffinityBar;
    progBars[5] = ui->approachabilityBar;
    progBars[6] = ui->timeCommitmentBar;
    progBars[7] = ui->energyBar;
    progBars[8] = ui->careBar;


    sliders[0] = ui->trainingSlider;
    sliders[1] = ui->trainabilitySlider;
    sliders[2] = ui->adultAffinitySlider;
    sliders[3] = ui->childAffinitySlider;
    sliders[4] = ui->animalAffinitySlider;
    sliders[5] = ui->approachabilitySlider;
    sliders[6] = ui->timeCommitmentSlider;
    sliders[7] = ui->energySlider;
    sliders[8] = ui->careSlider;

    spinBoxes[0] = ui->ageSpinBox;
    spinBoxes[1] = ui->maxAgeSpinBox;

    comboBoxes[0] = ui->speciesComboBox;
    comboBoxes[1] = ui->sexComboBox;

    checkBoxes[0] = ui->immunizedCheckBox;
}
void AnimalDetailDiag::handleButtonClose()
{
    close();
}

void AnimalDetailDiag::handleButtonEdit()
{
    editMode = !editMode;
    if (editMode == false)
    {
        editButton->setText("Edit");
        updateCurrentAnimal();
    }
    else
    {
        QValidator *textValidator = new QRegExpValidator(QRegExp("([A-Z]|[a-z]|-|.){1,50}"), this);
        QValidator *expValidator = new QRegExpValidator(QRegExp("([0-9]|,){1,50}"), this);

        ui->nameLineEdit->setValidator(textValidator);
        ui->breedLineEdit->setValidator(textValidator);
        ui->expenditureLineEdit->setValidator(expValidator);
        editButton->setText("Save");
    }
    setEditable(editMode);
}

void AnimalDetailDiag::updateCurrentAnimal()
{
/* Need to take all values
 * use setters?
 * Use populate social/history?
*/
    aSubject->setName(ui->nameLineEdit->text().toStdString());
    aSubject->setAge(ui->ageSpinBox->text().toInt());
    aSubject->setInt(5, ui->maxAgeLineEdit->text().toInt());
    aSubject->setString(6, ui->sexComboBox->currentText().toStdString());
    aSubject->setBool(7, ui->immunizedCheckBox->isChecked());
    aSubject->setInt(22, getExpenditureFromUI());
    aSubject->setString(21, ui->bioTextEdit->toPlainText().toStdString());
    aSubject->setString(2, ui->speciesComboBox->currentText().toStdString());
    aSubject->setString(3, ui->breedLineEdit->text().toStdString());
    //species stuff
    aSubject->setString(17,ui->dietLineEdit->text().toStdString());
    aSubject->setString(18,ui->mobilityLineEdit->text().toStdString());
    aSubject->setString(19, ui->disabilityLineEdit->text().toStdString());
    aSubject->setString(20, ui->historyTextEdit->toPlainText().toStdString());

    aSubject->setInt(9, ui->energySlider->value());
    aSubject->setInt(10, ui->trainingSlider->value());
    aSubject->setInt(11, ui->trainabilitySlider->value());
    aSubject->setInt(12, ui->adultAffinitySlider->value());
    aSubject->setInt(13, ui->childAffinitySlider->value());
    aSubject->setInt(14, ui->animalAffinitySlider->value());
    aSubject->setInt(15, ui->approachabilitySlider->value());
    aSubject->setInt(16, ui->timeCommitmentSlider->value());
    aSubject->setInt(8, ui->careSlider->value());

    //aManager->pushAnimalToDB(aManager->indexOfAnimalWithID(aSubject->getShelterID()));

    updateFields();
}

int AnimalDetailDiag::getExpenditureFromUI()
{
    QString inputString = ui->expenditureLineEdit->text();
    QString newString = "";
    for (int i = 0; i < inputString.length(); i++)
    {
        if (inputString[i].isDigit())
        {
            newString.append(inputString[i]);
        }
    }

    if (newString.toInt() > 0)
    {
        return newString.toInt();
    }
    else
    {
        return 0;
    }
}
AnimalDetailDiag::~AnimalDetailDiag()
{
    delete ui;
}

void AnimalDetailDiag::updateFields()
{
    //Fields
    lineEdits[0]->setText(QString::number(aSubject->getID()));
    lineEdits[1]->setText(QString::fromStdString(aSubject->getName()));
    lineEdits[2]->setText(QString::fromStdString(aSubject->getString(17)));
    lineEdits[3]->setText(QString::fromStdString(aSubject->getString(18)));
    lineEdits[4]->setText(QString::fromStdString(aSubject->getString(19)));
    lineEdits[5]->setText(QString::number(aSubject->getInt(22)));
    lineEdits[6]->setText(QString::fromStdString(aSubject->getString(3)));

    lineEdits[7]->setText(QString::fromStdString(aSubject->getString(2)));
    lineEdits[8]->setText(QString::fromStdString(aSubject->getString(6)));
    lineEdits[9]->setText(QString::number(aSubject->getAge()));
    lineEdits[10]->setText(QString::number(aSubject->getInt(5)));
    lineEdits[11]->setText((aSubject->getBool(7)) ? QString("Yes") : QString("No"));

    lineEdits[12]->setText(QString::fromStdString((aSubject->getInt(9) == 0) ? "LOW" : (aSubject->getInt(9) == 1) ? "MEDIUM" : "HIGH"));
    lineEdits[13]->setText(QString::fromStdString((aSubject->getInt(10) == 0) ? "LOW" : (aSubject->getInt(10) == 1) ? "MEDIUM" : "HIGH"));
    lineEdits[14]->setText(QString::fromStdString((aSubject->getInt(11) == 0) ? "LOW" : (aSubject->getInt(11) == 1) ? "MEDIUM" : "HIGH"));
    lineEdits[15]->setText(QString::fromStdString((aSubject->getInt(12) == 0) ? "LOW" : (aSubject->getInt(12) == 1) ? "MEDIUM" : "HIGH"));
    lineEdits[16]->setText(QString::fromStdString((aSubject->getInt(13) == 0) ? "LOW" : (aSubject->getInt(13) == 1) ? "MEDIUM" : "HIGH"));
    lineEdits[17]->setText(QString::fromStdString((aSubject->getInt(14) == 0) ? "LOW" : (aSubject->getInt(14) == 1) ? "MEDIUM" : "HIGH"));
    lineEdits[18]->setText(QString::fromStdString((aSubject->getInt(15) == 0) ? "LOW" : (aSubject->getInt(15) == 1) ? "MEDIUM" : "HIGH"));
    lineEdits[19]->setText(QString::fromStdString((aSubject->getInt(16) == 0) ? "LOW" : (aSubject->getInt(16) == 1) ? "MEDIUM" : "HIGH"));
    lineEdits[20]->setText(QString::fromStdString((aSubject->getInt(8) == 0) ? "LOW" : (aSubject->getInt(8) == 1) ? "MEDIUM" : "HIGH"));

    lineEdits[0]->setReadOnly(true);
    lineEdits[0]->setStyleSheet(QString::fromStdString("background-color: rgb(245, 243, 241);"));

    for (int i = 12; i < NUMLINES; i++)
    {
        lineEdits[i]->setReadOnly(true);
        {
            lineEdits[i]->setStyleSheet(QString::fromStdString("background-color: rgb(245, 243, 241);"));
        }
    }

    textEdits[0]->setText(QString::fromStdString(aSubject->getString(21)));
    textEdits[1]->setText(QString::fromStdString(aSubject->getString(20)));

    sliders[0]->setValue(aSubject->getInt(10));
    sliders[1]->setValue(aSubject->getInt(11));
    sliders[2]->setValue(aSubject->getInt(12));
    sliders[3]->setValue(aSubject->getInt(13));
    sliders[4]->setValue(aSubject->getInt(14));
    sliders[5]->setValue(aSubject->getInt(15));
    sliders[6]->setValue(aSubject->getInt(16));
    sliders[7]->setValue(aSubject->getInt(9));
    sliders[8]->setValue(aSubject->getInt(8));

        progBars[0]->setValue(aSubject->getInt(10));
        progBars[1]->setValue(aSubject->getInt(11));
        progBars[2]->setValue(aSubject->getInt(12));
        progBars[3]->setValue(aSubject->getInt(13));
        progBars[4]->setValue(aSubject->getInt(14));
        progBars[5]->setValue(aSubject->getInt(15));
        progBars[6]->setValue(aSubject->getInt(16));
        progBars[7]->setValue(aSubject->getInt(9));
        progBars[8]->setValue(aSubject->getInt(8));

    spinBoxes[0]->setValue(aSubject->getAge());
    spinBoxes[1]->setValue(aSubject->getInt(5));

    for (int i = 0; i < NUMCOMBO; i++)
    {
        for (int j = 0; j < comboBoxes[i]->count(); j++)
        {
            if (comboBoxes[i]->itemText(j).toStdString() == aSubject->getString(6) || comboBoxes[i]->itemText(j).toStdString() == aSubject->getString(2))
            {
                comboBoxes[i]->setCurrentIndex(j);
            }
        }
    }
    checkBoxes[0]->setChecked(aSubject->getBool(7));
}

void AnimalDetailDiag::setEditable (bool canEdit)
{
    for (int i = 1; i < 12; i++)
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

    for (int i = 0; i < NUMTEXT; i++)
    {
        textEdits[i]->setReadOnly(!canEdit);
        if (canEdit)
        {
            textEdits[i]->setStyleSheet(QString::fromStdString(""));
        }
        else
        {
            textEdits[i]->setStyleSheet(QString::fromStdString("background-color: rgb(245, 243, 241);"));
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

    int numDone = NUMLINES -(NUMBARS+NUMCHECK+NUMCOMBO+NUMSPIN);
    for (int i = 0; i < NUMCOMBO; i++)
    {
        comboBoxes[i]->setMaximumWidth(otherWidth);
        lineEdits[numDone + i]->setMaximumWidth(lineWidth);
    }
    numDone += NUMCOMBO;
    for (int i = 0; i < NUMSPIN; i++)
    {
        spinBoxes[i]->setMaximumWidth(otherWidth);
        lineEdits[numDone + i]->setMaximumWidth(lineWidth);
    }
    numDone += NUMSPIN;
    for (int i = 0; i < NUMCHECK; i++)
    {
        checkBoxes[i]->setCheckable(true);
        checkBoxes[i]->setMaximumWidth(otherWidth);
        lineEdits[numDone + i]->setMaximumWidth(lineWidth);
    }
    for (int i = numDone; i < NUMLINES; i++)
    {
        lineEdits[i]->setMaximumWidth(lineWidth);
    }
    for (int i = 0; i < NUMBARS; i++)
    {
        sliders[i]->setMaximumWidth(otherWidth);
        progBars[i]->setMaximumWidth(lineWidth);
    }
}
