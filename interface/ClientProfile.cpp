#include "ClientProfile.h"

ClientProfile::ClientProfile()
{

}

ClientProfile::ClientProfile(int a, int lOfMobility, int ownExp, int budget, int space, int timeAvail, int lOfEnergy, int goodWithAnis)
{
  age = a;
  levelOfMobility = toFiveScale(lOfMobility);
  lengthOfOwnershipExpectation = ownExp;
  budgetPerMonth = budget;
  livingSpaceSquareFeet = space;
  timeAvailabilityPerDay = timeAvail;
  levelOfEnergy = toFiveScale(lOfEnergy);
  goodWithAnimals = toFiveScale(goodWithAnis);
}

ClientProfile::ClientProfile(const ClientProfile& a_profile)
{

}
