#ifndef ENTITY_H
#define ENTITY_H

#include "Description.h"
#include "ArrayCollection.h"
#include "./interface/Levels.h"
#include <string>

class Entity
{
public:
    Entity();
    ~Entity();

    Entity * setID(int id){ID=id; return this;}
    Entity * setAge(int a){age=a; return this;}
    Entity * setName(std::string n){name=n; return this;}

    Entity * addBoolDesc(Description<bool> desc){boolCollection.Append(desc); return this;}
    Entity * addIntDesc(Description<int> desc){intCollection.Append(desc); return this;}
    Entity * addStringDesc(Description<std::string> desc){stringCollection.Append(desc); return this;}

    int getID(){return ID;}
    int getAge(){return age;}
    std::string getName(){return name;}

    Iterator<Description<bool>> * getBoolIterator() {return boolCollection.CreateIterator();}
    Iterator<Description<int>> * getIntIterator() {return intCollection.CreateIterator();}
    Iterator<Description<std::string>> * getStringIterator(){return stringCollection.CreateIterator();}

private:
    int ID;
    int age;
    std::string name;

    ArrayCollection<Description<bool>> boolCollection;
    ArrayCollection<Description<int>> intCollection;
    ArrayCollection<Description<std::string>> stringCollection;
};

class UAnimal : public Entity
{
public:
    UAnimal();
    ~UAnimal();
};

class UClient : public Entity
{
public:
    UClient();
    ~UClient();
};

#endif // ENTITY_H
