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
  FiveScale levelOfMobility;
  int lengthOfOwnershipExpectation;
  int budgetPerMonth;
  int livingSpaceSquareFeet;
  float timeAvailabilityPerDay;
  FiveScale levelOfEnergy;
  FiveScale goodWithAnimals;

public:
// Constructor
  ClientProfile();
  ClientProfile(int a, int lOfMobility, int ownExp, int budget, int space, float timeAvail, int lOfEnergy, int goodWithAnis);

//Operator Overloads
  ClientProfile(const ClientProfile& a_profile);

// Getters
  inline int getAge()                           const {return age;}
  inline FiveScale getLevelOfMobility()         const {return levelOfMobility;}
  inline int getLengthOfOwnershipExpectation()  const {return lengthOfOwnershipExpectation;}
  inline int getBudgetPerMonth()                const {return budgetPerMonth;}
  inline int getLivingSpaceSquareFeet()         const {return livingSpaceSquareFeet;}
  inline int getTimeAvailabilityPerDay()        const {return timeAvailabilityPerDay;}
  inline FiveScale getLevelOfEnergy()           const {return levelOfEnergy;}
  inline FiveScale getGoodWithAnimals()         const {return goodWithAnimals;}

// Setters
  inline void setAge(int a)                               {age = a;}
  inline void setLevelOfMobility(int lOfMobility)         {levelOfMobility = toFiveScale(lOfMobility);}
  inline void setLengthOfOwnershipExpectation(int ownExp) {lengthOfOwnershipExpectation = ownExp;}
  inline void setBudgetPerMonth(int budget)               {budgetPerMonth = budget;}
  inline void setLivingSpaceSquareFeet(int space)         {livingSpaceSquareFeet = space;}
  inline void setTimeAvailabilityPerDay(float timeAvail)  {timeAvailabilityPerDay = timeAvail;}
  inline void setLevelOfEnergy(int lOfEnergy)             {levelOfEnergy = toFiveScale(lOfEnergy);}
  inline void setGoodWithAnimals(int goodWithAnis)        {goodWithAnimals = toFiveScale(goodWithAnis);}
};
#endif // CLIENTPROFILE_H
