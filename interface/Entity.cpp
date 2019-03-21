#include "Entity.h"
#include <iostream>

Entity::Entity() : ID(-1), age(-1), name(""), boolCollection(), intCollection(), stringCollection()
{

}

UAnimal::UAnimal() : Entity()
{

}

UClient::UClient() : Entity()
{

}

Entity::~Entity()
{

}

UAnimal::~UAnimal()
{

}

UClient::~UClient()
{

}




int Entity::getInt (int id)
{
      /*int    id                  = 0,
        int    age                 = 4,
        int    lifeExpectancy      = 5,
        int    levelOfCare         = 8,
        int    levelOfEnergy       = 9,
        int    trainingLevel       = 10,
        int    trainabilityLevel   = 11,
        int    affinityForPeople   = 12,
        int    affinityForChildren = 13,
        int    affinityForAnimals  = 14,
        int    approachability     = 15,
        int    timeCommitment      = 16,*/
    Iterator<Description<int>> * iter = getIntIterator();
    iter->first();
    while(!iter->isDone())
    {
        if (iter->currentItem().getAttributeID() == id)
        {
            return iter->currentItem().getValue();
        }
        iter->next();
    }
}
std::string Entity::getString (int id)
{
    /*
    string name                = 1,
    string species             = 2,
    string breed               = 3,
    string sex                 = 6,
    string dietNeeds text      = 17,
    string mobilityNeeds       = 18,
    string disablityNeeds      = 19,
    string abuseHistory        = 20,
    string biography           = 21*/
    Iterator<Description<std::string>> * iter = getStringIterator();
    iter->first();
    while(!iter->isDone())
    {
        if (iter->currentItem().getAttributeID() == id)
        {
            return iter->currentItem().getValue();
        }
        iter->next();
    }
}
bool Entity::getBool (int id)
{
     //   bool   immunized           = 7,
    Iterator<Description<bool>> * iter = getBoolIterator();
    iter->first();
    while(!iter->isDone())
    {
        if (iter->currentItem().getAttributeID() == id)
        {
            return iter->currentItem().getValue();
        }
        iter->next();
    }
}
