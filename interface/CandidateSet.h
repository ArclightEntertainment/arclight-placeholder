#ifndef CANDIDATESET_H
#define CANDIDATESET_H

#include "AnimalClientPair.h"
#include "EntityBuilder.h"
#include <string>

class CandidateSet
{
private:
    int size;
    float compatibilitySum;
    AnimalClientPair **candidates;

public:
    CandidateSet(int maxSize);
    float getSetCompatibility();
    void add(AnimalClientPair *pair);
    AnimalClientPair *get(int index);
    AnimalClientPair *remove(int index);
    void sort();
    bool containsAnimal(UAnimal *animal);
    bool containsClient(UClient *client);
    std::string toString();
    inline int getSize() { return size; }
    inline bool isEmpty() { return size == 0; }
    CandidateSet *disjointSubset(AnimalClientPair *exclusionaryPair);
};
#endif // CANDIDATESET_H
