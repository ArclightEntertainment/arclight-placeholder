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

    setPreferences(aSubject->getBool(static_cast<int>(ClientAttribute::POPULATED)));
}
void ClientDetailDiag::handleButtonQuiz()
{
    QuestionnaireDialog diag(mediator, aSubject, this);
    diag.setWindowTitle("Matching QuestionWidgetnaire");
    diag.exec();

    updateFields();
    setEditable(false);
    setPreferences(aSubject->getBool(static_cast<int>(ClientAttribute::POPULATED)));
}
void ClientDetailDiag::setPreferences(bool visible)
{
    int numDone = 10;
    for (int i = numDone; i < NUMLINES; i++)
    {
	lineEdits[i]->setVisible(visible);
    }
    for (int i = 0; i < NUMBAR; i++)
    {
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
	QValidator *numValidator = new QRegExpValidator(QRegExp("([0-9]|,){1,5}"), this);

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

    progBars[0] = ui->mobilityBar;
    progBars[1] = ui->patienceBar;
    progBars[2] = ui->experienceBar;
    progBars[3] = ui->affectionBar;

}
void ClientDetailDiag::updateFields()
{
    //Fields

    comboBoxes[0]->setCurrentIndex(comboBoxes[0]->findText(QString::fromStdString(aSubject->getString(static_cast<int>(ClientAttribute::PREF_TITLE)))));

    lineEdits[0]->setText(QString::fromStdString(aSubject->getString(static_cast<int>(ClientAttribute::PREF_TITLE))));
    lineEdits[1] = ui->nameLineEdit;
    lineEdits[1]->setText(QString::fromStdString(aSubject->getName() + " " + aSubject->getString(static_cast<int>(ClientAttribute::LAST_NAME))));
    lineEdits[2] = ui->phoneLineEdit;
    lineEdits[2]->setText(QString::fromStdString(aSubject->getString(static_cast<int>(ClientAttribute::PHONE_NUMBER))));
    lineEdits[3]->setText(QString::fromStdString(aSubject->getString(static_cast<int>(ClientAttribute::POSTAL_CODE))));
    lineEdits[4]->setText(QString::fromStdString(aSubject->getString(static_cast<int>(ClientAttribute::CITY))));
    lineEdits[5]->setText(QString::fromStdString(aSubject->getString(static_cast<int>(ClientAttribute::SUBNATIONAL_DIVISION))));
    lineEdits[6]->setText(QString::fromStdString(aSubject->getString(static_cast<int>(ClientAttribute::COUNTRY))));
    lineEdits[7]->setText(QString::fromStdString(aSubject->getString(static_cast<int>(ClientAttribute::STREET_LINE_1))));
    lineEdits[8]->setText(QString::fromStdString(aSubject->getString(static_cast<int>(ClientAttribute::STREET_LINE_2))));
    lineEdits[9]->setText(QString::number(aSubject->getID()));


    //fix values with correct ids
    lineEdits[10]->setText(QString::number(aSubject->getInt(static_cast<int>(ClientAttribute::MONTHLY_BUDGET_FOR_ANIMAL))));
    lineEdits[11]->setText(QString::number(aSubject->getInt(static_cast<int>(ClientAttribute::AVAILABILITY_PER_DAY))));
    lineEdits[12]->setText(QString::number(aSubject->getInt(static_cast<int>(ClientAttribute::AGE))));
    lineEdits[13]->setText(QString::number(aSubject->getInt(static_cast<int>(ClientAttribute::LENGTH_OF_OWNERSHIP_EXPECTATION))));
    lineEdits[14]->setText(QString::fromStdString((aSubject->getBool(static_cast<int>(ClientAttribute::HAS_CHILDREN_UNDER_TWELVE))) ? "Yes" : "No"));
    lineEdits[15]->setText(QString::fromStdString((aSubject->getBool(static_cast<int>(ClientAttribute::HAS_PETS))) ? "Yes" : "No"));

    int mob = static_cast<int>(ClientAttribute::LEVEL_OF_MOBILITY);
    int pat = static_cast<int>(ClientAttribute::LEVEL_OF_PATIENCE);
    int pre = static_cast<int>(ClientAttribute::PREVIOUS_EXPERIENCE);
    int phy = static_cast<int>(ClientAttribute::PHYSICAL_AFFECTION);

    lineEdits[16]->setText(QString::number(aSubject->getInt(mob)));
    lineEdits[17]->setText(QString::number(aSubject->getInt(pat)));
    lineEdits[18]->setText(QString::number(aSubject->getInt(pre)));
    lineEdits[19]->setText(QString::number(aSubject->getInt(phy)));

    progBars[0]->setValue(aSubject->getInt(mob));
    progBars[1]->setValue(aSubject->getInt(pat));
    progBars[2]->setValue(aSubject->getInt(pre));
    progBars[3]->setValue(aSubject->getInt(phy));

    //update the preference page values here
}
void ClientDetailDiag::updateCurrentClient()
{
    aSubject->setString(static_cast<int>(ClientAttribute::PREF_TITLE), comboBoxes[0]->currentText().toStdString());

    std::string nameText = lineEdits[1]->text().toStdString();
    std::string fName = nameText.substr(0, nameText.find(' ', 0));
    std::string lName = nameText.substr(nameText.find(' ', 0) + 1, nameText.length());

    aSubject->setName(fName);
    aSubject->setString(static_cast<int>(ClientAttribute::LAST_NAME), lName);

    aSubject->setString(static_cast<int>(ClientAttribute::PHONE_NUMBER), lineEdits[2]->text().toStdString());
    aSubject->setString(static_cast<int>(ClientAttribute::POSTAL_CODE), lineEdits[3]->text().toStdString());
    aSubject->setString(static_cast<int>(ClientAttribute::CITY), lineEdits[4]->text().toStdString());
    aSubject->setString(static_cast<int>(ClientAttribute::SUBNATIONAL_DIVISION), lineEdits[5]->text().toStdString());
    aSubject->setString(static_cast<int>(ClientAttribute::COUNTRY), lineEdits[6]->text().toStdString());
    aSubject->setString(static_cast<int>(ClientAttribute::STREET_LINE_1), lineEdits[7]->text().toStdString());
    aSubject->setString(static_cast<int>(ClientAttribute::STREET_LINE_2), lineEdits[8]->text().toStdString());

    updateFields();
}


void ClientDetailDiag::setEditable (bool canEdit)
{
    for (int i = 0; i < NUMLINES; i++)
    {
	if (canEdit)
	{
	    lineEdits[i]->setReadOnly(canEdit);
            lineEdits[i]->setStyleSheet(QString::fromStdString(""));
        }
	else if (i >= 10 || !canEdit)
        {
	    lineEdits[i]->setReadOnly(canEdit);
            lineEdits[i]->setStyleSheet(QString::fromStdString("background-color: rgb(245, 243, 241);"));
        }
    }

    for (int i = 0; i < NUMCOMBO; i++)
    {
	comboBoxes[i]->setMaximumWidth((canEdit) ? 60 : 0);
	lineEdits[i]->setMaximumWidth((canEdit) ? 0 : 40);
    }
    lineEdits[9]->setReadOnly(true);
    lineEdits[9]->setStyleSheet(QString::fromStdString("background-color: rgb(245, 243, 241);"));
}
