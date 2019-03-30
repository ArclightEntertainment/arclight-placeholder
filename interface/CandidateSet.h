#ifndef CANDIDATESET_H
#define CANDIDATESET_H

#include "AnimalClientPair.h"
#include "Animal.h"
#include "Client.h"

using Candidate = AnimalClientPair;

class CandidateSet
{
private:
    float compatibilitySum;
    //float setCompatibility;
    int size;
    Candidate **candidates;

public:
    CandidateSet(int maxSize) = 0;
    float getSetCompatibility() = 0;
    void add(Candidate *pair) = 0;
    Candidate *get(int index) = 0;
    Candidate *remove(int index) = 0;
    void sort() = 0;
    bool containsAnimal(Animal *animal) = 0;
    bool containsClient(Client *client) = 0;
    //int getSize() = 0;
    //bool isPrunable() = 0;
    //bool isEmpty() = 0;
    //int compare(CandidateSet *other) = 0;
    //CandidateSet *next();
    //CandidateSet(CandidateSet *other);
};
#endif // CANDIDATESET_H
