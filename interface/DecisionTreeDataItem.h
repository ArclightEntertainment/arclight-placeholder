#ifndef DECISIONTREEDATAITEM_H
#define DECISIONTREEDATAITEM_H

#include "CandidateSet.h"


class Branch
{
private:
    AnimalClientPair *decision;
    CandidateSet *context;
    float value;

public:
    Branch(AnimalClientPair *decisionIn, CandidateSet *context);
    AnimalClientPair *getDecision();
    CandidateSet *getContext();
    float getValue();
};

class DecisionTreeDataItem
{
private:
    CandidateSet *dataSet;
    int currentIndex;
    void checkDone();

public:
    DecisionTreeDataItem(CandidateSet *dataSetIn);
    CandidateSet *getCurrentItem();
    Branch *next();
    bool isDone();
};
#endif // DECISIONTREEDATAITEM_H
