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

void AnimalManager::pushAnimalToDB(int index)
{
    DatabaseInterface::pushDBAnimal(animalCollection[index]);
}

int AnimalManager::addAnimal(int id, std::string n, int a, char sx, std::string sp, std::string b, int cL)
{
    animalCollection[numAnimals++] = *new Animal(id, n, a, sx, sp, b, cL);
    return numAnimals-1;
}

void AnimalManager::updateAnimalSocial(int index, int trLevel, int peopleLevel, int childLevel, int animalLevel, int approachLevel, int tiLevel)
{
    animalCollection[index].populateSocial(trLevel, peopleLevel, childLevel, animalLevel, approachLevel, tiLevel);
}

void AnimalManager::updateAnimalHistory(int index, bool imm, std::string dietString, std::string mobilityString, std::string disabilityString, std::string bio, std::string aHist)
{
    animalCollection[index].populateHistory(imm, dietString, mobilityString, disabilityString, bio, aHist);
}

int AnimalManager::checkID(int id)
{
    for(int i = 0; i < numAnimals; i++)
    {
        if (animalCollection[i].getShelterID() == id)
        {
            return 0;
        }
    }
    return 1;
}
