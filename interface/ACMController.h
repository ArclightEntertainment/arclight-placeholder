#ifndef ACMCONTROLLER_H
#define ACMCONTROLLER_H

#include "AnimalClientPair.h"
#include "CandidateSet.h"
#include "Animal.h"
#include "Client.h"

class ACMController
{
private:
    float threshold;
    int numAnimals;
    int numClients;
    CandidateSet candidates;

    CandidateSet *generateAndStoreSortedCandidates(Animal **animals, Client **clients) = 0;
    CandidateSet *generateCandidate(ANimal *animal, Client *client) = 0;
    CandidateSet *sortCandidates() = 0;
    bool isAcceptable(AnimalClientPair *pair);
    //CandidateSet *filterCandidates() = 0;
    //CandidateSet *getMatchSet() = 0;

public:
    ACMController(Animal **animals, Client **clients, float thresholdValue) = 0;
    CandidateSet* run() = 0;
};
#endif // ACMCONTROLLER_H
