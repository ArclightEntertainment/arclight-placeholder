#include "MainWindow.h"
#include <QApplication>
#include "./data/DatabaseInterface.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //login page -> open main window
    //open new login dialog on logout
    //just logout on close

    DatabaseInterface::getDB();

    MainWindow w;
    w.show();

    return a.exec();
}
