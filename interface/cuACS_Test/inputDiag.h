#ifndef INPUTDIAG_H
#define INPUTDIAG_H

#include <QCoreApplication>
#include <QPushButton>
#include <QDialog>
#include <QMainWindow>
#include <QDebug>
#include <qstring.h>

namespace Ui {
class InputDiag;
}

class InputDiag : public QDialog
{
    Q_OBJECT

public:
    explicit InputDiag(QWidget *parent = 0);
    ~InputDiag();
private slots:
    void handleButtonSave();
    void handleButtonCancel();
private:
    Ui::InputDiag *ui;
    QPushButton *saveButton;
    QPushButton *cancelButton;
};

#endif // INPUTDIAG_H
