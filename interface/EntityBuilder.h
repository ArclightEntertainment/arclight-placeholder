#ifndef ENTITYBUILDER_H
#define ENTITYBUILDER_H

#define NUM_ANIMAL_DESC 22
#define NUM_CLIENT_DESC 21

#include "./interface/Entity.h"

#include <iostream>

class EntityBuilder
{
public:
    EntityBuilder();
    ~EntityBuilder();
    EntityBuilder * addBoolDesc(Description<bool> desc) {entity->addBoolDesc(desc); return this;}
    EntityBuilder * addIntDesc(Description<int> desc) {entity->addIntDesc(desc); return this;}
    EntityBuilder * addStringDesc(Description<std::string> desc) {entity->addStringDesc(desc); return this;}
    EntityBuilder * setID(int id) {entity->setID(id); return this;}
    EntityBuilder * setAge(int a) {entity->setAge(a); return this;}
    EntityBuilder * setName(std::string n) {entity->setName(n); return this;}
    virtual void reset()=0;
    Entity * getEntity() {return entity;}
    Entity * build();

protected:
    int numDesc;
    void setNumDesc(int numD){numDesc = numD;}
    Entity * entity;
};

class ClientBuilder : public EntityBuilder
{
public:
    ClientBuilder();
    ~ClientBuilder();
    void reset() {entity = new UClient();}
};

class AnimalBuilder : public EntityBuilder
{
public:
    AnimalBuilder();
    ~AnimalBuilder();
    void reset() {entity = new UAnimal();}
};
#endif // ENTITYBUILDER_H

/*
*/
