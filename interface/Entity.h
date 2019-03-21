#ifndef ENTITY_H
#define ENTITY_H

#include "Description.h"
#include "ArrayCollection.h"
#include <string>

class Entity
{
public:
    Entity();
    ~Entity();

    Entity * setID(int id){ID=id; return this;}
    Entity * setAge(int a){age=a; return this;}
    Entity * setName(std::string n){name=n; return this;}

    Entity * addBoolDesc(Description<bool> desc){boolCollection.append(desc); return this;}
    Entity * addIntDesc(Description<int> desc){intCollection.append(desc); return this;}
    Entity * addStringDesc(Description<std::string> desc){stringCollection.append(desc); return this;}

    int getID(){return ID;}
    int getAge(){return age;}
    std::string getName(){return name;}

    int getInt (int id);
    std::string getString (int id);
    bool getBool (int id);

    Iterator<Description<bool>> * getBoolIterator() {return boolCollection.createIterator();}
    Iterator<Description<int>> * getIntIterator() {return intCollection.createIterator();}
    Iterator<Description<std::string>> * getStringIterator(){return stringCollection.createIterator();}

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
