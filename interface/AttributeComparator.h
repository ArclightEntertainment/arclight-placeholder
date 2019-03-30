#ifndef ATTRIBUTECOMPARATOR_H
#define ATTRIBUTECOMPARATOR_H

#include "Animal.h"
#include "Client.h"

class AttributeComparator
{
public:
    static float calculateCompatability(Animal* animal, Client* client);
}
#endif // ATTRIBUTECOMPARATOR_H
