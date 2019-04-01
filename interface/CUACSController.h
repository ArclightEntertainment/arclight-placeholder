#ifndef CUACSCONTROLLER_H
#define CUACSCONTROLLER_H

#include <iostream>
#include <string>
#include "../data/DatabaseController.h"
#include "./EntityBuilder.h"
#include "ArrayCollection.h"
#include "ACMController.h"

class CUACSController
{
public:
    CUACSController();
    ~CUACSController();
    //static const std::string DB_PATH;
    Iterator<UAnimal*>* getAnimalIterator();
    Iterator<UClient*>* getClientIterator();
    unsigned int getNumEntities (char type) {return (type == 'c') ? clientCollection.count() : animalCollection.count();}

    UAnimal **getAnimals();
    Entity * getAnimalWithId(int id);
    int getNextAnimalID();

    void addAnimal (int id,int expenditure,std::string name,int age,int maxAge,std::string sex,std::string species,std::string breed,int care,int energy);
    void updateAnimalSocial (int training,int trainability,int people,int child,int animal,int approach,int time);
    void updateAnimalHistory (bool imm,std::string diet,std::string mob,std::string disab,std::string bio,std::string aHist);
    void finalizeAnimal();

    UClient **getClients();
    Entity * getClientWithId(int id);
    int getNextClientID();

    void addClient(std::string t, int iD, std::string fn, std::string ln, std::string pn);
    void populateClientAddress(std::string sl1, std::string sl2, std::string ct, std::string sub, std::string c, std::string pc);
    void populateClientProfile(int a, bool hasUnderTwelve, bool hasPet, int ownExp, int budget, int timeAvail, int lOfMobility, int lOfPatience, int prevExp, int physAffect);
    void finalizeClient();

    Iterator<UAnimal *> * createAnimalIterator () { return animalCollection.createIterator();}
    Iterator<UClient *> * createClientIterator () { return clientCollection.createIterator();}

    CandidateSet *launchACM();

private:
    DatabaseController *dbController;
    ACMController *acmController;

    ArrayCollection<UAnimal*> animalCollection;
    ArrayCollection<UClient*> clientCollection;
    EntityBuilder * entity;
    bool isDBOpen;
};
#endif
