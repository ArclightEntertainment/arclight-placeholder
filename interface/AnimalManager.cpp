#include "AnimalManager.h"
#include "./data/DatabaseInterface.h"

//Default Constructor
AnimalManager::AnimalManager()
{
    animalCollection = new Animal[30];
}

//Can instantiate with a specific count
AnimalManager::AnimalManager(int i)
{
    animalCollection = new Animal[i];
}

//Creates a new animal with basic information, returns it's index in the array.
int AnimalManager::addAnimal(int id, std::string n, int a, char sx, std::string sp, std::string b, int cL)
{
    animalCollection[numAnimals++] = *new Animal(id, n, a, sx, sp, b, cL);
    resize();
    return numAnimals-1;
}

//Takes in an index and some information, populates those values in the animal at index
void AnimalManager::updateAnimalSocial(int index, int trLevel, int peopleLevel, int childLevel, int animalLevel, int approachLevel, int tiLevel)
{
    animalCollection[index].populateSocial(trLevel, peopleLevel, childLevel, animalLevel, approachLevel, tiLevel);
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
        //std::cout<<"Doubled!"<<std::endl;
    }
}

//used for testing only. Input desired code segments to run here
void AnimalManager::testFunc()
{
    Animal a = Animal(0, "Jake", 1, 'M', "Cat", "", 1);
    Animal b = Animal(a);
    //std::cout<<a.getName() << " " << a.getAge() << " " << a.getSpecies() << std::endl;
    //std::cout<<b.getName() << " " << b.getAge() << " " << b.getSpecies() << std::endl;
}
