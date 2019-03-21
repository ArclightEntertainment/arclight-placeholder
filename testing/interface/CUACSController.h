#ifndef CUACSCONTROLLER_H
#define CUACSCONTROLLER_H

#include <iostream>
#include <string>
#include "../data/DatabaseController.h"
#include "./EntityBuilder.h"
#include "./AbstractCollection.h"

class CUACSController
{
public:
    CUACSController();
    ~CUACSController();
    //static const std::string DB_PATH;
    UAnimal* getAnimal();
    Iterator<UAnimal*>* getAnimalIterator();
private:
    DatabaseController *dbController;
    EntityBuilder *animalBuilder;
    bool isDBOpen;
};
#endif
