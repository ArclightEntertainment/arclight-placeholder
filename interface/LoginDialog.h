#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>
#include <QLineEdit>
#include <QLabel>

#include "CUACSController.h"

namespace Ui {
class LoginDialog;
}

class LoginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LoginDialog(int * i, CUACSController * med, QWidget *parent = 0);
    ~LoginDialog();
private slots:
    void handleButtonLogin();
    void handleButtonClose();
    void handleButtonStaff();
    void handleButtonClient();
private:
    Ui::LoginDialog *ui;

    QPushButton * loginButton;
    QPushButton * closeButton;
    QPushButton * staffButton;
    QPushButton * clientButton;
    QLabel * nameLabel;
    QLineEdit * fNameLineEdit;
    QLineEdit * lNameLineEdit;

    int * id;
    CUACSController* mediator;
};

#endif // LOGINDIALOG_H
