#ifndef ACMDETAILDIALOG_H
#define ACMDETAILDIALOG_H

#include <QDialog>
#include<QVBoxLayout>
#include <interface/AnimalClientPair.h>
#include <interface/CUACSController.h>

namespace Ui {
class ACMDetailDialog;
}

class ACMDetailDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ACMDetailDialog(CUACSController * med, int cID, AnimalClientPair * p, QWidget *parent = 0);
    ~ACMDetailDialog();

    void addComments(std::string comments[], int count=0);

private slots:
    void handleButtonAnimal();
    void handleButtonClient();
    void handleButtonClose();
private:
    Ui::ACMDetailDialog *ui;

    QPushButton * animalButton;
    QPushButton * clientButton;
    QPushButton * closeButton;

    AnimalClientPair * pair;
    CUACSController * mediator;

    QVBoxLayout * comments;

    int currentID;

    void populateAnimal();
    void populateClient();
};

#endif // ACMDETAILDIALOG_H
