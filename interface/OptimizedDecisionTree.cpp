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
    std::cout << "Depth: " << depth << std::endl;

    //std::cout << "OptimizedDecisionTree::findOptimalPath()" << std::endl;

    // Base Case
    if (data->isDone())
    {
        //std::cout << "findOptimalPath returning new, empty Candidate set" << std::endl;

        return new CandidateSet(depth);
    }

    //Branch *optimalBranch = NULL;
    CandidateSet *decision = NULL;

    while(!data->isDone())
    {
        Branch *nextBranch = data->next();

        //std::cout << "Branch size: " << nextBranch->getContext()->getSize() << std::endl;

        if (nextBranch->isPrunable())
        {
            continue;
        }

        OptimizedDecisionTree *child = new OptimizedDecisionTree(depth+1);
        DecisionTreeDataItem *childData = new DecisionTreeDataItem(nextBranch->getContext());
        child->setData(childData);

        //std::cout << "Child data set" << std::endl;

        if (!decision)
        {
            decision = child->findOptimalPath();
        }
        else
        {
            CandidateSet *childResult = child->findOptimalPath();
            if (childResult)
            {
                decision = maxDecision(childResult, decision);
            }
        }
    }
    return decision;
}

CandidateSet *OptimizedDecisionTree::maxDecision(CandidateSet *a, CandidateSet *b)
{
    //std::cout << "OptimizedDecisionTree::maxDecision()" << std::endl;

    if (a->getSetCompatibility() < b->getSetCompatibility())
    {
        return b;
    }
    return a;
}

