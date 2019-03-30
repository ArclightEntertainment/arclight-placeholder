#ifndef ANIMALCLIENTPAIR_H
#define ANIMALCLIENTPAIR_H

#include "Animal.h"
#include "Client.h"

class AnimalClientPair
{
private:
    Animal *animal;
    Client *client;
    float compatibility;

public:
    AnimalClientPair(Animal *a, Client *c);
    Animal *getAnimal();
    Client *getClient();
    float getCompatibility();
};
#endif // ANIMALCLIENTPAIR_H
