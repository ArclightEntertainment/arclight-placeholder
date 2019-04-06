#include "DecisionTreeDataItem.h"

Branch::Branch(AnimalClientPair *decisionIn, CandidateSet *resultantContext)
{
    decision = decisionIn;
    context = resultantContext;
    value = decision->getCompatibility();
}

AnimalClientPair *Branch::getDecision()
{
    return decision;
}

CandidateSet *Branch::getContext()
{
    return context;
}

float Branch::getValue()
{
    return value;
}

bool Branch::isPrunable()
{
    // Temporary
    return false;
}
/*
Branch::getValue()
{
    //return context->getSetCompatibility();
}*/

DecisionTreeDataItem::DecisionTreeDataItem(/*CandidateSet *&resultantDataIn, */CandidateSet *dataSetIn)
{
   // resultantData = new CandidateSet(resultantDataIn)
    //dataItem = dataQueue->peek();
    //dataQueue = new CandidateSet(dataQueueIn->filterOut(dataItem));
    dataSet = dataSetIn;
    //depth = depthIn;
    //isDone = dataSet->getSize();
    currentIndex = 0;
    //checkDone();

    //current = NULL;
    //currentIndex = 0;
    //next();
}
/*
DecisionTreeDataItem::DecisionTreeDataItem(CandidateSet)
{
    resultantData = new CandidateSet();
    dataQueue = new CandidateSet(toCopy.getDataSet());
    //data
    isDone = false;
    //current = NULL;
    currentIndex = 0;
    next();
}*/

Branch *DecisionTreeDataItem::next()
{
    //std::cout << "DecisionTreeDataItem::next()" << std::endl;

    if (isDone())
    {
        //std::cout << "next() returning null" << std::endl;
        return NULL;
    }

    AnimalClientPair *nextDataItem = dataSet->get(currentIndex);
    std::cout << "Next data item: " << nextDataItem->toString() << std::endl;

    CandidateSet *nextSet = dataSet->disjointSubset(nextDataItem);
   // CandidateSet *nextSet = dataSet->getSubsetWithout(nextDataItem);
   // std::cout << "past disjoin subset" << std::endl;

    Branch *branch = new Branch(nextDataItem, nextSet);
    //DecisionTreeDataItem *next = dataQueue
    //AnimalClientPair *choice = data->get(currentIndex);
    //CandidateSet *subset = dataSet->subset(currentIndex, )
    //dataQueue->getIndexOfFirstPairExcluding()
    currentIndex++;
    //checkDone();
    return branch;
}

bool DecisionTreeDataItem::isDone()
{
    return currentIndex >= dataSet->getSize();
}
/*
CandidateSet *DecisionTreeDataItem::getCurrentItem()
{
    return current;
}*/





