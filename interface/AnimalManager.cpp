#include "AnimalManager.h"
#include "./data/DatabaseInterface.h"

//Default Constructor
AnimalManager::AnimalManager()
{
    animalCollection = new Animal[30];
    nextShelterID = 0;
}

//Can instantiate with a specific count
AnimalManager::AnimalManager(int i)
{
    animalCollection = new Animal[i];
    nextShelterID = 0;
}

//Creates a new animal with basic information, returns it's index in the array.
int AnimalManager::addAnimal(int id, int expenditure, std::string n, int a, int lE, char sx, std::string sp, std::string b, int eL, int cL)
{
    animalCollection[numAnimals++] = *new Animal(id, expenditure, n, a, lE, sx, sp, b, eL, cL);
    resize();
    nextShelterID++;
    return numAnimals-1;
}

//Takes in an index and some information, populates those values in the animal at index
void AnimalManager::updateAnimalSocial(int index, int taLevel, int trLevel, int peopleLevel, int childLevel, int animalLevel, int approachLevel, int tiLevel)
{
    animalCollection[index].populateSocial(trLevel, taLevel, peopleLevel, childLevel, animalLevel, approachLevel, tiLevel);
}

//takes in index and history info, populates related fields in animal at index
void AnimalManager::updateAnimalHistory(int index, bool imm, std::string dietString, std::string mobilityString, std::string disabilityString, std::string bio, std::string aHist)
{
    animalCollection[index].populateHistory(imm, dietString, mobilityString, disabilityString, bio, aHist);
}

//Finalize animal at index, send it to database
void AnimalManager::pushAnimalToDB(int index)
{
    DatabaseInterface::pushDBAnimal(animalCollection[index]);
}

//check input id against id's of every other animal in db, if used, then
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

int AnimalManager::getNextID()
{
    return nextShelterID+1;
}

void AnimalManager::resize()
{
    if (numAnimals >= maxNumAnimals)
    {
        maxNumAnimals *= 2;
        Animal *newArray = new Animal[maxNumAnimals];
        for (int i = 0; i < numAnimals; i++)
        {
            newArray[i] = animalCollection[i];
        }
        animalCollection = newArray;
    }
}

Animal* AnimalManager::getAnimalWithId(int sid)
{
    for (int i = 0; i < numAnimals; i++)
    {
        if (animalCollection[i].getShelterID() == sid)
        {
            return &animalCollection[i];
        }
    }
    return NULL;
}

Animal* AnimalManager::getAnimalWithName(std::string n)
{
    for (int i = 0; i < numAnimals; i++)
    {
        if (animalCollection[i].getName().compare(n) == 0)
        {
            return &animalCollection[i];
        }
    }
    return NULL;
}

