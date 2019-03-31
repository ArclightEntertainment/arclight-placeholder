#ifndef CLIENTDETAILDIAG_H
#define CLIENTDETAILDIAG_H


#include <QCoreApplication>
#include <QMessageBox>
#include <QDialog>
#include <QLineEdit>
#include <QComboBox>
#include <QMainWindow>
#include <QDebug>
#include <qstring.h>

#include "CUACSController.h"

namespace Ui {
    class ClientDetailDiag;
}

class ClientDetailDiag : public QDialog
{
    Q_OBJECT

public:
    explicit ClientDetailDiag(CUACSController *med, Entity* subject, bool canEdit=false, QWidget *parent = 0);
    ~ClientDetailDiag();
private slots:
    void handleButtonClose();
    void handleButtonEdit();
private:
    //UI Elements
    static const int NUMLINES = 10;
    static const int NUMCOMBO = 1;

    QLineEdit *lineEdits[NUMLINES];
    QComboBox *comboBoxes[NUMCOMBO];

    Ui::ClientDetailDiag *ui;
    QPushButton *closeButton;
    QPushButton *editButton;

    //pointer to manager + subject
    CUACSController *mediator;
    Entity *aSubject;
    //update field values, remove edit privileges
    bool editMode;
    void setFields();
    void updateFields();
    std::string getPhoneNumberFromUI();

    void setEditable (bool canEdit);
    void updateCurrentClient();
};

#endif // CLIENTDETAILDIAG_H

/*
 * 1id, 2fName,
 * 6lName, 7prefTitle, 8phoneNumber, 9streetLine1, 10streetLine2, 11city, 12subnationalDivision, 13country, 14postalCode,
 *
 * 3hasChildrenUnderTwelve, 4hasPets, 5age,
 * 15lengthOfOwnershipExpectation, 16monthlyBudgetForAnimal, 17availabilityPerDay, 18levelOfMobility, 19levelOfPatience, 20previousExperience, 21physicalAffection
*/
