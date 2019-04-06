#include "ACMTreeController.h"
#include "DecisionTreeDataItem.h"
#include <iostream>

ACMTreeController::ACMTreeController(CandidateSet *treeData)
{
    int numAnimals = treeData->getNumAnimals();
    int numClients = treeData->getNumClients();

    //std::cout << "Num Animals: " << numAnimals <<  " Num Clients: " << numClients << std::endl;
    intendedDepth = (numAnimals > numClients) ? numAnimals : numClients;

    DecisionTreeDataItem *rootData = new DecisionTreeDataItem(treeData);
    root = new OptimizedDecisionTree(1);
    root->setData(rootData);
}

CandidateSet *ACMTreeController::makeDecision()
{
    //std::cout << "ACMTreeController::makeDecision()" << std::endl;
    return root->findOptimalPath(intendedDepth);
}
