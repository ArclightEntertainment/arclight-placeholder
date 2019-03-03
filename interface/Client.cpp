#include "Client.h"

//default
Client::Client()
{

}

//Basic constructor
Client::Client(int id, std::string t, std::string fn, std::string ln, std::string pn)
{
  clientID = id;
  title = t;
  firstName = fn;
  lastName = ln;
  phoneNumber = pn;
  address = Address();
  profile = ClientProfile();
}

//copy constructor
Client::Client(const Client &a_client)
{

}

//populate address
void Client::populateAddress(std::string sl1, std::string sl2, std::string ct, std::string sub, std::string cn, std::string pc)
{
  address.setStreetLine1(sl1);
  address.setStreetLine2(sl2);
  address.setCity(ct);
  address.setCity(sub);
  address.setCountry(cn);
  address.setPostalCode(pc);
}

//populate profile
void Client::populateProfile(int a, bool hasUnderTwelve, int ownExp, int budget, int spaceSqFt, int timeAvail, FiveScale lOfMobility, FiveScale lOfEnergy, FiveScale lOfPatience, FiveScale prevExp, FiveScale physAffect)
{
  profile.setAge(a);
  profile.setHasChildrenUnderTwelve(hasUnderTwelve);
  profile.setLevelOfMobility(lOfMobility);
  profile.setLengthOfOwnershipExpectation(ownExp);
  profile.setBudgetPerMonth(budget);
  profile.setLivingSpaceSquareFeet(spaceSqFt);
  profile.setTimeAvailabilityPerDay(timeAvail);
  profile.setLevelOfEnergy(lOfEnergy);
  profile.setLevelOfPatience(lOfPatience);
  profile.setPreviousExperience(prevExp);
  profile.setPhysicalAffection(physAffect);
}
