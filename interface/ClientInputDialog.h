#ifndef CLIENTINPUTDIALOG_H
#define CLIENTINPUTDIALOG_H

#include <QDialog>

namespace Ui {
class ClientInputDialog;
}

class ClientInputDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ClientInputDialog(QWidget *parent = 0);
    ~ClientInputDialog();

private:
    Ui::ClientInputDialog *ui;
};

#endif // CLIENTINPUTDIALOG_H
