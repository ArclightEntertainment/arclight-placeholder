#include "MainWindow.h"
#include <QApplication>
#include "./data/DatabaseInterface.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //login page -> open main window
    //open new login dialog on logout
    //just logout on close

    MainWindow w;
    w.show();

    Animal **animalArray = DatabaseInterface::getDB();
    Animal *animal = animalArray[0];
    std::cout << animal->getName() << std::endl;
    return a.exec();
}
