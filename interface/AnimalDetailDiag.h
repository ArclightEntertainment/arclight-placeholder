#ifndef ANIMALDETAILDIAG_H
#define ANIMALDETAILDIAG_H

#include <QCoreApplication>
#include <QMessageBox>
#include <QLineEdit>
#include <QTextEdit>
#include <QProgressBar>
#include <QSlider>
#include <QDialog>
#include <QMainWindow>
#include <QDebug>
#include <qstring.h>

#include "CUACSController.h"

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
    bool editMode;
    //UI Elements
    static const int NUMLINES = 21;
    QLineEdit *lineEdits[NUMLINES];
    static const int NUMTEXT = 2;
    QTextEdit *textEdits[NUMTEXT];
    static const int NUMBARS = 9;
    QProgressBar *progBars[NUMBARS];
    QSlider *sliders[NUMBARS];

    Ui::AnimalDetailDiag *ui;
    QPushButton *closeButton;
    QPushButton *editButton;
    //pointer to manager + subject
    CUACSController *mediator;
    Entity *aSubject;
    //update field values, remove edit privileges
    void updateFields();
    void setEditable (bool canEdit);
};
#endif // ANIMALDETAILDIAG_H
