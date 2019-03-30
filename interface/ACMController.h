#ifndef ACMCONTROLLER_H
#define ACMCONTROLLER_H

#include "AnimalClientPair.h"
#include "CandidateSet.h"
#include "Animal.h"
#include "Client.h"

class ACMController
{
private:
    int numAnimals;
    int numClients;
    float threshold;
    CandidateSet * candidates;

    void generateAndStoreSortedCandidates(Animal **animals, Client **clients);
    AnimalClientPair *generateCandidate(Animal *animal, Client *client);
    void sortCandidates();
    bool isAcceptable(AnimalClientPair *pair);
    //CandidateSet *filterCandidates();
    //CandidateSet *getMatchSet();

public:
    ACMController(Animal **animals, Client **clients, float thresholdValue);
    CandidateSet* run();
};
#endif // ACMCONTROLLER_H
