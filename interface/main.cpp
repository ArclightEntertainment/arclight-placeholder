#include "MainWindow.h"
#include <QApplication>
#include "./data/DatabaseInterface.h"
#include "./data/arraycollection.h"
#include "./data/description.h"

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
        w.setAnimalArr(animalArr, animalCount);//
        //
        //
        //
        //
        //
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

    //ArrayCollection<Description<int>> * ints = new ArrayCollection<Description<int>>();
    //ArrayCollection<Description<std::string>> * strings = new ArrayCollection<Description<std::string>>();
    //ArrayCollection<Description<ThreeScale>> * threes = new ArrayCollection<Description<ThreeScale>>();
    //for (int i = 0; i < 342; i+=3)
    //{
    //    ints->Append(Description<int>("ID", i,10000 + i));
    //    std::string name = "Dougie: " + std::to_string(i+1);
    //    strings->Append(Description<std::string>("Name", i+1, name));
    //    threes->Append(Description<ThreeScale>("energyLevel", i+2, ThreeScale::HIGH));
    //}
    //
    //Iterator<Description<int>> * int_iter = ints->CreateIterator();
    //Iterator<Description<std::string>> * string_iter = strings->CreateIterator();
    //Iterator<Description<ThreeScale>> * three_iter = threes->CreateIterator();
    //
    //while (!int_iter->IsDone())
    //{
    //    std::cout << "Int: " << int_iter->CurrentItem().getValue() << std::endl;
    //    int_iter->Next();
    //}

    while (!string_iter->IsDone())
    {
        std::cout << "String: " << string_iter->CurrentItem().getValue() << std::endl;
        string_iter->Next();
    }

    while (!three_iter->IsDone())
    {
        std::cout << "ThreeScale: " << ((three_iter->CurrentItem().getValue() == ThreeScale::HIGH) ? "HIGH" : ((three_iter->CurrentItem().getValue() == ThreeScale::MEDIUM) ? "MEDIUM" : ((three_iter->CurrentItem().getValue() == ThreeScale::LOW) ? "LOW" :  "UNDFTS"))) << std::endl;
        three_iter->Next();
    }


    return a.exec();
}
