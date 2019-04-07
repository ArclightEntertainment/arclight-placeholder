#include "AnimalClientPair.h"
#include "AttributeComparator.h"
#include <sstream>

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

std::string AnimalClientPair::toString()
{
    std::ostringstream stream;
    stream << "(" << compatibility << "), "
                    << animal->getName() << ", "
                    << client->getName();

    return stream.str();

}
