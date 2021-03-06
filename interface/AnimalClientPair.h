#ifndef ANIMALCLIENTPAIR_H
#define ANIMALCLIENTPAIR_H

#include "EntityBuilder.h"
#include <string>

class AnimalClientPair
{
private:
    UAnimal *animal;
    UClient *client;
    float compatibility;

public:
    AnimalClientPair(UAnimal *a, UClient *c);
    UAnimal *getAnimal();
    UClient *getClient();
    float getCompatibility();
    std::string toString();
};
#endif // ANIMALCLIENTPAIR_H
