#include "CandidateSet.h"
#include <algorithm>

CandidateSet::CandidateSet(int maxSize)
{
   size = 0;
   compatibilitySum = 0.0;
   candidates = new AnimalClientPair*[maxSize];
}

AnimalClientPair* CandidateSet::get(int index)
{
    return candidates[index];
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

    return removed;
}

void CandidateSet::add(AnimalClientPair *pair)
{
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

bool CandidateSet::containsAnimal(Animal *animal)
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

bool CandidateSet::containsClient(Client *client)
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
