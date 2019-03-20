#include "EntityBuilder.h"
#include <iostream>

EntityBuilder::EntityBuilder()
{

}
EntityBuilder::~EntityBuilder()
{

}

AnimalBuilder::AnimalBuilder() : EntityBuilder()
{
    entity = new UAnimal();
}
AnimalBuilder::~AnimalBuilder()
{
}

ClientBuilder::ClientBuilder() : EntityBuilder()
{
    entity = new UClient();
}
ClientBuilder::~ClientBuilder()
{
}
