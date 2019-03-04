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
    void updateAnimalSocial(int index, int trLevel, int taLevel, int peopleLevel, int childLevel, int animalLevel, int approachLevel, int tiLevel);
    void updateAnimalHistory(int index, bool imm, std::string dietString, std::string mobilityString, std::string disabilityString, std::string bio, std::string aHist);
    void pushAnimalToDB(int index);
    int checkID(int id);
    int getNextID();
    Animal* getAnimalWithId(int sid);
    Animal* getAnimalWithName(std::string n);
    inline Animal* getAnimalCollection(){return animalCollection;}
    inline int getNumAnimals(){return numAnimals;}
    inline void setArr(Animal *arr, int numAn){animalCollection = arr; numAnimals = numAn; maxNumAnimals = numAn; resize();setNextShelterID();}
    void resize();
    inline void printAll(){for (int i = 0; i < numAnimals; i++){std::cout<<animalCollection[i].getName() << " " << animalCollection[i].getShelterID() << std::endl;}}
private:
    Animal *animalCollection;
    int numAnimals;
    int maxNumAnimals;

    int nextShelterID;
    inline void setNextShelterID(){for (int i = 0; i < numAnimals; i++){if (animalCollection[i].getShelterID() > nextShelterID){nextShelterID = animalCollection[i].getShelterID();}}}
};

#endif // ANIMALMANAGER_H
