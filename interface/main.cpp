#include "MainWindow.h"
#include <QApplication>
#include "./data/DatabaseInterface.h"
#include "./data/ArrayCollection.h"
#include "./data/Description.h"
#include "./data/Entity.h"

void testAnimals()
{
    ArrayCollection<UAnimal*> * animals = new ArrayCollection<UAnimal*>();
    Iterator<UAnimal*> * animalIterator = animals->CreateIterator();

    ArrayCollection<UClient*> * clients = new ArrayCollection<UClient*>();
    Iterator<UClient*> * clientIterator = clients->CreateIterator();

    int numEntities = 10;
    int numAttributes = 5;


    for (int i = 0; i < numEntities; i++)
    {
        UAnimal * anim = new UAnimal();
        UClient * cli = new UClient();
        std::string aName = "";
        std::string cName = "";
        for (int j = 0; j < i; j++)
        {
            aName.append("a");
            cName.append("c");
        }
        anim->setID(i)->setAge(i)->setName(aName);
        cli->setID(i + numEntities + 1)->setAge(i + numEntities + 1)->setName(cName);

        for (int j = 0; j < numAttributes; j++)
        {
            std::string boolName="Bool: ";
            std::string intName="Int: ";
            std::string stringName="String: ";

            boolName.append(std::to_string(i));
            intName.append(std::to_string(i));
            stringName.append(std::to_string(i));

            Description<bool> someBool = Description<bool>(boolName, i % numAttributes, (i % 2));
            Description<int> someInt = Description<int>(intName, numAttributes + i % numAttributes, i);
            Description<std::string> someString = Description<std::string>(stringName, 2 * numAttributes + i % numAttributes, stringName);

            anim->addBoolDesc(someBool)->addIntDesc(someInt)->addStringDesc(someString);
            cli->addBoolDesc(someBool)->addIntDesc(someInt)->addStringDesc(someString);

        }

        animals->Append(anim);
        clients->Append(cli);
    }

    std::cout<<"\n\nPRINT OUT ALL CLIENTS + ATTRIBUTES"<<std::endl;
    while (!clientIterator->IsDone())
    {
        UClient * temp = clientIterator->CurrentItem();
        Iterator<Description<bool>> * bools = temp->getBoolIterator();
        Iterator<Description<int>> * ints = temp->getIntIterator();
        Iterator<Description<std::string>> * strings = temp->getStringIterator();
        while (!bools->IsDone() && !ints->IsDone() && !strings->IsDone())
        {
            std::cout<<"CLIENT: " << temp->getName() <<"- ";
            std::cout<<bools->CurrentItem().getName()       << " / " <<      bools->CurrentItem().getAttributeID()       << " / "   << bools->CurrentItem().getValue() << " -- ";
            std::cout<<ints->CurrentItem().getName()        << " / " <<      ints->CurrentItem().getAttributeID()        << " / "   << ints->CurrentItem().getValue() << " -- ";
            std::cout<<strings->CurrentItem().getName()     << " / " <<      strings->CurrentItem().getAttributeID()     << " / "   << strings->CurrentItem().getValue();
            std::cout<<std::endl;
            bools->Next();
            ints->Next();
            strings->Next();
        }
        clientIterator->Next();
        std::cout<<std::endl;
    }

    std::cout<<"\n\nPRINT OUT ALL ANIMALS + ATTRIBUTES"<<std::endl;
    while (!animalIterator->IsDone())
    {
        UAnimal * temp = animalIterator->CurrentItem();
        Iterator<Description<bool>> * bools = temp->getBoolIterator();
        Iterator<Description<int>> * ints = temp->getIntIterator();
        Iterator<Description<std::string>> * strings = temp->getStringIterator();
        while (!bools->IsDone() && !ints->IsDone() && !strings->IsDone())
        {
            std::cout<<"ANIMAL: " << temp->getName() <<"- ";
            std::cout<<bools->CurrentItem().getName()       << " / " <<      bools->CurrentItem().getAttributeID()       << " / "   << bools->CurrentItem().getValue() << " -- ";
            std::cout<<ints->CurrentItem().getName()        << " / " <<      ints->CurrentItem().getAttributeID()        << " / "   << ints->CurrentItem().getValue() << " -- ";
            std::cout<<strings->CurrentItem().getName()     << " / " <<      strings->CurrentItem().getAttributeID()     << " / "   << strings->CurrentItem().getValue();
            std::cout<<std::endl;
            bools->Next();
            ints->Next();
            strings->Next();
        }
        animalIterator->Next();
        std::cout<<std::endl;
    }
}


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

    testAnimals();

    return a.exec();
}
