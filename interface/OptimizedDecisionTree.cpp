#include "OptimizedDecisionTree.h"
/*
OptimizedDecisionTree::OptimizedDecisionTree()
{

}
/*
OptimizedDecisionTree::OptimizedDecisionTree(Branch *branch)
{

}
*/

OptimizedDecisionTree::OptimizedDecisionTree(int depthIn)
{
    depth = depthIn;
    data = NULL;
}

CandidateSet *OptimizedDecisionTree::findOptimalPath()
{
    // Base Case
    if (data->isDone())
    {
        return new CandidateSet(depth);
    }

    //Branch *optimalBranch = NULL;
    CandidateSet *decision = NULL;

    while(!data->isDone())
    {
        Branch *nextBranch = data->next();

        if (nextBranch->isPrunable())
        {
            continue;
        }

        OptimizedDecisionTree *child = new OptimizedDecisionTree(depth+1);
        DecisionTreeDataItem *childData = new DecisionTreeDataItem(nextBranch->getContext());
        child->setData(childData);

        if (!decision)
        {
            decision = child->findOptimalPath();
        }
        else
        {
            decision = maxDecision(child->findOptimalPath(), decision);
        }
    }

    return decision;
}

CandidateSet *OptimizedDecisionTree::maxDecision(CandidateSet *a, CandidateSet *b)
{
    if (a->getSetCompatibility() < b->getSetCompatibility())
    {
        return b;
    }
    return a;
}

