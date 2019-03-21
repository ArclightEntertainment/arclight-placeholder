#include "EntityBuilder.h"
#include <iostream>

EntityBuilder::EntityBuilder()
{

}

EntityBuilder::~EntityBuilder()
{

}

Entity * EntityBuilder::build()
{
    int currentID = 0;

    Iterator<Description<bool>>         * bool_iter   = entity->getBoolIterator();
    Iterator<Description<int>>          * int_iter    = entity->getIntIterator();
    Iterator<Description<std::string>>  * string_iter = entity->getStringIterator();

    while (currentID < numDesc)
    {
        //std::cout<< "current: " << currentID << "/ numDesc: " << numDesc<< "/ bool: " << bool_iter->currentItem().getAttributeID() << "/ int: " << int_iter->currentItem().getAttributeID() << "/ string: " << string_iter->currentItem().getAttributeID() << std::endl;
        if (bool_iter->currentItem().getAttributeID() == currentID)
        {
            bool_iter->next(); currentID++;
        }
        else if (int_iter->currentItem().getAttributeID() == currentID)
        {
            int_iter->next(); currentID++;
        }
        else if (string_iter->currentItem().getAttributeID() == currentID)
        {
            string_iter->next(); currentID++;
        }
        else
        {
            return NULL;
        }
    }
    //std::cout<<"Made Animal: " << entity->getName() <<std::endl;
    return entity;
}

AnimalBuilder::AnimalBuilder() : EntityBuilder()
{
    setNumDesc(NUM_ANIMAL_DESC);
    entity = new UAnimal();
}
AnimalBuilder::~AnimalBuilder()
{
}

ClientBuilder::ClientBuilder() : EntityBuilder()
{
    setNumDesc(NUM_CLIENT_DESC);
    entity = new UClient();
}
ClientBuilder::~ClientBuilder()
{
}
