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
    bool firstIsMaximal(CandidateSet *a, CandidateSet *b);
    bool isPrunable(Branch *branch, float threshold, int intendedDepth);
    //CandidateSet *maxDecision(CandidateSet *a, CandidateSet *b);
    //DecisionTreeDataItem *explore(DecisionTreeDataItem * branch);
    //DecisionTreeDataItem *next();

public:
    OptimizedDecisionTree(int currentDepth);
    inline void setData(DecisionTreeDataItem *dataIn) { data = dataIn; }
    CandidateSet *findOptimalPath(int intendedDepth);
    //OptimizedDecisionTree(CandidateSet *pathToNode);
    //DecisionTreeDataItem *evaluate();
};
#endif // OPTIMIZEDDECISIONTREE_H
