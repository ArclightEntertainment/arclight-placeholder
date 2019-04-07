#include "OptimizedDecisionTree.h"

OptimizedDecisionTree::OptimizedDecisionTree(int currentDepth)
{
    depth = currentDepth;
    data = NULL;
}

CandidateSet *OptimizedDecisionTree::findOptimalPath(int intendedDepth)
{
    // Base Case
    if (data->isDone())
    {
        return new CandidateSet(depth);
    }

    CandidateSet *optimalSubpathSolution = NULL;
    AnimalClientPair *decision = NULL;

    while(!data->isDone())
    {
        Branch *branch = data->next();

        if (decision && isPrunable(branch, optimalSubpathSolution->getValue(), intendedDepth))
        {
            continue;
        }

        OptimizedDecisionTree *child = new OptimizedDecisionTree(depth+1);
        DecisionTreeDataItem *childData = new DecisionTreeDataItem(branch->getContext());
        child->setData(childData);

        if (!optimalSubpathSolution)
        {
            optimalSubpathSolution = child->findOptimalPath(intendedDepth);
            decision = branch->getDecision();
        }
        else
        {
            CandidateSet *childResult = child->findOptimalPath(intendedDepth);

            if (firstIsMaximal(childResult, optimalSubpathSolution))
            {
                optimalSubpathSolution = childResult;
                decision = branch->getDecision();
            }
        }
    }

    if (decision && optimalSubpathSolution)
    {
        optimalSubpathSolution->add(decision);
    }

    return optimalSubpathSolution;
}

bool OptimizedDecisionTree::firstIsMaximal(CandidateSet *a, CandidateSet *b)
{
    return (!b || a->getValue() > b->getValue());
}

bool OptimizedDecisionTree::isPrunable(Branch *branch, float threshold, int intendedDepth)
{
    int targetSize = intendedDepth - depth;

    CandidateSet *set = branch->getContext();
    int setSize = set->getSize();

    CandidateSet *bestCaseSet = new CandidateSet(setSize);

    for (int i=0; i < setSize; i++)
    {
        AnimalClientPair * pair = set->get(i);
        if (!bestCaseSet->containsAnimal(pair->getAnimal())
                || !bestCaseSet->containsClient(pair->getClient()))
        {
            bestCaseSet->add(pair);
        }
    }

    return (targetSize != bestCaseSet->getSize() || bestCaseSet->getValue() <= threshold);
}
