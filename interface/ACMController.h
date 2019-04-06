#ifndef ACMCONTROLLER_H
#define ACMCONTROLLER_H

#include "AnimalClientPair.h"
#include "CandidateSet.h"
#include "EntityBuilder.h"

class ACMController
{
private:
    int numAnimals;
    int numClients;
    float threshold;
    CandidateSet *candidates;
    //ACMTreeController *decisionTree;

    void generateCandidates(Iterator<UAnimal *> *animalIterator, Iterator<UClient *> *clientIterator);
    AnimalClientPair *generateCandidate(UAnimal *animal, UClient *client);
    void sortCandidates();
    bool isAcceptable(AnimalClientPair *pair);

public:
    ACMController(float thresholdValue);
    CandidateSet* run();
    void setup(int numA, Iterator<UAnimal *> *animalIterator, int numC, Iterator<UClient *> *clientIterator);
    inline CandidateSet *getCandidateSet() { return candidates; }
};
#endif // ACMCONTROLLER_H
