#include "Tests.h"
#include "MainWindow.h"
#include "ACMController.h"

void Tests::runTests()
{
    //testClients()
    //testACM();
}

void Tests::testClients()
{
    bool doPrint = false;
    ArrayCollection<UClient*> * clients = new ArrayCollection<UClient*>();
    Iterator<UClient*> * clientIterator = clients->createIterator();

    int numEntities = 25;
    int numAttributes = 21;


    for (int i = 0; i < numEntities; i++)
    {
        EntityBuilder * cli = new ClientBuilder();
        std::string cName = "Client #" + std::to_string(i);

        cli->setID(i + numEntities + 1)->setAge(i + numEntities + 1)->setName(cName);


        for (int j = 0; j < numAttributes; j++)
        {
            std::string string = "Value (";
            string.append(std::to_string(j));
            string.append(")");

            if (j % 3 == 0){cli->addBoolDesc(Description<bool>("Bool ", j, j%2));}
            if (j % 3 == 1){cli->addIntDesc(Description<int>("Int ", j, j));}
            if (j % 3 == 2){cli->addStringDesc(Description<std::string>("String ", j, string));}
        }

        UClient * client = (UClient*)cli->build();
        if (client != NULL)
        {
            clients->append(client);
        }
    }

    std::cout<<"\n\nPRINT OUT ALL CLIENTS + ATTRIBUTES"<<std::endl;
    while (!clientIterator->isDone() && doPrint)
    {
        UClient * temp = clientIterator->currentItem();
        Iterator<Description<bool>> * bools = temp->getBoolIterator();
        Iterator<Description<int>> * ints = temp->getIntIterator();
        Iterator<Description<std::string>> * strings = temp->getStringIterator();

        while (!bools->isDone())
        {
            std::cout<< temp->getName() << ": Bools: ";
            std::cout<<bools->currentItem().getName() << "/" << bools->currentItem().getAttributeID() << "/" << bools->currentItem().getValue();
            std::cout<<std::endl;
            bools->next();
        }
        while (!ints->isDone())
        {
            std::cout<< temp->getName() << ": Ints: ";
            std::cout<<ints->currentItem().getName() << "/" << ints->currentItem().getAttributeID() << "/" << ints->currentItem().getValue();
            std::cout<<std::endl;
            ints->next();
        }
        while (!strings->isDone())
        {
            std::cout<< temp->getName() << ": Strings: ";
            std::cout<<strings->currentItem().getName() << "/" << strings->currentItem().getAttributeID() << "/" << strings->currentItem().getValue();
            std::cout<<std::endl;
            strings->next();
        }
        clientIterator->next();
        std::cout<<std::endl;
    }
}

void Tests::testACM(CUACSController *mediator)
{
   std::cout << mediator->launchACM()->toString() << std::endl;
}
