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

    Animal animalArr[animalCount];

    for(int i=0; i<animalCount; i++){
        std::cout << animal->getName() << std::endl;
        animalArr[i] = *animal;
        animal++;
    }
    w.setArr(animalArr, animalCount);
    return a.exec();
}
