#ifndef ANIMALDETAILDIAG_H
#define ANIMALDETAILDIAG_H

#include <QCoreApplication>
#include <QMessageBox>
#include <QLineEdit>
#include <QTextEdit>
#include <QProgressBar>
#include <QSlider>
#include <QSpinBox>
#include <QComboBox>
#include <QCheckBox>
#include <QDialog>
#include <QMainWindow>
#include <QDebug>
#include <qstring.h>

#include "CUACSController.h"
#include "interface/Attributes.h"

namespace Ui {
    class AnimalDetailDiag;
}

class AnimalDetailDiag : public QDialog
{
    Q_OBJECT

public:
    explicit AnimalDetailDiag(CUACSController *med, Entity* subject, bool canEdit=false, QWidget *parent = 0);
    ~AnimalDetailDiag();
private slots:
    void handleButtonClose();
    void handleButtonEdit();
private:
private:
    bool editMode;
    //UI Elements
    static const int NUMLINES = 21;
    static const int NUMTEXT = 2;
    static const int NUMBARS = 9;
    static const int NUMSPIN = 2;
    static const int NUMCOMBO = 2;
    static const int NUMCHECK = 1;

    QLineEdit *lineEdits[NUMLINES];
    QTextEdit *textEdits[NUMTEXT];
    QProgressBar *progBars[NUMBARS];
    QSlider *sliders[NUMBARS];
    QSpinBox *spinBoxes[NUMSPIN];
    QComboBox *comboBoxes[NUMCOMBO];
    QCheckBox *checkBoxes[NUMCHECK];


    Ui::AnimalDetailDiag *ui;
    QPushButton *closeButton;
    QPushButton *editButton;
    //pointer to manager + subject
    CUACSController *mediator;
    Entity *aSubject;
    //update field values, remove edit privileges
    void updateFields();
    void updateCurrentAnimal();
    void setEditable (bool canEdit);
    void setFields();
    int getExpenditureFromUI();
};
#endif // ANIMALDETAILDIAG_H
