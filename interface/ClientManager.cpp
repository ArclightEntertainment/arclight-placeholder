#include "ClientManager.h"
#include "./data/DatabaseInterface.h"

//Default Constructor
ClientManager::ClientManager()
{
    clientCollection = new Client[30];
}

//Can instantiate with a specific count
ClientManager::ClientManager(int cCount)
{
    clientCollection = new Client[cCount];
}

int ClientManager::addClient(std::string t, std::string fn, std::string ln, std::string pn)
{

    std::cout<<"ErrorCheck4___----_____-----___----____--" << std::endl;
    std::cout<<numClients << " " << maxNumClients << std::endl;
    clientCollection[numClients++] = *new Client(t, fn, ln, pn);
    std::cout<<"ErrorCheck5~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
    resize();
    return numClients-1;
}

void ClientManager::populateClientAddress(int index, std::string sl1, std::string sl2, std::string ct, std::string sub, std::string c, std::string pc)
{

    std::cout<<"ErrorCheck7^V^V^V^V^V^V^V^V^V^V^V^V^V^V^V^V^V^V^V^" << std::endl;
    clientCollection[index].populateAddress(sl1, sl2, ct, sub, c, pc);
}

void ClientManager::populateClientProfile(int index, int a, bool hasUnderTwelve, int ownExp, int budget, int spaceSqFt, int timeAvail, FiveScale lOfMobility, FiveScale lOfEnergy, FiveScale lOfPatience, FiveScale prevExp, FiveScale physAffect)
{
    clientCollection[index].populateProfile(a, hasUnderTwelve, ownExp, budget, spaceSqFt, timeAvail, lOfMobility, lOfEnergy, lOfPatience, prevExp, physAffect);
}

//Finalize client at index, send it to database
void ClientManager::pushClientToDB(int index)
{
    Client* a = &clientCollection[index];
    std::cout << a->getNameWithTitle() << "\n\t" << a->getPhoneNumber() << "\n\t" << a->getAddress().getCity() << std::endl;
    //clientCollection[index].setID(DatabaseInterface::pushDBClient(clientCollection[index]));
}

//check input id against id's of every other client in db, if used, then
int ClientManager::checkID(int id)
{
    for(int i = 0; i < numClients; i++)
    {
        if (clientCollection[i].getID() == id)
        {
            return 0;
        }
    }
    return 1;
}

void ClientManager::resize()
{
    if (numClients >= maxNumClients)
    {
        maxNumClients *= 2;
        Client *newArray = new Client[maxNumClients];
        for (int i = 0; i < numClients; i++)
        {
            newArray[i] = clientCollection[i];
        }
        clientCollection = newArray;
        //std::cout<<"Doubled!"<<std::endl;
    }
}

Client* ClientManager::getClientWithId(int sid)
{
    for (int i = 0; i < numClients; i++)
    {
        if (clientCollection[i].getID() == sid)
        {
            return &clientCollection[i];
        }
    }
    return NULL;
}

Client* ClientManager::getClientWithName(std::string n)
{
    for (int i = 0; i < numClients; i++)
    {
        if (clientCollection[i].getName().compare(n) == 0)
        {
            return &clientCollection[i];
        }
    }
    return NULL;
}

