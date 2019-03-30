#ifndef CANDIDATESET_H
#define CANDIDATESET_H

#include "AnimalClientPair.h"
#include "Animal.h"
#include "Client.h"

//using Candidate = AnimalClientPair;

class CandidateSet
{
private:
    //float setCompatibility;
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
    bool containsAnimal(Animal *animal);
    bool containsClient(Client *client);
    //int getSize();
    //bool isPrunable();
    //bool isEmpty();
    //int compare(CandidateSet *other);
    //CandidateSet *next();
    //CandidateSet(CandidateSet *other);
};
#endif // CANDIDATESET_H
