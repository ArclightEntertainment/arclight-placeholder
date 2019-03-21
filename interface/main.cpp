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

    Animal **animalArray = DatabaseInterface::getAnimalArray();
    int animalCount = DatabaseInterface::getAnimalCount();
    Animal *animal = animalArray[0];
    Animal animalArr[animalCount];

    Client **clientArray = DatabaseInterface::getClientArray();
    int clientCount = DatabaseInterface::getClientCount();
    Client *client = clientArray[0];
    Client clientArr[clientCount];

    for(int i=0; i<animalCount; i++){
        animalArr[i] = *animal;
        animal++;
    }

    for(int i=0; i<clientCount; i++){
        clientArr[i] = *client;
        client++;
    }

    if (animalCount > 0)
    {
        w.setAnimalArr(animalArr, animalCount);
    }
    else
    {
        int AnimalCount = 10;
        Animal AnimalArr[AnimalCount];
        w.setAnimalArr(AnimalArr, AnimalCount);
    }
    if (clientCount > 0)
    {
        w.setClientArr(clientArr, clientCount);
    }
    else
    {
        int ClientCount = 10;
        Client ClientArr[ClientCount];
        w.setClientArr(ClientArr, ClientCount);
    }
    return a.exec();
}
