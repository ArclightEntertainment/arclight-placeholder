#ifndef CLIENTMANAGER_H
#define CLIENTMANAGER_H

#include <iostream>

#include "Client.h"


class ClientManager
{
public:
    ClientManager();
    ClientManager(int cCount);
    int addClient(std::string t, int iD, std::string fn, std::string ln, std::string pn);
    void populateClientAddress(int index, std::string sl1, std::string sl2, std::string ct, std::string sub, std::string c, std::string pc);
    void populateClientProfile(int index, int a, bool hasUnderTwelve, int ownExp, int budget, int spaceSqFt, int timeAvail, FiveScale lOfMobility, FiveScale lOfEnergy, FiveScale lOfPatience, FiveScale prevExp, FiveScale physAffect);
    void pushClientToDB(int index);
    int checkID(int id);
    Client* getClientWithId(int sid);
    Client* getClientWithName(std::string n);
    inline Client* getClientCollection(){return clientCollection;}
    inline int getNumClients(){return numClients;}
    inline void setArr(Client *arr, int numCli){clientCollection = arr; numClients = numCli; maxNumClients = numCli; resize();}
    void resize();
private:
    Client *clientCollection;
    int numClients;
    int maxNumClients;
};

#endif // ClientMANAGER_H
