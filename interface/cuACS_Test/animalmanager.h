#ifndef ANIMALMANAGER_H
#define ANIMALMANAGER_H

#include <iostream>

#include "animal.h"


class AnimalManager
{
public:
    AnimalManager();
    AnimalManager(int animalCount);
    void addAnimal(Animal &newAnimal);
    inline Animal* getAnimalCollection(){return animalCollection;}
    inline int getNumAnimals(){return numAnimals;}
private:
    Animal *animalCollection;
    int numAnimals;
};

#endif // ANIMALMANAGER_H
