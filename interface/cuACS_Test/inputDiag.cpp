#include "inputDiag.h"
#include "ui_inputdialog.h"

InputDiag::InputDiag(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InputDiag)
{
    ui->setupUi(this);

    saveButton = ui->saveButton;
    cancelButton = ui->cancelButton;

    connect(saveButton, SIGNAL(released()), this,SLOT(handleButtonSave()));
    connect(cancelButton, SIGNAL(released()), this,SLOT(handleButtonCancel()));
}

void InputDiag::handleButtonSave()
{
    //important values
    bool name = !ui->nameLineEdit->text().isEmpty();
    bool species = QString::compare(ui->speciesSelector->currentText(), "Species");  //!= Species
    bool sex = QString::compare(ui->sexSelector->currentText(), "Sex");  //!= Sex
    bool age = QString::compare(ui->ageSpinBox->text(), "0");

    //verify -> populate
    if (name && species && sex && age)
    {
        // qDebug() << "Name: "    << ui->nameLineEdit->text();
        // qDebug() << "Species: " << ui->speciesSelector->currentText();
        // qDebug() << "Sex: "     << ui->sexSelector->currentText();
        // qDebug() << "Age: "     << ui->ageSpinBox->text()                << "\n";
        Animal *newAnimal = new Animal(
                    ui->nameLineEdit->text().toStdString(),
                    ui->ageSpinBox->text().toInt(),
                    ui->sexSelector->currentText().at(0).toLatin1(),
                    ui->speciesSelector->currentText().toStdString(),
                    ui->breedLineEdit->text().toStdString()
                    );
        qDebug() << QString::fromStdString(newAnimal->getName());
        close();
    } else {
//Make a warning dialog
    }
}
void InputDiag::handleButtonCancel()
{
    close();
}
InputDiag::~InputDiag()
{
    delete ui;
}
