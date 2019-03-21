#include "AnimalDetailDiag.h"
#include "ui_animaldetaildialog.h"
#include <iostream>

//Requires parent widget and manager
AnimalDetailDiag::AnimalDetailDiag(AnimalManager *manager, Animal *subject, bool canEdit, QWidget *parent) :
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

    aManager = manager;
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


    lineEdits[0]->setText(QString::number(aSubject->getShelterID()));
    lineEdits[1]->setText(QString::fromStdString(aSubject->getName()));
    lineEdits[2]->setText(QString::fromStdString(aSubject->getDietNeeds()));
    lineEdits[3]->setText(QString::fromStdString(aSubject->getMobilityNeeds()));
    lineEdits[4]->setText(QString::fromStdString(aSubject->getDisabilityNeeds()));
    lineEdits[5]->setText(QString::number(aSubject->getEstimatedCost()));
    lineEdits[6]->setText(QString::fromStdString(aSubject->getBreed()));

    lineEdits[7]->setText(QString::fromStdString(aSubject->getSpecies()));
    lineEdits[8]->setText(QString::fromStdString(aSubject->getSexString()));
    lineEdits[9]->setText(QString::number(aSubject->getAge()));
    lineEdits[10]->setText(QString::number(aSubject->getLifeExpectancy()));
    lineEdits[11]->setText((aSubject->isImmunized()) ? QString("Yes") : QString("No"));

    lineEdits[12]->setText(QString::fromStdString(aSubject->getLevelOfEnergyString()));
    lineEdits[13]->setText(QString::fromStdString(aSubject->getTrainingString()));
    lineEdits[14]->setText(QString::fromStdString(aSubject->getTrainabilityString()));
    lineEdits[15]->setText(QString::fromStdString(aSubject->getAffForPeopleString()));
    lineEdits[16]->setText(QString::fromStdString(aSubject->getAffForChildrenString()));
    lineEdits[17]->setText(QString::fromStdString(aSubject->getAffForAnimalsString()));
    lineEdits[18]->setText(QString::fromStdString(aSubject->getApproachabilityString()));
    lineEdits[19]->setText(QString::fromStdString(aSubject->getTimeCommitmentString()));
    lineEdits[20]->setText(QString::fromStdString(aSubject->getLevelOfCareString()));


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
    aSubject->setLifeExpectancy(ui->maxAgeLineEdit->text().toInt());
    aSubject->setSex((ui->sexComboBox->currentText().toStdString() == "Female") ? 'F' : 'M');
    aSubject->setImmunized(ui->immunizedCheckBox->isChecked());
    aSubject->setEstimatedCost(getExpenditureFromUI());
    aSubject->setBiography(ui->bioTextEdit->toPlainText().toStdString());
    //species stuff

    aSubject->setDietNeeds(ui->dietLineEdit->text().toStdString());
    aSubject->setMobilityNeeds(ui->mobilityLineEdit->text().toStdString());
    aSubject->setDisabilityNeeds(ui->disabilityLineEdit->text().toStdString());
    aSubject->setAbuseHistory(ui->historyTextEdit->toPlainText().toStdString());

    aSubject->setEnergy(ui->energySlider->value());
    aSubject->setTrainability(ui->trainabilitySlider->value());
    aSubject->setTraining(ui->trainingSlider->value());
    aSubject->setAffForAdults(ui->adultAffinitySlider->value());
    aSubject->setAffForChildren(ui->childAffinitySlider->value());
    aSubject->setAffForAnimals(ui->animalAffinitySlider->value());
    aSubject->setApproachability(ui->approachabilitySlider->value());
    aSubject->setTimeCommitment(ui->timeCommitmentSlider->value());
    aSubject->setCareLevel(ui->careSlider->value());

    if (aManager->indexOfAnimalWithID(aSubject->getShelterID()) >= 0)
    {
        aManager->pushAnimalToDB(aManager->indexOfAnimalWithID(aSubject->getShelterID()));
    }
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
    lineEdits[0]->setText(QString::number(aSubject->getShelterID()));
    lineEdits[1]->setText(QString::fromStdString(aSubject->getName()));
    lineEdits[2]->setText(QString::fromStdString(aSubject->getDietNeeds()));
    lineEdits[3]->setText(QString::fromStdString(aSubject->getMobilityNeeds()));
    lineEdits[4]->setText(QString::fromStdString(aSubject->getDisabilityNeeds()));
    lineEdits[5]->setText(QString::number(aSubject->getEstimatedCost()));
    lineEdits[6]->setText(QString::fromStdString(aSubject->getBreed()));

    lineEdits[7]->setText(QString::fromStdString(aSubject->getSpecies()));
    lineEdits[8]->setText(QString::fromStdString(aSubject->getSexString()));
    lineEdits[9]->setText(QString::number(aSubject->getAge()));
    lineEdits[10]->setText(QString::number(aSubject->getLifeExpectancy()));
    lineEdits[11]->setText((aSubject->isImmunized()) ? QString("Yes") : QString("No"));

    lineEdits[12]->setText(QString::fromStdString(aSubject->getLevelOfEnergyString()));
    lineEdits[13]->setText(QString::fromStdString(aSubject->getTrainingString()));
    lineEdits[14]->setText(QString::fromStdString(aSubject->getTrainabilityString()));
    lineEdits[15]->setText(QString::fromStdString(aSubject->getAffForPeopleString()));
    lineEdits[16]->setText(QString::fromStdString(aSubject->getAffForChildrenString()));
    lineEdits[17]->setText(QString::fromStdString(aSubject->getAffForAnimalsString()));
    lineEdits[18]->setText(QString::fromStdString(aSubject->getApproachabilityString()));
    lineEdits[19]->setText(QString::fromStdString(aSubject->getTimeCommitmentString()));
    lineEdits[20]->setText(QString::fromStdString(aSubject->getLevelOfCareString()));

    lineEdits[0]->setReadOnly(true);
    lineEdits[0]->setStyleSheet(QString::fromStdString("background-color: rgb(245, 243, 241);"));

    for (int i = 12; i < NUMLINES; i++)
    {
        lineEdits[i]->setReadOnly(true);
        {
            lineEdits[i]->setStyleSheet(QString::fromStdString("background-color: rgb(245, 243, 241);"));
        }
    }

    textEdits[0]->setText(QString::fromStdString(aSubject->getBiography()));
    textEdits[1]->setText(QString::fromStdString(aSubject->getAbuseHistory()));

    sliders[0]->setValue(aSubject->getTrainingLevel());
    sliders[1]->setValue(aSubject->getTrainabilityLevel());
    sliders[2]->setValue(aSubject->getAffForPeople());
    sliders[3]->setValue(aSubject->getAffForChildren());
    sliders[4]->setValue(aSubject->getAffForAnimals());
    sliders[5]->setValue(aSubject->getApproachability());
    sliders[6]->setValue(aSubject->getTimeCommitment());
    sliders[7]->setValue(aSubject->getLevelOfEnergy());
    sliders[8]->setValue(aSubject->getLevelOfCare());

    for (int i = 0; i < NUMBARS; i++)
    {
        progBars[i]->setValue(sliders[i]->value());
    }

    spinBoxes[0]->setValue(aSubject->getAge());
    spinBoxes[1]->setValue(aSubject->getLifeExpectancy());

    for (int i = 0; i < NUMCOMBO; i++)
    {
        for (int j = 0; j < comboBoxes[i]->count(); j++)
        {
            if (comboBoxes[i]->itemText(j).toStdString() == aSubject->getSexString() || comboBoxes[i]->itemText(j).toStdString() == aSubject->getSpecies())
            {
                comboBoxes[i]->setCurrentIndex(j);
            }
        }
    }
    checkBoxes[0]->setChecked(aSubject->isImmunized());
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
