#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <iostream>

#include <QCoreApplication>
#include <QPushButton>
#include <QDialog>
#include <QMainWindow>
#include "inputDiag.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void handleButtonView();
    void handleButtonInput();
private:
    Ui::MainWindow *ui;
    QPushButton *viewButton;
    QPushButton *inputButton;
};

#endif // MAINWINDOW_H
