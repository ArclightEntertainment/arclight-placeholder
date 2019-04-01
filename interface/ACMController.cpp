#include "ACMController.h"

ACMController::ACMController(float thresholdValue)
{
    numAnimals = 0;
    numClients = 0;
    threshold = thresholdValue;
}

void ACMController::generateCandidates(Iterator<UAnimal *> *animalIterator, Iterator<UClient *> *clientIterator)
{
    UAnimal *animals[numAnimals];
    UClient *clients[numClients];

    candidates = new CandidateSet(numAnimals * numClients);

    int i, j;

    i = -1;
    while (!animalIterator->isDone())
    {
        animals[++i] = animalIterator->currentItem();
        animalIterator->next();
    }

    j = -1;
    while (!clientIterator->isDone())
    {
        clients[++j] = clientIterator->currentItem();
        clientIterator->next();
    }

    for (int i=0; i<numAnimals; i++)
    {
        for (int j=0; j<numClients; j++)
        {
            candidates->add(generateCandidate(animals[i], clients[j]));
        }
    }
}

AnimalClientPair *ACMController::generateCandidate(UAnimal *animal, UClient *client)
{
    return new AnimalClientPair(animal, client);
}

void ACMController::sortCandidates()
{
    candidates->sort();
}

void ACMController::setup(int numA, Iterator<UAnimal *> *animalIterator, int numC, Iterator<UClient *> *clientIterator)
{
    numAnimals = numA;
    numClients = numC;

    generateCandidates(animalIterator, clientIterator);
    sortCandidates();
}

bool ACMController::isAcceptable(AnimalClientPair *pair)
{
    return pair->getCompatibility() >= threshold;
}

CandidateSet *ACMController::run()
{
    // Temporary

    //decisionTree = ACMTreeController(candidates);

    //Temporary
    return candidates;

}
