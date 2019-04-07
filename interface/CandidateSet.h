#ifndef CANDIDATESET_H
#define CANDIDATESET_H

#include "AnimalClientPair.h"
#include "EntityBuilder.h"
#include <string>

class CandidateSet
{
private:
    int size;
    int numAnimals;
    int numClients;

    float compatibilitySum;

    AnimalClientPair **candidates;

    float getSetCompatibility();

public:
    CandidateSet(int maxSize);

    void add(AnimalClientPair *pair);
    AnimalClientPair *get(int index);
    AnimalClientPair *remove(int index);

    inline int getSize() { return size; }
    inline bool isEmpty() { return size == 0; }
    float getValue();

    void sort();

    int find(AnimalClientPair *pair);
    bool containsAnimal(UAnimal *animal);
    bool containsClient(UClient *client);
    int getNumAnimals();
    int getNumClients();

    std::string toString();

    CandidateSet *disjointSubset(AnimalClientPair *exclusionaryPair);
};
#endif // CANDIDATESET_H
