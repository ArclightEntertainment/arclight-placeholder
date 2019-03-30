#include "CandidateSet.h"

CandidateSet::CandidateSet(int maxSize)
{
   candidates = new Candidate*[maxSize];
   size = 0;
   setCompatibility = 0;
}

Candidate* CandidateSet::get(int index)
{
    return candidates[i];
}

Candidate* CandidateSet::remove(int index)
{
    Candidate* removed = get(index);
    for (int i=index; i<size-1; i++)
    {
        candidates[i] = candidates[i+1];
    }

    compatibilitySum -= removed->getCompatibility();
    size--;

    return removed;
}

void CandidateSet::add(Candidate *pair)
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
              [](Candidate* a, Candidate* b)
    {
        return a->getCompatibility() > b->getCompatibility();
    };
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
