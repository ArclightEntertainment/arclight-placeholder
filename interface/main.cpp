#include "MainWindow.h"
#include <QApplication>
#include "./data/DatabaseInterface.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    DatabaseInterface::getDB();

    MainWindow w;
    w.show();

    return a.exec();
}
