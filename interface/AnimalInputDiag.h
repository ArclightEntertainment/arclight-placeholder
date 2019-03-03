#ifndef ANIMALINPUTDIAG_H
#define ANIMALINPUTDIAG_H

#include <QCoreApplication>
#include <QPushButton>
#include <QMessageBox>
#include <QDialog>
#include <QMainWindow>
#include <QDebug>
#include <qstring.h>

#include "AnimalManager.h"

namespace Ui {
class AnimalInputDiag;
}

class AnimalInputDiag : public QDialog
{
    Q_OBJECT

public:
    explicit AnimalInputDiag(AnimalManager *manager, QWidget *parent = 0);
    ~AnimalInputDiag();
private slots:
    void handleButtonSave();
    void handleButtonCancel();
private:
    //UI Elements
    Ui::AnimalInputDiag *ui;
    QPushButton *saveButton;
    QPushButton *cancelButton;
    //pointer to manager
    AnimalManager *aManager;
};

#endif // ANIMALINPUTDIAG_H
