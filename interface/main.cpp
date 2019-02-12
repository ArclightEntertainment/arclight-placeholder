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
    int animalCount = DatabaseInterface::getAnimalCount();
    Animal *animal = animalArray[0];
    for(int i=0; i<animalCount; i++){
        std::cout << animal->getName() << std::endl;
        animal++;
    }
    return a.exec();
}
