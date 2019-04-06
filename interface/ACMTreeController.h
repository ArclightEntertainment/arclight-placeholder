#ifndef ACMTREECONTROLLER_H
#define ACMTREECONTROLLER_H

#include "OptimizedDecisionTree.h"
#include "CandidateSet.h"

class ACMTreeController
{
private:
    OptimizedDecisionTree *root;
    int intendedDepth;

public:
    ACMTreeController(CandidateSet *treeData);
    CandidateSet *makeDecision();
};
#endif // ACMTREECONTROLLER_H
