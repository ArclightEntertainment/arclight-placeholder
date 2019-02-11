#ifndef INPUTDIAG_H
#define INPUTDIAG_H

#include <QCoreApplication>
#include <QPushButton>
#include <QMessageBox>
#include <QDialog>
#include <QMainWindow>
#include <QDebug>
#include <qstring.h>

#include "Animal.h"
#include "AnimalManager.h"

namespace Ui {
class InputDiag;
}

class InputDiag : public QDialog
{
    Q_OBJECT

public:
    explicit InputDiag(AnimalManager *manager, QWidget *parent = 0);
    ~InputDiag();
private slots:
    void handleButtonSave();
    void handleButtonCancel();
    Animal& generateAnimalFromInput();
private:
    Ui::InputDiag *ui;
    QPushButton *saveButton;
    QPushButton *cancelButton;

    AnimalManager *aManager;
};

#endif // INPUTDIAG_H
