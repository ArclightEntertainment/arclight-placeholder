#ifndef INPUTDIAG_H
#define INPUTDIAG_H

#include <QCoreApplication>
#include <QPushButton>
#include <QDialog>
#include <QMainWindow>


namespace Ui {
class InputDiag;
}

class InputDiag : public QDialog
{
    Q_OBJECT

public:
    explicit InputDiag(QWidget *parent = 0);
    ~InputDiag();
private:
    Ui::InputDiag *ui;
};

#endif // INPUTDIAG_H
