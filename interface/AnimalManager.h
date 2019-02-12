#ifndef ANIMALMANAGER_H
#define ANIMALMANAGER_H

#include <iostream>

#include "Animal.h"


class AnimalManager
{
public:
    AnimalManager();
    AnimalManager(int animalCount);
    int addAnimal(int id, std::string n, int a, char sx, std::string sp, std::string b, int cL);
    void updateAnimalSocial(int index, int trLevel, int peopleLevel, int childLevel, int animalLevel, int approachLevel, int tiLevel);
    void updateAnimalHistory(int index, bool imm, std::string dietString, std::string mobilityString, std::string disabilityString, std::string bio, std::string aHist);
    void pushAnimalToDB(int index);
    int checkID(int id);
    inline Animal* getAnimalCollection(){return animalCollection;}
    inline int getNumAnimals(){return numAnimals;}

    void testFunc();
private:
    Animal *animalCollection;
    int numAnimals;
};

#endif // ANIMALMANAGER_H
