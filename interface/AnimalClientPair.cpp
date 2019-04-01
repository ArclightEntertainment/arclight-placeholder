#include "AnimalClientPair.h"
#include "AttributeComparator.h"

AnimalClientPair::AnimalClientPair(UAnimal *a, UClient *c)
{
    animal = a;
    client = c;
    compatibility = AttributeComparator::calculateCompatibility(a, c);
}

UAnimal *AnimalClientPair::getAnimal()
{
    return animal;
}

UClient *AnimalClientPair::getClient()
{
    return client;
}

float AnimalClientPair::getCompatibility()
{
    return compatibility;
}
