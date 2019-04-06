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
    return -1;
}
std::string Entity::getString (int id)
{
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
    return "";
}
bool Entity::getBool (int id)
{
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
    return false;
}


void Entity::setInt (int id, int val)
{
    Iterator<Description<int>> * iter = getIntIterator();
    iter->first();
    int i = 0;
    while(!iter->isDone())
    {
        if (iter->currentItem().getAttributeID() == id)
        {
            iter->currentItem().setValue(val);
            break;
        }
        i++;
        iter->next();
    }
    intCollection.setValue(i, Description<int>(iter->currentItem().getName(), iter->currentItem().getAttributeID(), val));
}
void Entity::setString (int id, std::string val)
{
    Iterator<Description<std::string>> * iter = getStringIterator();
    iter->first();
    int i = 0;
    while(!iter->isDone())
    {
        if (iter->currentItem().getAttributeID() == id)
        {
            iter->currentItem().setValue(val);
            break;
        }
        i++;
        iter->next();
    }
    stringCollection.setValue(i, Description<std::string>(iter->currentItem().getName(), iter->currentItem().getAttributeID(), val));
}
void Entity::setBool (int id, bool val)
{
    Iterator<Description<bool>> * iter = getBoolIterator();
    iter->first();
    int i = 0;
    while(!iter->isDone())
    {
        if (iter->currentItem().getAttributeID() == id)
        {
            iter->currentItem().setValue(val);
            break;
        }
        i++;
        iter->next();
    }
    boolCollection.setValue(i, Description<bool>(iter->currentItem().getName(), iter->currentItem().getAttributeID(), val));
}
