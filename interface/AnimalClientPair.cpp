#include "AnimalClientPair.h"
#include "AttributeComparator.h"

AnimalClientPair::AnimalClientPair(Animal *a, Client *c)
{
    animal = a;
    client = c;
    AttributeComparator::calculateCompatability(animal, client);
}

Animal *AnimalClientPair::getAnimal()
{
    return animal;
}

Client *AnimalClientPair::getClient()
{
    return client;
}

float AnimalClientPair::getCompatability()
{
    return compatability;
}
