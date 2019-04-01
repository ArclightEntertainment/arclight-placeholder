#ifndef OPTIMIZEDDECISIONTREE_H
#define OPTIMIZEDDECISIONTREE_H

#include "CandidateSet.h"
#include "DecisionTreeDataItem.h"


class OptimizedDecisionTree
{
private:
    int depth;
    OptimizedDecisionTree *optimalSubtree;
    DecisionTreeDataItem *data;
    CandidateSet *maxDecision(CandidateSet *a, CandidateSet *b);
    //DecisionTreeDataItem *explore(DecisionTreeDataItem * branch);
    //DecisionTreeDataItem *next();

public:
    OptimizedDecisionTree(int depthIn);
    inline void setData(DecisionTreeDataItem *dataIn) { data = dataIn; }
    CandidateSet *findOptimalPath();
    //OptimizedDecisionTree(CandidateSet *pathToNode);
    //DecisionTreeDataItem *evaluate();
};
#endif // OPTIMIZEDDECISIONTREE_H
