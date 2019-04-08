#ifndef ACMDETAILDIALOG_H
#define ACMDETAILDIALOG_H

#include <QDialog>
#include <interface/AnimalClientPair.h>
#include <interface/CUACSController.h>

namespace Ui {
class ACMDetailDialog;
}

class ACMDetailDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ACMDetailDialog(CUACSController * med, AnimalClientPair * p, QWidget *parent = 0);
    ~ACMDetailDialog();

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

    void populateAnimal();
    void populateClient();
};

#endif // ACMDETAILDIALOG_H
