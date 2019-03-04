#include "AnimalDetailDiag.h"
#include "ui_animaldetaildialog.h"
#include <iostream>

//Requires parent widget and manager
AnimalDetailDiag::AnimalDetailDiag(AnimalManager *manager, Animal *subject, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AnimalDetailDiag)
{
    ui->setupUi(this);

    closeButton = ui->closeButton;

    //link buttons and functions
    connect(closeButton, SIGNAL(released()), this,SLOT(handleButtonClose()));

    aManager = manager;
    aSubject = subject;
    updateFields();
}


void AnimalDetailDiag::handleButtonClose()
{
    close();
}

AnimalDetailDiag::~AnimalDetailDiag()
{
    delete ui;
}

void AnimalDetailDiag::updateFields()
{
    //Fields
    QLineEdit *lineEdits[NUMLINES];
    lineEdits[0] = ui->nameLineEdit;
    lineEdits[0]->setText(QString::fromStdString(aSubject->getName()));
    lineEdits[1] = ui->idLineEdit;
    lineEdits[1]->setText(QString::number(aSubject->getShelterID()));
    lineEdits[2] = ui->speciesLineEdit;
    lineEdits[2]->setText(QString::fromStdString(aSubject->getSpecies()));
    lineEdits[3] = ui->breedLineEdit;
    lineEdits[3]->setText(QString::fromStdString(aSubject->getBreed()));
    lineEdits[4] = ui->sexLineEdit;
    lineEdits[4]->setText(QString::fromStdString(aSubject->getSexString()));
    lineEdits[5] = ui->ageLineEdit;
    lineEdits[5]->setText(QString::number(aSubject->getAge()));
    lineEdits[6] = ui->careLineEdit;
    lineEdits[6]->setText(QString::fromStdString(aSubject->getLevelOfCareString()));
    lineEdits[7] = ui->trainingLineEdit;
    lineEdits[7]->setText(QString::fromStdString(aSubject->getTrainingString()));
    lineEdits[8] = ui->trainabilityLineEdit;
    lineEdits[8]->setText(QString::fromStdString(aSubject->getTrainabilityString()));
    lineEdits[9] = ui->adultAffinityLineEdit;
    lineEdits[9]->setText(QString::fromStdString(aSubject->getAffForPeopleString()));
    lineEdits[10] = ui->childAffinityLineEdit;
    lineEdits[10]->setText(QString::fromStdString(aSubject->getAffForChildrenString()));
    lineEdits[11] = ui->animalAffinityLineEdit;
    lineEdits[11]->setText(QString::fromStdString(aSubject->getAffForAnimalsString()));
    lineEdits[12] = ui->approachabilityLineEdit;
    lineEdits[12]->setText(QString::fromStdString(aSubject->getApproachabilityString()));
    lineEdits[13] = ui->timeCommitmentLineEdit;
    lineEdits[13]->setText(QString::fromStdString(aSubject->getTimeCommitmentString()));
    lineEdits[14] = ui->dietLineEdit;
    lineEdits[14]->setText(QString::fromStdString(aSubject->getDietNeeds()));
    lineEdits[15] = ui->mobilityLineEdit;
    lineEdits[15]->setText(QString::fromStdString(aSubject->getMobilityNeeds()));
    lineEdits[16] = ui->disabilityLineEdit;
    lineEdits[16]->setText(QString::fromStdString(aSubject->getDisabilityNeeds()));
    lineEdits[17] = ui->immunizedLineEdit;
    lineEdits[17]->setText((aSubject->isImmunized()) ? QString("Yes") : QString("No"));
    lineEdits[18] = ui->expenditureLineEdit;
    lineEdits[18]->setText(QString::number(aSubject->getEstimatedCost()));

    for (int i = 0; i < NUMLINES; i++)
    {
        lineEdits[i]->setReadOnly(true);
    }


    QTextEdit *textEdits[NUMTEXT];
    textEdits[0] = ui->bioTextEdit;
    textEdits[0]->setText(QString::fromStdString(aSubject->getBiography()));
    textEdits[1] = ui->historyTextEdit;
    textEdits[1]->setText(QString::fromStdString(aSubject->getAbuseHistory()));

    for (int i = 0; i < NUMTEXT; i++)
    {
        textEdits[i]->setReadOnly(true);
    }


    QProgressBar *progBars[NUMBARS];
    progBars[0] = ui->trainingBar;
    progBars[0]->setValue(aSubject->getTrainingLevel());
    qDebug() << "TrainingLevel: " << progBars[0]->value() << " " << aSubject->getTrainingLevel();
    progBars[1] = ui->trainabilityBar;
    progBars[1]->setValue(aSubject->getTrainabilityLevel());
    qDebug() << "TrainabilityLevel: " << progBars[1]->value() << " " << aSubject->getTrainabilityLevel();
    progBars[2] = ui->adultAffinityBar;
    progBars[2]->setValue(aSubject->getAffForPeople());
    qDebug() << "adultAff: " << progBars[2]->value() << " " << aSubject->getAffForPeople();
    progBars[3] = ui->childAffinityBar;
    progBars[3]->setValue(aSubject->getAffForChildren());
    qDebug() << "childAff: " << progBars[3]->value() << " " << aSubject->getAffForChildren();
    progBars[4] = ui->animalAffinityBar;
    progBars[4]->setValue(aSubject->getAffForAnimals());
    qDebug() << "animAff: " << progBars[4]->value() << " " << aSubject->getAffForAnimals();
    progBars[5] = ui->approachabilityBar;
    progBars[5]->setValue(aSubject->getApproachability());
    qDebug() << "Approach: " << progBars[5]->value() << " " << aSubject->getApproachability();
    progBars[6] = ui->timeCommitmentBar;
    progBars[6]->setValue(aSubject->getTimeCommitment());
    qDebug() << "timeComm: " << progBars[6]->value() << " " << aSubject->getTimeCommitment();
}
