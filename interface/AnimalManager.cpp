#include "AnimalManager.h"
#include "./data/DatabaseInterface.h"

AnimalManager::AnimalManager()
{
    animalCollection = new Animal[30];
}

AnimalManager::AnimalManager(int i)
{
    animalCollection = new Animal[i];
}

void AnimalManager::addAnimal(Animal &newAnimal)
{
    animalCollection[numAnimals++] = newAnimal;
    std::cout<<numAnimals<<std::endl;
    DatabaseInterface::pushDBAnimal(newAnimal);
}
