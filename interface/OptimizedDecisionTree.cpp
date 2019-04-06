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

OptimizedDecisionTree::OptimizedDecisionTree(int currentDepth/*, int intendedDepthIn*/)
{
    depth = currentDepth;
    //intendedDepth = intendedDepthIn;
    data = NULL;
}

CandidateSet *OptimizedDecisionTree::findOptimalPath(int intendedDepth)
{


    //std::cout << "OptimizedDecisionTree::findOptimalPath()" << std::endl;

    // Base Case
    if (data->isDone())
    {
        //std::cout << "findOptimalPath returning new, empty Candidate set" << std::endl;

        return new CandidateSet(depth);
    }

    //std::cout << "Depth: " << depth << std::endl;

    //Branch *optimalBranch = NULL;
    CandidateSet *optimalSubpathSolution = NULL;
    AnimalClientPair *decision = NULL;

    while(!data->isDone())
    {
        Branch *branch = data->next();

        /*
        if (depth == 1)
        {
            std::cout << "@Depth " << depth << ": " << branch->getDecision()->toString() << std::endl;
        }
        */

        //std::cout << "Branch size: " << nextBranch->getContext()->getSize() << std::endl;

        if (decision && isPrunable(branch, optimalSubpathSolution->getValue(), intendedDepth))
        {
            //std::cout << "\tDetermined to be prunable" << std::endl;
            continue;
        }

        OptimizedDecisionTree *child = new OptimizedDecisionTree(depth+1);
        DecisionTreeDataItem *childData = new DecisionTreeDataItem(branch->getContext());
        child->setData(childData);

        //std::cout << "Child data set" << std::endl;

        if (!optimalSubpathSolution)
        {
            //std::cout << "Checking first subpath: " << branch->getDecision()->toString() << std::endl;
            optimalSubpathSolution = child->findOptimalPath(intendedDepth);
            decision = branch->getDecision();
        }
        else
        {
            //std::cout << "Checking seconday subpath" << std::endl;
            CandidateSet *childResult = child->findOptimalPath(intendedDepth);
            //optimalSubpathSolution = maxDecision(childResult, optimalSubpathSolution);
            if (firstIsMaximal(childResult, optimalSubpathSolution))
            {
                /*
                if (depth == 1)
                {
                    std::cout << "\tOverwriting previous solution: " << decision->toString() << " with " << branch->getDecision()->toString() << std::endl;
                }*/
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


/*
    int numAnimalsTotal = set->getNumAnimals();
    int numClientsTotal = set->getNumClients();

    int numAnimalsAccountedFor = 0;
    int numClientsAccountedFor = 0;
*/
    for (int i=0; i < setSize; i++)
    {
        AnimalClientPair * pair = set->get(i);
        if (!bestCaseSet->containsAnimal(pair->getAnimal())
                || !bestCaseSet->containsClient(pair->getClient()))
        {
            bestCaseSet->add(pair);
        }
    }

   // std::cout << "bestCaseSet:\n" << bestCaseSet->toString() << std::endl;
    //std::cout << "target size check: " << ((targetSize == bestCaseSet->getSize()) ? "Pass" : "Fail") << std::endl;
    //std::cout << "      value check: " << ((bestCaseSet->getValue() > threshold) ? "Pass" : "Fail") << std::endl;

    return (targetSize != bestCaseSet->getSize() || bestCaseSet->getValue() <= threshold);
/*
    CandidateSet *animalSet = new CandidateSet(set->getSize());
    CandidateSet *clientSet = new CandidateSet(set->getSize());

    Animal **animals = set->getAllContainedAnimals();
    Client **clients = set->getAllContainedClients();

    size_t numAnimals = sizeof(animals) / sizeof(animals[0]);
    size_t numClients = sizeof(clients) / sizeof(clients[0]);

    for (int i = 0; i < numAnimals; i++)
    {
        AnimalClientPair *pair = set->getFirstPairContainingAnimal(animals[i]);
        animalSet->add(pair);
    }

    for (int i = 0; i < numClients; i++)
    {
        AnimalClientPair *pair = set->getFirstPairContainingClient(clients[i]);
        clientSet->add(pair);
    }
*/

}

/*
CandidateSet *OptimizedDecisionTree::maxDecision(CandidateSet *a, CandidateSet *b)
{
    //std::cout << "OptimizedDecisionTree::maxDecision()" << std::endl;

    if (!firstIsHigher(a, b))
    {
        return b;
    }
    return a;
}*/

