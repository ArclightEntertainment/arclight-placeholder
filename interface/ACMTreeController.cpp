#include "ACMTreeController.h"
#include "DecisionTreeDataItem.h"

ACMTreeController::ACMTreeController(CandidateSet *treeData)
{
    int numAnimals = treeData->getNumAnimals();
    int numClients = treeData->getNumClients();

    intendedDepth = (numAnimals > numClients) ? numAnimals : numClients;

    DecisionTreeDataItem *rootData = new DecisionTreeDataItem(treeData);
    root = new OptimizedDecisionTree(1);
    root->setData(rootData);
}

CandidateSet *ACMTreeController::makeDecision()
{
    return root->findOptimalPath(intendedDepth);
}
