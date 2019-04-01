#ifndef ANIMALCLIENTPAIR_H
#define ANIMALCLIENTPAIR_H

#include "EntityBuilder.h"

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
};
#endif // ANIMALCLIENTPAIR_H
