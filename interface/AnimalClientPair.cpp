#include "AnimalClientPair.h"
#include "AttributeComparator.h"

AnimalClientPair::AnimalClientPair(Animal *a, Client *c)
{
    animal = a;
    client = c;
    compatibility = AttributeComparator::calculateCompatibility(a, c);
}

Animal *AnimalClientPair::getAnimal()
{
    return animal;
}

Client *AnimalClientPair::getClient()
{
    return client;
}

float AnimalClientPair::getCompatibility()
{
    return compatibility;
}
