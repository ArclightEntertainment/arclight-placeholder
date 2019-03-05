#include "ClientProfile.h"

ClientProfile::ClientProfile()
{

}

ClientProfile::ClientProfile(int a, bool hasUnderTwelve, bool hasPet, int ownExp, int budget, int timeAvail, FiveScale lOfMobility, FiveScale lOfPatience, FiveScale prevExp, FiveScale physAffect)
{
  age = a;
  hasChildrenUnderTwelve = hasUnderTwelve;
  hasPets = hasPet;
  lengthOfOwnershipExpectation = ownExp;
  budgetPerMonth = budget;
  timeAvailabilityPerDay = timeAvail;
  levelOfMobility = lOfMobility;
  levelOfPatience = lOfPatience;
  previousExperience = prevExp;
  physicalAffection = physAffect;
}

ClientProfile::ClientProfile(const ClientProfile& a_profile)
{

}
