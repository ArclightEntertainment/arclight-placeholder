#include "ClientProfile.h"

ClientProfile::ClientProfile()
{

}

ClientProfile::ClientProfile(int a, bool hasUnderTwelve, int ownExp, int budget, int timeAvail, FiveScale lOfMobility, FiveScale lOfEnergy, FiveScale lOfPatience, FiveScale prevExp, FiveScale physAffect)
{
  age = a;
  hasChildrenUnderTwelve = hasUnderTwelve;
  lengthOfOwnershipExpectation = ownExp;
  budgetPerMonth = budget;
  timeAvailabilityPerDay = timeAvail;
  levelOfMobility = lOfMobility;
  levelOfEnergy = lOfEnergy;
  levelOfPatience = lOfPatience;
  previousExperience = prevExp;
  physicalAffection = physAffect;
}

ClientProfile::ClientProfile(const ClientProfile& a_profile)
{

}
