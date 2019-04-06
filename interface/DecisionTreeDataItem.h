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
    //bool isPrunable();
};

class DecisionTreeDataItem
{
private:
    //CandidateSet resultantData;
    //AnimalClientPair *dataItem;
    CandidateSet *dataSet;
    //AnimalClientPair *currentItem;
    //CandidateSet *currentDataSubset;

    int currentIndex;
    //bool isDone;
    void checkDone();

public:
    DecisionTreeDataItem(CandidateSet *dataSetIn);
    //DecisionTreeDataItem(DecisionTreeDataItem &toCopy);
    Branch *next();
    //int compare();
    bool isDone();
    //getValue();
    CandidateSet *getCurrentItem();

};
#endif // DECISIONTREEDATAITEM_H
