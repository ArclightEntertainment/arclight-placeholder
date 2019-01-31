#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //login page -> open main window
    //open new login dialog on logout
    //just logout on close

    MainWindow w;
    w.show();

    return a.exec();
}
