#include "ACMTreeController.h"
#include "DecisionTreeDataItem.h"

ACMTreeController::ACMTreeController(CandidateSet *treeData)
{
    DecisionTreeDataItem *rootData = new DecisionTreeDataItem(treeData);
    root = new OptimizedDecisionTree(0);
    root->setData(rootData);
}

CandidateSet *ACMTreeController::makeDecision()
{
    //std::cout << "ACMTreeController::makeDecision()" << std::endl;
    return root->findOptimalPath();
}
