#ifndef ENTITYBUILDER_H
#define ENTITYBUILDER_H
#include "./data/Entity.h"

class EntityBuilder
{
public:
    EntityBuilder();
    ~EntityBuilder();
    virtual EntityBuilder * addBoolDesc(Description<bool> desc)=0;
    virtual EntityBuilder * addIntDesc(Description<int> desc)=0;
    virtual EntityBuilder * addStringDesc(Description<std::string> desc)=0;
    virtual EntityBuilder * setID(int id)=0;
    virtual EntityBuilder * setAge(int a)=0;
    virtual EntityBuilder * setName(std::string n)=0;
    virtual void reset()=0;
    virtual Entity getEntity()=0;
    virtual Entity build()=0;
};

class ClientBuilder : EntityBuilder
{
public:
    ClientBuilder();
    ~ClientBuilder();
    EntityBuilder * addBoolDesc(Description<bool> desc) {entity.addBoolDesc(desc); return this;}
    EntityBuilder * addIntDesc(Description<int> desc) {entity.addIntDesc(desc); return this;}
    EntityBuilder * addStringDesc(Description<std::string> desc) {entity.addStringDesc(desc); return this;}
    EntityBuilder * setID(int id) {entity.setID(id); return this;}
    EntityBuilder * setAge(int a) {entity.setAge(a); return this;}
    EntityBuilder * setName(std::string n) {entity.setName(n); return this;}

    void reset() {entity = UClient();}
    Entity getEntity() {return entity;}
    Entity build(){}
private:
    UClient entity;
};

class AnimalBuilder : EntityBuilder
{
public:
    AnimalBuilder();
    ~AnimalBuilder();
    EntityBuilder * addBoolDesc(Description<bool> desc) {entity.addBoolDesc(desc); return this;}
    EntityBuilder * addIntDesc(Description<int> desc) {entity.addIntDesc(desc); return this;}
    EntityBuilder * addStringDesc(Description<std::string> desc) {entity.addStringDesc(desc); return this;}
    EntityBuilder * setID(int id) {entity.setID(id); return this;}
    EntityBuilder * setAge(int a) {entity.setAge(a); return this;}
    EntityBuilder * setName(std::string n) {entity.setName(n); return this;}

    void reset() {entity = UAnimal();}
    Entity getEntity() {return entity;}
    Entity build(){}
private:
    UAnimal entity;
};
#endif // ENTITYBUILDER_H

/*
*/
