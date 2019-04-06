#include "CandidateSet.h"
#include <algorithm>
#include <sstream>

CandidateSet::CandidateSet(int maxSize)
{
   size = 0;
   numClients = 0;
   numAnimals = 0;
   compatibilitySum = 0.0;
   candidates = new AnimalClientPair*[maxSize];
}

AnimalClientPair* CandidateSet::get(int index)
{
    return candidates[index];
}

int CandidateSet::find(AnimalClientPair *pair)
{
    int index = -1;

    for (int i=0; i<size; i++)
    {
        if (candidates[i] == pair)
        {
            index = i;
            break;
        }
    }
    return index;
}

AnimalClientPair* CandidateSet::remove(int index)
{
    AnimalClientPair* removed = get(index);
    for (int i=index; i<size-1; i++)
    {
        candidates[i] = candidates[i+1];
    }

    compatibilitySum -= removed->getCompatibility();
    size--;

    if (!containsAnimal(removed->getAnimal()))
    {
        numAnimals--;
    }

    if (!containsClient(removed->getClient()))
    {
        numClients--;
    }

    return removed;
}

void CandidateSet::add(AnimalClientPair *pair)
{
    if (!containsAnimal(pair->getAnimal()))
    {
        numAnimals++;
    }

    if (!containsClient(pair->getClient()))
    {
        numClients++;
    }

    candidates[size] = pair;
    compatibilitySum += pair->getCompatibility();
    size++;
}

float CandidateSet::getSetCompatibility()
{
    return compatibilitySum / size;
}

void CandidateSet::sort()
{
    std::sort(candidates, candidates + size,
              [](AnimalClientPair* a, AnimalClientPair* b)
    {
        return a->getCompatibility() > b->getCompatibility();
    });
}

bool CandidateSet::containsAnimal(UAnimal *animal)
{
    for (int i=0; i<size; i++)
    {
        if (candidates[i]->getAnimal() == animal)
        {
            return true;
        }
    }
    return false;
}

bool CandidateSet::containsClient(UClient *client)
{
    for (int i=0; i<size; i++)
    {
        if (candidates[i]->getClient() == client)
        {
            return true;
        }
    }
    return false;
}

std::string CandidateSet::toString()
{
    std::ostringstream stream;
    stream << size << " pairs:\n[";

    for (int i=0; i<size; i++)
    {
        stream << "\n" << candidates[i]->toString();
    }
    stream << "\n]\n";

    return stream.str();
}

CandidateSet *CandidateSet::disjointSubset(AnimalClientPair *exclusionaryPair)
{
    int index = find(exclusionaryPair);
    CandidateSet *disjointSubset = new CandidateSet(size-index);

    for (int i=index; i<size; i++)
    {
        if (candidates[i]->getAnimal() == exclusionaryPair->getAnimal()
                || candidates[i]->getClient() == exclusionaryPair->getClient())
        {
            continue;
        }

        disjointSubset->add(candidates[i]);
    }

    return disjointSubset;
}

float CandidateSet::getValue()
{
    return compatibilitySum / size;
}

int CandidateSet::getNumAnimals()
{
    CandidateSet* pairsWithUnique = new CandidateSet(size);

    for (int i=0; i<size; i++)
    {
        AnimalClientPair *pair = candidates[i];
        UAnimal *animal = pair->getAnimal();

        if (!pairsWithUnique->containsAnimal(animal))
        {
            pairsWithUnique->add(pair);
        }
    }

    return pairsWithUnique->getSize();
}

int CandidateSet::getNumClients()
{
    CandidateSet* pairsWithUnique = new CandidateSet(size);

    for (int i=0; i<size; i++)
    {
        AnimalClientPair *pair = candidates[i];
        UClient *client = pair->getClient();

        if (!pairsWithUnique->containsClient(client))
        {
            pairsWithUnique->add(pair);
        }
    }

    return pairsWithUnique->getSize();
}
