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
    void populateClientProfile(int index, int a, bool hasUnderTwelve, bool hasPet, int ownExp, int budget, int timeAvail, FiveScale lOfMobility, FiveScale lOfPatience, FiveScale prevExp, FiveScale physAffect);
    void pushClientToDB(int index);
    int checkID(int id);
    int getNextID();
    Client* getClientWithId(int sid);
    Client* getClientWithName(std::string n);
    inline Client* getClientCollection(){return clientCollection; }
    inline int getNumClients(){return numClients;}
    inline void setArr(Client *arr, int numCli){clientCollection = arr; numClients = numCli; maxNumClients = numCli; resize(); setNextClientID();}
    void resize();
    inline void printAll(){for (int i = 0; i < numClients; i++){std::cout<<clientCollection[i].getNameWithTitle() << " " << clientCollection[i].getClientID() << std::endl;}}
private:
    Client *clientCollection;
    int numClients;
    int maxNumClients;

    int nextClientID;
    inline void setNextClientID(){for (int i = 0; i < numClients; i++){if (clientCollection[i].getClientID() > nextClientID){nextClientID = clientCollection[i].getClientID();}}}
};

#endif // ClientMANAGER_H
