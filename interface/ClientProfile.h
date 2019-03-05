#ifndef CLIENTPROFILE_H
#define CLIENTPROFILE_H

#include "Levels.h"

//------------------------------------------
//------------------------------------------
//-----------Client Profile Class-----------
//------------------------------------------
//------------------------------------------
class ClientProfile
{
private:
  int age;
  bool hasChildrenUnderTwelve;
  int lengthOfOwnershipExpectation;
  int budgetPerMonth;
  int timeAvailabilityPerDay;
  bool hasPets;
  FiveScale levelOfMobility;
  FiveScale levelOfEnergy;
  FiveScale levelOfPatience;
  FiveScale previousExperience;
  FiveScale physicalAffection;

public:
// Constructor
  ClientProfile();
  ClientProfile(int a, bool hasUnderTwelve, bool hasPet, int ownExp, int budget, int timeAvail, FiveScale lOfMobility, FiveScale lOfEnergy, FiveScale lOfPatience, FiveScale prevExp, FiveScale physAffect);

//Operator Overloads
  ClientProfile(const ClientProfile& a_profile);

// Getters
  inline int getAge()                           const {return age;}
  inline bool getHasChildrenUnderTwelve()       const {return hasChildrenUnderTwelve;}
  inline bool getHasPets()                      const {return hasPets;}
  inline int getLengthOfOwnershipExpectation()  const {return lengthOfOwnershipExpectation;}
  inline int getBudgetPerMonth()                const {return budgetPerMonth;}
  inline int getTimeAvailabilityPerDay()        const {return timeAvailabilityPerDay;}
  inline FiveScale getLevelOfMobility()         const {return levelOfMobility;}
  inline FiveScale getLevelOfEnergy()           const {return levelOfEnergy;}
  inline FiveScale getLevelOfPatience()         const {return levelOfPatience;}
  inline FiveScale getPreviousExperience()      const {return previousExperience;}
  inline FiveScale getPhysicalAffection()       const {return physicalAffection;}

// Setters
  inline void setAge(int a)                                  {age = a;}
  inline void setHasChildrenUnderTwelve(bool hasUnderTwelve) {hasChildrenUnderTwelve = hasUnderTwelve;}
  inline void setHasPets(bool hasPet)                        {hasPets = hasPet;}
  inline void setLengthOfOwnershipExpectation(int ownExp)    {lengthOfOwnershipExpectation = ownExp;}
  inline void setBudgetPerMonth(int budget)                  {budgetPerMonth = budget;}
  inline void setTimeAvailabilityPerDay(int timeAvail)       {timeAvailabilityPerDay = timeAvail;}
  inline void setLevelOfMobility(FiveScale lOfMobility)      {levelOfMobility = lOfMobility;}
  inline void setLevelOfEnergy(FiveScale lOfEnergy)          {levelOfEnergy = lOfEnergy;}
  inline void setLevelOfPatience(FiveScale lOfPatience)      {levelOfPatience = lOfPatience;}
  inline void setPreviousExperience(FiveScale prevEx)        {previousExperience = prevEx;}
  inline void setPhysicalAffection(FiveScale physAffect)     {physicalAffection = physAffect;}
};
#endif // CLIENTPROFILE_H
