#include "ACMController.h"

ACMController::ACMController(Animal **animals, Client **clients, float thresholdValue)
{
    numAnimals = sizeof(animals)/sizeof(Animal*);
    numClients = sizeof(clients)/sizeof(Client*);
    threshold = thresholdValue;

    //int maxCandidateSetSize = numAnimals * numClients;
    candidates = new CandidateSet(numAnimals * numClients);
    generateAndStoreSortedCandidates(animals, clients);
}

void ACMController::generateAndStoreSortedCandidates(Animal **animals, Client **clients)
{
    for (int i=0; i<numAnimals; i++)
    {
        for (int j=0; j<numClients; j++)
        {
            AnimalClientPair* pair = generateCandidate(animals[i], clients[j]);
            if (isAcceptable(pair))
            {
                candidates->add(pair);
            }
        }
    }

    sortCandidates();
}

AnimalClientPair *ACMController::generateCandidate(Animal *animal, Client *client)
{
    return new AnimalClientPair(animal, client);
    //candidates.add(candidate);

}

void ACMController::sortCandidates()
{
    candidates->sort();
}

bool ACMController::isAcceptable(AnimalClientPair *pair)
{
    return pair->getCompatibility() >= threshold;
}
/*
CandidateSet *ACMController::filterCandidates()
{
    int numUnfilteredCandidates = candidates.getSize();

    for (int i=0; i<numUnfilteredCandidates; i++)
    {
        Candidate *candidate = candidates.get(i);
        if (candidate.getCompatibility() < threshold)
        {
            candidates.remove(i);
        }
    }
}

CandidateSet *ACMController::getMatchSet()
{

}*/

CandidateSet *ACMController::run()
{
    // Temporary
    return candidates;
}
