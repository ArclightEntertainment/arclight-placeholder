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

