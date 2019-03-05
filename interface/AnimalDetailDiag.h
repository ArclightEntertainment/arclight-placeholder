#ifndef ANIMALDETAILDIAG_H
#define ANIMALDETAILDIAG_H

#include <QCoreApplication>
#include <QMessageBox>
#include <QDialog>
#include <QMainWindow>
#include <QDebug>
#include <qstring.h>

#include "AnimalManager.h"

namespace Ui {
    class AnimalDetailDiag;
}

class AnimalDetailDiag : public QDialog
{
    Q_OBJECT

public:
    explicit AnimalDetailDiag(AnimalManager *manager, Animal* subject, QWidget *parent = 0);
    ~AnimalDetailDiag();
private slots:
    void handleButtonClose();
private:
    //UI Elements
    const int NUMLINES = 20;
    const int NUMTEXT = 2;
    const int NUMBARS = 7;
    Ui::AnimalDetailDiag *ui;
    QPushButton *closeButton;
    //pointer to manager + subject
    AnimalManager *aManager;
    Animal *aSubject;
    //update field values, remove edit privileges
    void updateFields();
};
#endif // ANIMALDETAILDIAG_H
